/*! \file main.c
 *
 * This application generates the physical device information and
 * output the information in YAML data to stdout.
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include <shr/shr_pb.h>

#include <bcmdrd/bcmdrd_dev.h>
#include <bcmdrd/bcmdrd_pt.h>
#include <bcmdrd/bcmdrd_pt_ser.h>
#include <bcmdrd/bcmdrd_enum_map.h>

#include "version.h"

/*******************************************************************************
 * Local definitions
 */

/* User data in DRD symbol iteration callback function */
typedef struct sym_data_s {
    int unit;
    FILE *fh;
} sym_data_t;

#define IFMT "%*s"
#define ISTR(_i) _i, ""

/* Indentation width of the output file */
#define INDENT_STEP 4

/*******************************************************************************
 * Local variables
 */

/* Create device table */
#define BCMDRD_DEVLIST_ENTRY(_nm,_vn,_dv,_rv,_md,_pi,_bd,_bc,_fn,_cn,_pf,_pd,_r0,_r1) \
    { _vn, _dv, _rv, _md, #_bd, #_fn },
#define BCMDRD_DEVLIST_INCLUDE_ALL
static struct {
    uint16_t vendor_id;
    uint16_t device_id;
    uint16_t revision;
    uint16_t model;
    const char *drv_name;
    const char *full_name;
} dev_table[] = {
#include <bcmdrd/bcmdrd_devlist.h>
    { 0, 0 } /* end-of-list */
};

/*******************************************************************************
 * Private functions
 */

static int
dev_init(int unit, const char *name, const char **dev_name)
{
    int idx = 0;
    bcmdrd_dev_id_t id;

    if (name == NULL) {
        return -1;
    }

    /* Look for matching name in device table */
    for (idx = 0; idx < COUNTOF(dev_table); idx++) {
        if (dev_table[idx].full_name == NULL) {
            /* End of table */
            return -1;
        }
        if (strncasecmp(dev_table[idx].full_name, name, strlen(name)) == 0) {
            /* Found matching device */
            break;
        }
    }

    /* Set up ID structure */
    memset(&id, 0, sizeof(id));
    id.vendor_id = dev_table[idx].vendor_id;
    id.device_id = dev_table[idx].device_id;
    id.revision = dev_table[idx].revision;
    id.model = dev_table[idx].model;

    /* Set up base device name */
    *dev_name = dev_table[idx].full_name;

    /* Create the target device from DRD */
    if (bcmdrd_dev_create(unit, &id) < 0) {
        return -1;
    }

    return 0;
}

static int
dev_cleanup(int unit)
{
    bcmdrd_dev_destroy(unit);

    return 0;
}

static int
print_header(FILE *fh)
{
    fprintf(fh, "#\n");
    fprintf(fh, "# DO NOT EDIT THIS FILE!\n");
    fprintf(fh, "# This file is auto-generated from the registers file.\n");
    fprintf(fh, "# Edits to this file will be lost when it is regenerated.\n");
    fprintf(fh, "#\n");
    fprintf(fh, "# Copyright: (c) %s", version_year());
    fprintf(fh, " Broadcom. All Rights Reserved. \"Broadcom\" refers to\n");
    fprintf(fh, "# Broadcom Limited and/or its subsidiaries.\n");
    fprintf(fh, "#\n");

    return 0;
}

static int
print_symbol(const bcmdrd_symbol_t *s, bcmdrd_sid_t sid, void *vptr)
{
    sym_data_t *sym_data = (sym_data_t *)vptr;
    int unit = sym_data->unit;
    FILE *fh = sym_data->fh;
    const bcmdrd_chip_info_t *cinfo = bcmdrd_dev_chip_info_get(unit);
    const bcmdrd_symbols_t *symbols = bcmdrd_dev_symbols_get(unit, 0);
    int indent = 0;
    uint32_t size, wsize, min, max, step;
    uint32_t acc_type, blk_info, mask, addr;
    bool is_mem, is_head;
    int rv, idx, blktype, num_tbl_inst;
    shr_pb_t *pb;
    const char *str;
    const bcmdrd_block_t *pblk;

    if (!bcmdrd_chip_sym_valid(cinfo, sid)) {
        return 0;
    }

    /* Only print register or memory symbol */
    if ((s->flags &
         (BCMDRD_SYMBOL_FLAG_MEMORY | BCMDRD_SYMBOL_FLAG_REGISTER)) == 0) {
        return 0;
    }

    /* Extract encoded symbol information */
    size = BCMDRD_SYMBOL_INDEX_SIZE_GET(s->index);
    wsize = BCMDRD_BYTES2WORDS(size);
    min = BCMDRD_SYMBOL_INDEX_MIN_GET(s->index);
    max = BCMDRD_SYMBOL_INDEX_MAX_GET(s->index);
    step = BCMDRD_SYMBOL_INDEX_STEP_GET(s->index);
    is_mem = ((s->flags & BCMDRD_SYMBOL_FLAG_MEMORY) != 0);
    /* Max index may depend on current chip configuration */
    if (is_mem) {
        max = bcmdrd_chip_mem_maxidx(cinfo, sid, max);
    }
    acc_type = BCMDRD_SYM_INFO_ACCTYPE(s->info);
    blk_info = BCMDRD_SYM_INFO_BLKTYPES(s->info);

    pb = shr_pb_create();

    /*
     * Each symbol is an entry of the sequence which is the value of the
     * mapping to the device ID key.
     */
    indent += INDENT_STEP;
    shr_pb_printf(pb, IFMT "- \n", ISTR(indent));

    /* Name */
    indent += INDENT_STEP;
    shr_pb_printf(pb, IFMT "%-13s [%s", ISTR(indent),
                  "name:", s->name);
#if  BCMDRD_CONFIG_INCLUDE_ALIAS_NAMES == 1
    if (s->ufname) {
        shr_pb_printf(pb, ", %s", s->ufname);
    }
    if (s->alias) {
        shr_pb_printf(pb, ", %s", s->alias);
    }
#endif
    shr_pb_printf(pb, "]\n");

    /* Offset */
    addr = s->addr;
    if (cinfo->block_port_addr) {
        pblk = bcmdrd_chip_block_types_match(cinfo, blk_info, NULL);
        if (pblk) {
            addr = cinfo->block_port_addr(pblk->blknum, is_mem ? -1 : 0,
                                          addr, 0);
        }
    }
    shr_pb_printf(pb, IFMT "%-13s 0x%08"PRIx32"\n", ISTR(indent),
                  "offset:", addr);

    /* Access type */
    if (acc_type) {
        shr_pb_printf(pb, IFMT "%-13s %"PRIu32"\n", ISTR(indent),
                      "access:", acc_type);
    }

    /* Size */
    shr_pb_printf(pb, IFMT "%-13s {bytes: %u, words: %u}\n", ISTR(indent),
                  "size:", size, wsize);

    /* Reset value and mask */
    if (!is_mem) {
        const uint32_t *resetval;

        resetval = bcmdrd_sym_reg_resetval_get(symbols, s);
        if (resetval) {
            shr_pb_printf(pb, IFMT "%-13s [0x%08"PRIx32, ISTR(indent),
                          "reset_value:", resetval[0]);
            for (idx = 1; idx < wsize; idx++) {
                shr_pb_printf(pb, ", 0x%08"PRIx32, resetval[idx]);
            }
            shr_pb_printf(pb, "]\n");
            shr_pb_printf(pb, IFMT "%-13s [0x%08"PRIx32, ISTR(indent),
                          "reset_mask:", resetval[wsize]);
            for (idx = 1; idx < wsize; idx++) {
                shr_pb_printf(pb, ", 0x%08"PRIx32, resetval[wsize + idx]);
            }
            shr_pb_printf(pb, "]\n");
        }
    }

    /* Flags */
    shr_pb_printf(pb, IFMT "%-13s [", ISTR(indent),
                  "flags:");
    is_head = true;
    for (mask = 1; mask; mask <<= 1) {
        if (s->flags & mask) {
            str = bcmdrd_enum_sym_flag_name(mask);
            if (str != NULL) {
                if (!is_head) {
                    shr_pb_printf(pb, ", ");
                }
                shr_pb_printf(pb, "%s", str);
                is_head = false;
            }
        }
    }
    shr_pb_printf(pb, "]\n");

    /* Blocks */
    shr_pb_printf(pb, IFMT "blocks: \n", ISTR(indent));
    indent += INDENT_STEP;
    blktype = -1;
    while ((blktype = bcmdrd_pt_blktype_get(unit, sid, blktype + 1)) >= 0) {
        str = cinfo->blktype_names[blktype];
        shr_pb_printf(pb, IFMT "%s: [", ISTR(indent),
                      str);
        is_head = true;
        idx = 0;
        if (s->flags & BCMDRD_SYMBOL_FLAG_MEMMAPPED) {
            shr_pb_printf(pb, "-1");
            is_head = false;
        }
        while ((pblk = bcmdrd_chip_block(cinfo, blktype, idx++)) != NULL) {
            if ((s->flags & BCMDRD_SYMBOL_FLAG_PORT) != 0 ||
                (s->flags & BCMDRD_SYMBOL_FLAG_SOFT_PORT) != 0) {
                bcmdrd_pbmp_t valid_pbmp;

                /* Skip port blocks with NULL port bitmap */
                if (BCMDRD_PBMP_IS_NULL(pblk->pbmps)) {
                    continue;
                }
                /* Check for valid port bitmap */
                bcmdrd_dev_phys_pbmp(unit, &valid_pbmp);
                BCMDRD_PBMP_AND(valid_pbmp, pblk->pbmps);
                if (BCMDRD_PBMP_IS_NULL(valid_pbmp)) {
                    continue;
                }
            }
            if (!is_head) {
                shr_pb_printf(pb, ", ");
            }
            shr_pb_printf(pb, "%d", pblk->blknum);
            is_head = false;
        }
        shr_pb_printf(pb, "]\n");
        if (is_head == true) {
            fprintf(stderr, "Failed to find block number for %s\n", s->name);
            shr_pb_destroy(pb);
            return -1;
        }
    }
    indent -= INDENT_STEP;

    /* Index */
    if (is_mem || (max - min) > 0) {
        shr_pb_printf(pb, IFMT "%-13s {maxidx: %"PRIu32", minidx: %"PRIu32,
                      ISTR(indent),
                      "index:", max, min);
        if (!is_mem) {
            shr_pb_printf(pb, ", step: %"PRIu32, step);
        }
        shr_pb_printf(pb, "}\n");
    }

    /* Instance */
    if ((num_tbl_inst = bcmdrd_pt_num_tbl_inst(unit, sid)) > 1) {
        shr_pb_printf(pb, IFMT "%-13s [", ISTR(indent), "instance:");
        is_head = true;
        for (idx = 0; idx < num_tbl_inst; idx++) {
            if (bcmdrd_pt_index_valid(unit, sid, idx, -1)) {
                if (!is_head) {
                    shr_pb_printf(pb, ", ");
                }
                shr_pb_printf(pb, "%d", idx);
                is_head = false;
            }
        }
        shr_pb_printf(pb, "]\n");
        if (is_head == true) {
            fprintf(stderr, "Failed to get valid instance for %s\n", s->name);
            shr_pb_destroy(pb);
            return -1;
        }
    }

    /* Fields */
#if BCMDRD_CONFIG_INCLUDE_FIELD_INFO == 1
    if (s->fields) {
        const char **fnames = symbols->field_names;
        int fidx = 0;
        bcmdrd_sym_field_info_t finfo;

        shr_pb_printf(pb, IFMT "fields: \n", ISTR(indent));
        indent += INDENT_STEP;

        BCMDRD_SYM_FIELDS_ITER_BEGIN(s->fields, finfo, symbols->field_names) {
            if (finfo.view >= 0) {
                rv = bcmdrd_symbol_field_filter(s, fnames,
                                                fnames[finfo.view], NULL);
                if (rv != 0) {
                    continue;
                }
            }
            if (finfo.name) {
                shr_pb_printf(pb, IFMT "%s: {", ISTR(indent),
                              finfo.name);
            } else {
                shr_pb_printf(pb, IFMT "field%d: {", ISTR(indent),
                              fidx++);
            }
            shr_pb_printf(pb, "maxbit: %d, minbit: %d}\n",
                          finfo.maxbit, finfo.minbit);
        } BCMDRD_SYM_FIELDS_ITER_END();

        indent -= INDENT_STEP;
    }
#endif

    fprintf(fh, "%s", shr_pb_str(pb));

    shr_pb_destroy(pb);

    return 0;
}

static int
emit_symbols(int unit, const char *dev_name, FILE *fh)
{
    const bcmdrd_symbols_t *symbols;
    bcmdrd_symbols_iter_t iter;
    sym_data_t sym_data;

    symbols = bcmdrd_dev_symbols_get(unit, 0);
    if (symbols == NULL) {
        fprintf(stderr, "bcmdrd_dev_symbols_get failed\n");
        return -1;
    }

    fprintf(fh, "\n# Physical memories and registers for %s\n", dev_name);
    fprintf(fh, "---\n");
    fprintf(fh, "%s: \n", dev_name);

    memset(&sym_data, 0, sizeof(sym_data));
    sym_data.unit = unit;
    sym_data.fh = fh;

    memset(&iter, 0, sizeof(iter));
    /* Iterate over all symbols */
    iter.name = "*";
    iter.symbols = symbols;
    iter.function = print_symbol;
    iter.vptr = &sym_data;
    if (bcmdrd_symbols_iter(&iter) <= 0) {
        fprintf(stderr, "Failed to iterate symbols for %s\n", dev_name);
        return -1;
    }
    fprintf(fh, "...\n");

    return 0;
}

static int
make_symtbl(int unit, const char *dev_name)
{
    FILE *fh = stdout;

    /* Print file header */
    print_header(fh);

    /* Print the device symbols */
    if (emit_symbols(unit, dev_name, fh) == 0) {
        fprintf(stderr, "Output symbols for %s to stdout\n", dev_name);
    }

    return 0;
}

static void
show_usage(const char *prg_name)
{
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "%s [options]\n", prg_name);
    fprintf(stderr,
            "-o <dev>    Device type for which to create symbol table.\n"
            "-h          Show help message.\n"
            "\n");
}

/*******************************************************************************
 * Public functions
 */

int
main(int argc, char *argv[])
{
    const char *dev_name = NULL;
    int unit = 0;

    /* Initialize and display version string */
    version_init();
    version_signon();

    while (1) {
        int ch;

        ch = getopt(argc, argv, "o:h");
        if (ch == -1) {
            /* No more options */
            break;
        }

        switch (ch) {
        case 'o':
            if (dev_init(unit, optarg, &dev_name) < 0) {
                fprintf(stderr, "Unsupported device: %s\n", optarg);
                exit(-2);
            }
            break;

        case 'h':
            show_usage(argv[0]);
            exit(-2);
            break;

        default:
            exit(-2);
            break;
        }
    }

    if (dev_name == NULL) {
        show_usage(argv[0]);
        exit(-2);
    }

    /* Make symbol table */
    make_symtbl(unit, dev_name);

    /* Clean up device resource */
    dev_cleanup(unit);

    exit(0);
}
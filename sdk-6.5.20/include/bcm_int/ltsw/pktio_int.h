/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef BCMINT_LTSW_PKTIO_INT_H
#define BCMINT_LTSW_PKTIO_INT_H

#include <sal/sal_types.h>

/*! API to LT opcode. */
#define BCMINT_PKTIO_OP_API2LT 0

/*! LT to API opcode. */
#define BCMINT_PKTIO_OP_LT2API 1

/*!
 * \brief Internal pktio pmd type.
 */
typedef enum bcmint_pktio_pmd_type_s {

    /*! Match id. */
    bcmintPktioPmdTypeMatchId = 32

} bcmint_pktio_pmd_type_t;

#define BCMINT_PKTIO_PMD_TYPE_STR \
{ \
    "MatchId" \
}

/*!
 * \brief Pktio header info.
 */
typedef struct bcmint_pktio_hdr_info_s {

    /*! Pktio pmd type. */
    int pmd_type;

    /*! Pktio field id. */
    int fid;

    /*! Check profile number. */
    bool profile_chk;

    /*! Profile number. */
    uint32_t profile;

} bcmint_pktio_hdr_info_t;

/*!
 * \brief Pktio field info.
 */
typedef struct bcmint_pktio_fid_info_s {

    /*! Pktio field id. */
    int fid;

    /*! Pktio lt field id. */
    int lt_fid;

    /*! Pktio profile bitmap. */
    uint32_t profile_bmp;

    /*! Pktio lt string. */
    const char *lt_str;

} bcmint_pktio_fid_info_t;

#endif /* BCMINT_LTSW_PKTIO_INT_H */
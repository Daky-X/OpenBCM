#ifndef BCMPKT_RXPMD_FLEX_DEFS_H
#define BCMPKT_RXPMD_FLEX_DEFS_H
/*****************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by xfc_map_parser
 * from the NPL output file(s) map.yml.
 * Edits to this file will be lost when it is regenerated.
 *
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 * All Rights Reserved.$
 *
 * Tool Path: $SDK/INTERNAL/fltg/xfc_map_parser
 */

/*!
 * \name RX flex metadata field IDs.
 * \anchor BCMPKT_RXPMD_FLEX_XXX
 */
#define BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_15_0                        0
#define BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_31_16                       1
#define BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_47_32                       2
#define BCMPKT_RXPMD_FLEX_DROP_CODE_15_0                                 3
#define BCMPKT_RXPMD_FLEX_PARSER_VHLEN_0_15_0                            4
#define BCMPKT_RXPMD_FLEX_IFP_TO_EP_MACSEC_INFO_15_0                     5
#define BCMPKT_RXPMD_FLEX_NHOP_INDEX_1_15_0                              6
#define BCMPKT_RXPMD_FLEX_SVP_15_0                                       7
#define BCMPKT_RXPMD_FLEX_EM_FT_OPAQUE_OBJ_OR_IFP_OPAQUE_OBJ_15_0        8
#define BCMPKT_RXPMD_FLEX_EFFECTIVE_TTL_7_0                              9
#define BCMPKT_RXPMD_FLEX_SYSTEM_SOURCE_15_0                             10
#define BCMPKT_RXPMD_FLEX_SYSTEM_DESTINATION_15_0                        11
#define BCMPKT_RXPMD_FLEX_VFI_15_0                                       12
#define BCMPKT_RXPMD_FLEX_DVP_15_0                                       13
#define BCMPKT_RXPMD_FLEX_NHOP_2_OR_ECMP_GROUP_INDEX_1_15_0              14
#define BCMPKT_RXPMD_FLEX_L2_IIF_10_0                                    15
#define BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_LOW_15_0                         16
#define BCMPKT_RXPMD_FLEX_INGRESS_PP_PORT_7_0                            17
#define BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_15_0                      18
#define BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_31_16                     19
#define BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMAP_VALUE_OR_IFP_OPAQUE_OBJ_15_0 20
#define BCMPKT_RXPMD_FLEX_I2E_CLASS_ID_15_0                              21
#define BCMPKT_RXPMD_FLEX_L3_IIF_13_0                                    22
#define BCMPKT_RXPMD_FLEX_L3_OIF_1_13_0                                  23
#define BCMPKT_RXPMD_FLEX_IFP_TS_CONTROL_ACTION_3_0                      24
#define BCMPKT_RXPMD_FLEX_IFP_IOAM_GBP_ACTION_3_0                        25
#define BCMPKT_RXPMD_FLEX_TIMESTAMP_CTRL_3_0                             26
#define BCMPKT_RXPMD_FLEX_VLAN_TAG_PRESERVE_CTRL_SVP_MIRROR_ENABLE_1_0   27
#define BCMPKT_RXPMD_FLEX_SVP_NETWORK_GROUP_BITMAP_3_0                   28
#define BCMPKT_RXPMD_FLEX_INT_PRI_3_0                                    29
#define BCMPKT_RXPMD_FLEX_EGR_MTOP_INDEX_HI_3_0                          30
#define BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMARK_CTRL_3_0                    31
#define BCMPKT_RXPMD_FLEX_TUNNEL_PROCESSING_RESULTS_1_3_0                32
#define BCMPKT_RXPMD_FLEX_SYSTEM_OPCODE_3_0                              33
#define BCMPKT_RXPMD_FLEX_PKT_MISC_CTRL_0_3_0                            34
#define BCMPKT_RXPMD_FLEX_L2_OIF_10_0                                    35
#define BCMPKT_RXPMD_FLEX_EGR_MTOP_INDEX_LO_15_0                         36
#define BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_15_0                             37
#define BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_HIGH_3_0                         38
#define BCMPKT_RXPMD_FLEX_DLB_ECMP_DESTINATION_15_0                      39
#define BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_31_16                            40
#define BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_31_0                        41
#define BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_31_0                             42
#define BCMPKT_RXPMD_FLEX_MPLS_LABEL_DECAP_COUNT_3_0                     43

#define BCMPKT_RXPMD_FLEX_FID_COUNT                       44
#define BCMPKT_RXPMD_FLEX_FID_START                       0
#define BCMPKT_RXPMD_FLEX_FID_END                         43
#define BCMPKT_RXPMD_FLEX_I_REASON                        0
#define BCMPKT_RXPMD_FLEX_FID_INVALID                     -1
#define BCMPKT_RXPMD_FLEX_REASON_COUNT                    46

/*!
 * \name Packet Flex Reason Types.
 * \anchor BCMPKT_RXPMD_FLEX_REASON_XXX
 */
#define BCMPKT_RXPMD_FLEX_REASON_NO_COPY_TO_CPU                          0
#define BCMPKT_RXPMD_FLEX_REASON_CML_FLAGS                               1
#define BCMPKT_RXPMD_FLEX_REASON_L2_SRC_STATIC_MOVE                      2
#define BCMPKT_RXPMD_FLEX_REASON_L2_SRC_DISCARD                          3
#define BCMPKT_RXPMD_FLEX_REASON_MACSA_MULTICAST                         4
#define BCMPKT_RXPMD_FLEX_REASON_PKT_INTEGRITY_CHECK_FAILED              5
#define BCMPKT_RXPMD_FLEX_REASON_PROTOCOL_PKT                            6
#define BCMPKT_RXPMD_FLEX_REASON_MEMBERSHIP_CHECK_FAILED                 7
#define BCMPKT_RXPMD_FLEX_REASON_SPANNING_TREE_CHECK_FAILED              8
#define BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP_MISS                      9
#define BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP                           10
#define BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP_MISS                      11
#define BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP                           12
#define BCMPKT_RXPMD_FLEX_REASON_L3_HDR_ERROR                            13
#define BCMPKT_RXPMD_FLEX_REASON_L3_TTL_ERROR                            14
#define BCMPKT_RXPMD_FLEX_REASON_IPMC_L3_IIF_OR_RPA_ID_CHECK_FAILED      15
#define BCMPKT_RXPMD_FLEX_REASON_LEARN_CACHE_FULL                        16
#define BCMPKT_RXPMD_FLEX_REASON_VFP                                     17
#define BCMPKT_RXPMD_FLEX_REASON_IFP                                     18
#define BCMPKT_RXPMD_FLEX_REASON_IFP_METER                               19
#define BCMPKT_RXPMD_FLEX_REASON_DST_FP                                  20
#define BCMPKT_RXPMD_FLEX_REASON_SVP                                     21
#define BCMPKT_RXPMD_FLEX_REASON_EM_FT                                   22
#define BCMPKT_RXPMD_FLEX_REASON_IVXLT                                   23
#define BCMPKT_RXPMD_FLEX_REASON_MIRROR_SAMPLER_SAMPLED                  24
#define BCMPKT_RXPMD_FLEX_REASON_MIRROR_SAMPLER_EGR_SAMPLED              25
#define BCMPKT_RXPMD_FLEX_REASON_SER_DROP                                26
#define BCMPKT_RXPMD_FLEX_REASON_URPF_CHECK_FAILED                       27
#define BCMPKT_RXPMD_FLEX_REASON_L3_IIF_EQ_L3_OIF                        28
#define BCMPKT_RXPMD_FLEX_REASON_DLB_ECMP_MONITOR_EN_OR_MEMBER_REASSINED 29
#define BCMPKT_RXPMD_FLEX_REASON_DLB_LAG_MONITOR_EN_OR_MEMBER_REASSINED  30
#define BCMPKT_RXPMD_FLEX_REASON_MPLS_CTRL_PKT_TO_CPU                    31
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_0                      32
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_1                      33
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_2                      34
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_3                      35
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_4                      36
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_5                      37
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_6                      38
#define BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_7                      39
#define BCMPKT_RXPMD_FLEX_REASON_MTOP_IPV4_GATEWAY                       40
#define BCMPKT_RXPMD_FLEX_REASON_DLB_ECMP_PKT_SAMPLED                    41
#define BCMPKT_RXPMD_FLEX_REASON_DLB_LAG_PKT_SAMPLED                     42
#define BCMPKT_RXPMD_FLEX_REASON_TRACE_DO_NOT_MIRROR                     43
#define BCMPKT_RXPMD_FLEX_REASON_TRACE_DO_NOT_COPY_TO_CPU                44
#define BCMPKT_RXPMD_FLEX_REASON_TRACE_DOP                               45

#define BCMPKT_RXPMD_FLEX_FIELD_NAME_MAP_INIT \
    {"EVENT_TRACE_VECTOR_15_0", BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_15_0},\
    {"EVENT_TRACE_VECTOR_31_16", BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_31_16},\
    {"EVENT_TRACE_VECTOR_47_32", BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_47_32},\
    {"DROP_CODE_15_0", BCMPKT_RXPMD_FLEX_DROP_CODE_15_0},\
    {"PARSER_VHLEN_0_15_0", BCMPKT_RXPMD_FLEX_PARSER_VHLEN_0_15_0},\
    {"IFP_TO_EP_MACSEC_INFO_15_0", BCMPKT_RXPMD_FLEX_IFP_TO_EP_MACSEC_INFO_15_0},\
    {"NHOP_INDEX_1_15_0", BCMPKT_RXPMD_FLEX_NHOP_INDEX_1_15_0},\
    {"SVP_15_0", BCMPKT_RXPMD_FLEX_SVP_15_0},\
    {"EM_FT_OPAQUE_OBJ_OR_IFP_OPAQUE_OBJ_15_0", BCMPKT_RXPMD_FLEX_EM_FT_OPAQUE_OBJ_OR_IFP_OPAQUE_OBJ_15_0},\
    {"EFFECTIVE_TTL_7_0", BCMPKT_RXPMD_FLEX_EFFECTIVE_TTL_7_0},\
    {"SYSTEM_SOURCE_15_0", BCMPKT_RXPMD_FLEX_SYSTEM_SOURCE_15_0},\
    {"SYSTEM_DESTINATION_15_0", BCMPKT_RXPMD_FLEX_SYSTEM_DESTINATION_15_0},\
    {"VFI_15_0", BCMPKT_RXPMD_FLEX_VFI_15_0},\
    {"DVP_15_0", BCMPKT_RXPMD_FLEX_DVP_15_0},\
    {"NHOP_2_OR_ECMP_GROUP_INDEX_1_15_0", BCMPKT_RXPMD_FLEX_NHOP_2_OR_ECMP_GROUP_INDEX_1_15_0},\
    {"L2_IIF_10_0", BCMPKT_RXPMD_FLEX_L2_IIF_10_0},\
    {"ENTROPY_LABEL_LOW_15_0", BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_LOW_15_0},\
    {"INGRESS_PP_PORT_7_0", BCMPKT_RXPMD_FLEX_INGRESS_PP_PORT_7_0},\
    {"EP_NIH_HDR_TIMESTAMP_15_0", BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_15_0},\
    {"EP_NIH_HDR_TIMESTAMP_31_16", BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_31_16},\
    {"INGRESS_QOS_REMAP_VALUE_OR_IFP_OPAQUE_OBJ_15_0", BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMAP_VALUE_OR_IFP_OPAQUE_OBJ_15_0},\
    {"I2E_CLASS_ID_15_0", BCMPKT_RXPMD_FLEX_I2E_CLASS_ID_15_0},\
    {"L3_IIF_13_0", BCMPKT_RXPMD_FLEX_L3_IIF_13_0},\
    {"L3_OIF_1_13_0", BCMPKT_RXPMD_FLEX_L3_OIF_1_13_0},\
    {"IFP_TS_CONTROL_ACTION_3_0", BCMPKT_RXPMD_FLEX_IFP_TS_CONTROL_ACTION_3_0},\
    {"IFP_IOAM_GBP_ACTION_3_0", BCMPKT_RXPMD_FLEX_IFP_IOAM_GBP_ACTION_3_0},\
    {"TIMESTAMP_CTRL_3_0", BCMPKT_RXPMD_FLEX_TIMESTAMP_CTRL_3_0},\
    {"VLAN_TAG_PRESERVE_CTRL_SVP_MIRROR_ENABLE_1_0", BCMPKT_RXPMD_FLEX_VLAN_TAG_PRESERVE_CTRL_SVP_MIRROR_ENABLE_1_0},\
    {"SVP_NETWORK_GROUP_BITMAP_3_0", BCMPKT_RXPMD_FLEX_SVP_NETWORK_GROUP_BITMAP_3_0},\
    {"INT_PRI_3_0", BCMPKT_RXPMD_FLEX_INT_PRI_3_0},\
    {"EGR_MTOP_INDEX_HI_3_0", BCMPKT_RXPMD_FLEX_EGR_MTOP_INDEX_HI_3_0},\
    {"INGRESS_QOS_REMARK_CTRL_3_0", BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMARK_CTRL_3_0},\
    {"TUNNEL_PROCESSING_RESULTS_1_3_0", BCMPKT_RXPMD_FLEX_TUNNEL_PROCESSING_RESULTS_1_3_0},\
    {"SYSTEM_OPCODE_3_0", BCMPKT_RXPMD_FLEX_SYSTEM_OPCODE_3_0},\
    {"PKT_MISC_CTRL_0_3_0", BCMPKT_RXPMD_FLEX_PKT_MISC_CTRL_0_3_0},\
    {"L2_OIF_10_0", BCMPKT_RXPMD_FLEX_L2_OIF_10_0},\
    {"EGR_MTOP_INDEX_LO_15_0", BCMPKT_RXPMD_FLEX_EGR_MTOP_INDEX_LO_15_0},\
    {"ING_TIMESTAMP_15_0", BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_15_0},\
    {"ENTROPY_LABEL_HIGH_3_0", BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_HIGH_3_0},\
    {"DLB_ECMP_DESTINATION_15_0", BCMPKT_RXPMD_FLEX_DLB_ECMP_DESTINATION_15_0},\
    {"ING_TIMESTAMP_31_16", BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_31_16},\
    {"EVENT_TRACE_VECTOR_31_0", BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_31_0},\
    {"ING_TIMESTAMP_31_0", BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_31_0},\
    {"MPLS_LABEL_DECAP_COUNT_3_0", BCMPKT_RXPMD_FLEX_MPLS_LABEL_DECAP_COUNT_3_0},\
    {"flex pmd fid count", BCMPKT_RXPMD_FLEX_FID_COUNT}

#define BCMPKT_RXPMD_FLEX_REASON_NAME_MAP_INIT \
    {"NO_COPY_TO_CPU", BCMPKT_RXPMD_FLEX_REASON_NO_COPY_TO_CPU},\
    {"CML_FLAGS", BCMPKT_RXPMD_FLEX_REASON_CML_FLAGS},\
    {"L2_SRC_STATIC_MOVE", BCMPKT_RXPMD_FLEX_REASON_L2_SRC_STATIC_MOVE},\
    {"L2_SRC_DISCARD", BCMPKT_RXPMD_FLEX_REASON_L2_SRC_DISCARD},\
    {"MACSA_MULTICAST", BCMPKT_RXPMD_FLEX_REASON_MACSA_MULTICAST},\
    {"PKT_INTEGRITY_CHECK_FAILED", BCMPKT_RXPMD_FLEX_REASON_PKT_INTEGRITY_CHECK_FAILED},\
    {"PROTOCOL_PKT", BCMPKT_RXPMD_FLEX_REASON_PROTOCOL_PKT},\
    {"MEMBERSHIP_CHECK_FAILED", BCMPKT_RXPMD_FLEX_REASON_MEMBERSHIP_CHECK_FAILED},\
    {"SPANNING_TREE_CHECK_FAILED", BCMPKT_RXPMD_FLEX_REASON_SPANNING_TREE_CHECK_FAILED},\
    {"L2_DST_LOOKUP_MISS", BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP_MISS},\
    {"L2_DST_LOOKUP", BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP},\
    {"L3_DST_LOOKUP_MISS", BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP_MISS},\
    {"L3_DST_LOOKUP", BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP},\
    {"L3_HDR_ERROR", BCMPKT_RXPMD_FLEX_REASON_L3_HDR_ERROR},\
    {"L3_TTL_ERROR", BCMPKT_RXPMD_FLEX_REASON_L3_TTL_ERROR},\
    {"IPMC_L3_IIF_OR_RPA_ID_CHECK_FAILED", BCMPKT_RXPMD_FLEX_REASON_IPMC_L3_IIF_OR_RPA_ID_CHECK_FAILED},\
    {"LEARN_CACHE_FULL", BCMPKT_RXPMD_FLEX_REASON_LEARN_CACHE_FULL},\
    {"VFP", BCMPKT_RXPMD_FLEX_REASON_VFP},\
    {"IFP", BCMPKT_RXPMD_FLEX_REASON_IFP},\
    {"IFP_METER", BCMPKT_RXPMD_FLEX_REASON_IFP_METER},\
    {"DST_FP", BCMPKT_RXPMD_FLEX_REASON_DST_FP},\
    {"SVP", BCMPKT_RXPMD_FLEX_REASON_SVP},\
    {"EM_FT", BCMPKT_RXPMD_FLEX_REASON_EM_FT},\
    {"IVXLT", BCMPKT_RXPMD_FLEX_REASON_IVXLT},\
    {"MIRROR_SAMPLER_SAMPLED", BCMPKT_RXPMD_FLEX_REASON_MIRROR_SAMPLER_SAMPLED},\
    {"MIRROR_SAMPLER_EGR_SAMPLED", BCMPKT_RXPMD_FLEX_REASON_MIRROR_SAMPLER_EGR_SAMPLED},\
    {"SER_DROP", BCMPKT_RXPMD_FLEX_REASON_SER_DROP},\
    {"URPF_CHECK_FAILED", BCMPKT_RXPMD_FLEX_REASON_URPF_CHECK_FAILED},\
    {"L3_IIF_EQ_L3_OIF", BCMPKT_RXPMD_FLEX_REASON_L3_IIF_EQ_L3_OIF},\
    {"DLB_ECMP_MONITOR_EN_OR_MEMBER_REASSINED", BCMPKT_RXPMD_FLEX_REASON_DLB_ECMP_MONITOR_EN_OR_MEMBER_REASSINED},\
    {"DLB_LAG_MONITOR_EN_OR_MEMBER_REASSINED", BCMPKT_RXPMD_FLEX_REASON_DLB_LAG_MONITOR_EN_OR_MEMBER_REASSINED},\
    {"MPLS_CTRL_PKT_TO_CPU", BCMPKT_RXPMD_FLEX_REASON_MPLS_CTRL_PKT_TO_CPU},\
    {"MATCHED_RULE_BIT_0", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_0},\
    {"MATCHED_RULE_BIT_1", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_1},\
    {"MATCHED_RULE_BIT_2", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_2},\
    {"MATCHED_RULE_BIT_3", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_3},\
    {"MATCHED_RULE_BIT_4", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_4},\
    {"MATCHED_RULE_BIT_5", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_5},\
    {"MATCHED_RULE_BIT_6", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_6},\
    {"MATCHED_RULE_BIT_7", BCMPKT_RXPMD_FLEX_REASON_MATCHED_RULE_BIT_7},\
    {"MTOP_IPV4_GATEWAY", BCMPKT_RXPMD_FLEX_REASON_MTOP_IPV4_GATEWAY},\
    {"DLB_ECMP_PKT_SAMPLED", BCMPKT_RXPMD_FLEX_REASON_DLB_ECMP_PKT_SAMPLED},\
    {"DLB_LAG_PKT_SAMPLED", BCMPKT_RXPMD_FLEX_REASON_DLB_LAG_PKT_SAMPLED},\
    {"TRACE_DO_NOT_MIRROR", BCMPKT_RXPMD_FLEX_REASON_TRACE_DO_NOT_MIRROR},\
    {"TRACE_DO_NOT_COPY_TO_CPU", BCMPKT_RXPMD_FLEX_REASON_TRACE_DO_NOT_COPY_TO_CPU},\
    {"TRACE_DOP", BCMPKT_RXPMD_FLEX_REASON_TRACE_DOP},\
    {"flex reason count", BCMPKT_RXPMD_FLEX_REASON_COUNT}

#endif /* BCMPKT_RXPMD_FLEX_DEFS_H */
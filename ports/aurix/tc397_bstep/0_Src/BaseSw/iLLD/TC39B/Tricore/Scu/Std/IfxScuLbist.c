/**
 * \file IfxScuLbist.c
 * \brief SCU  basic functionality
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScuLbist.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxScuLbist_ParameterSet IfxScuLbist_defaultConfig = {
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#ifndef IFX_CFG_LBIST_CFG_B_ENABLED
    .application     = IfxScuLbist_Application_pt,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_A,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_A,
#else
    .application     = IfxScuLbist_Application_pt,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_B,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_B,
#endif
#else
#ifndef IFX_CFG_LBIST_CFG_B_ENABLED
    .application     = IfxScuLbist_Application_body,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_A,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_A,
#else
    .application     = IfxScuLbist_Application_body,
    .freq            = IfxScuLbist_Freq_div6,
    .splitShiftSel   = IfxScuLbist_SplitShiftSel_fourScanPartitions,
    .seed            = IFXSCULBIST_CFG_SEED,
    .pattern         = IFXSCULBIST_CFG_PATTERN_B,
    .scanChainLength = IFXSCULBIST_CFG_SCANCHAINLENGTH,
    .signature       = IFXSCULBIST_CFG_SIGNATURE_B,
#endif
#endif
};

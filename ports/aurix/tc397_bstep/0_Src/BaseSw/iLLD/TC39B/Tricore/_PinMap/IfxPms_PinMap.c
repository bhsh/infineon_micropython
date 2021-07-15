/**
 * \file IfxPms_PinMap.c
 * \brief PMS I/O map
 * \ingroup IfxLld_Pms
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 */

#include "IfxPms_PinMap.h"

IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_2_OUT = {&MODULE_PMS, {&MODULE_P32, 2}, IfxPort_OutputIdx_alt6};
IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_4_OUT = {&MODULE_PMS, {&MODULE_P32, 4}, IfxPort_OutputIdx_alt2};
IfxPms_Hwcfg_In IfxPms_HWCFG1IN_P14_5_IN = {&MODULE_PMS, {&MODULE_P14, 5}};
IfxPms_Hwcfg_In IfxPms_HWCFG2IN_P14_2_IN = {&MODULE_PMS, {&MODULE_P14, 2}};
IfxPms_Hwcfg_In IfxPms_HWCFG3IN_P14_3_IN = {&MODULE_PMS, {&MODULE_P14, 3}};
IfxPms_Hwcfg_In IfxPms_HWCFG4IN_P10_5_IN = {&MODULE_PMS, {&MODULE_P10, 5}};
IfxPms_Hwcfg_In IfxPms_HWCFG5IN_P10_6_IN = {&MODULE_PMS, {&MODULE_P10, 6}};
IfxPms_Hwcfg_In IfxPms_HWCFG6IN_P14_4_IN = {&MODULE_PMS, {&MODULE_P14, 4}};
IfxPms_Wkp_In IfxPms_PINAWKP_P14_1_IN = {&MODULE_PMS, {&MODULE_P14, 1}, Ifx_RxSel_a};
IfxPms_Wkp_In IfxPms_PINBWKP_P33_12_IN = {&MODULE_PMS, {&MODULE_P33,12}, Ifx_RxSel_b};


const IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS] = {
    {
        &IfxPms_DCDCSYNC_P32_2_OUT,
        &IfxPms_DCDCSYNC_P32_4_OUT
    }
};

const IfxPms_Hwcfg_In *IfxPms_Hwcfg_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_HWCFG_IN_NUM_ITEMS] = {
    {
        &IfxPms_HWCFG6IN_P14_4_IN,
        &IfxPms_HWCFG3IN_P14_3_IN,
        &IfxPms_HWCFG1IN_P14_5_IN,
        &IfxPms_HWCFG2IN_P14_2_IN,
        &IfxPms_HWCFG5IN_P10_6_IN,
        &IfxPms_HWCFG4IN_P10_5_IN
    }
};

const IfxPms_Wkp_In *IfxPms_Wkp_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_WKP_IN_NUM_ITEMS] = {
    {
        &IfxPms_PINAWKP_P14_1_IN,
        &IfxPms_PINBWKP_P33_12_IN
    }
};

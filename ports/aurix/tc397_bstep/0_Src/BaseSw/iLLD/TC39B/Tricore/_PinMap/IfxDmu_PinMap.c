/**
 * \file IfxDmu_PinMap.c
 * \brief DMU I/O map
 * \ingroup IfxLld_Dmu
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

#include "IfxDmu_PinMap.h"

IfxDmu_Fdest_In IfxDmu_FDEST_P21_0_IN = {&MODULE_DMU, {&MODULE_P21, 0}, Ifx_RxSel_a};


const IfxDmu_Fdest_In *IfxDmu_Fdest_In_pinTable[IFXDMU_PINMAP_NUM_MODULES][IFXDMU_PINMAP_NUM_0S][IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS] = {
    {
        {
            &IfxDmu_FDEST_P21_0_IN
        }
    }
};

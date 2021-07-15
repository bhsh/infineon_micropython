/**
 * \file IfxDmu_PinMap.h
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
 * \defgroup IfxLld_Dmu_pinmap DMU Pin Mapping
 * \ingroup IfxLld_Dmu
 */

#ifndef IFXDMU_PINMAP_H
#define IFXDMU_PINMAP_H

#include <IfxDmu_reg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Dmu_pinmap
 * \{ */

/** \brief DMU FDEST pin mapping structure */
typedef const struct
{
    Ifx_DMU*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxDmu_Fdest_In;


IFX_EXTERN IfxDmu_Fdest_In IfxDmu_FDEST_P21_0_IN;  /**< \brief Enter destructive debug mode */

/** \brief Table dimensions */
#define IFXDMU_PINMAP_NUM_MODULES 1
#define IFXDMU_PINMAP_NUM_0S 1
#define IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS 1


/** \brief IfxDmu_Fdest_In table */
IFX_EXTERN const IfxDmu_Fdest_In *IfxDmu_Fdest_In_pinTable[IFXDMU_PINMAP_NUM_MODULES][IFXDMU_PINMAP_NUM_0S][IFXDMU_PINMAP_FDEST_IN_NUM_ITEMS];

/** \} */

#endif /* IFXDMU_PINMAP_H */

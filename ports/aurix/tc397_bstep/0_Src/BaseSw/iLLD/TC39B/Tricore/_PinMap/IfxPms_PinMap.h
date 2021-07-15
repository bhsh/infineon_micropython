/**
 * \file IfxPms_PinMap.h
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
 * \defgroup IfxLld_Pms_pinmap PMS Pin Mapping
 * \ingroup IfxLld_Pms
 */

#ifndef IFXPMS_PINMAP_H
#define IFXPMS_PINMAP_H

#include <IfxPms_reg.h>
#include <_Impl/IfxPms_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Pms_pinmap
 * \{ */

/** \brief Wakeup pin mapping structure */
typedef const struct
{
    Ifx_PMS*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxPms_Wkp_In;

/** \brief DCDC Sync pin mapping structure */
typedef const struct
{
    Ifx_PMS*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxPms_Dcdcsync_Out;

/** \brief Hardware Configuration pin mapping structure */
typedef const struct
{
    Ifx_PMS*          module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
} IfxPms_Hwcfg_In;


IFX_EXTERN IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_2_OUT;  /**< \brief DC-DC synchronization output */
IFX_EXTERN IfxPms_Dcdcsync_Out IfxPms_DCDCSYNC_P32_4_OUT;  /**< \brief DC-DC synchronization output */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG1IN_P14_5_IN;  /**< \brief HWCFG1 pin input */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG2IN_P14_2_IN;  /**< \brief HWCFG2 pin input */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG3IN_P14_3_IN;  /**< \brief HWCFG3 pin input */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG4IN_P10_5_IN;  /**< \brief HWCFG4 pin input */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG5IN_P10_6_IN;  /**< \brief HWCFG5 pin input */
IFX_EXTERN IfxPms_Hwcfg_In IfxPms_HWCFG6IN_P14_4_IN;  /**< \brief HWCFG6 pin input */
IFX_EXTERN IfxPms_Wkp_In IfxPms_PINAWKP_P14_1_IN;  /**< \brief PINA ( P14.1) pin input */
IFX_EXTERN IfxPms_Wkp_In IfxPms_PINBWKP_P33_12_IN;  /**< \brief PINB (P33.12) pin input */

/** \brief Table dimensions */
#define IFXPMS_PINMAP_NUM_MODULES 1
#define IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS 2
#define IFXPMS_PINMAP_HWCFG_IN_NUM_ITEMS 6
#define IFXPMS_PINMAP_WKP_IN_NUM_ITEMS 2


/** \brief IfxPms_Dcdcsync_Out table */
IFX_EXTERN const IfxPms_Dcdcsync_Out *IfxPms_Dcdcsync_Out_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_DCDCSYNC_OUT_NUM_ITEMS];

/** \brief IfxPms_Hwcfg_In table */
IFX_EXTERN const IfxPms_Hwcfg_In *IfxPms_Hwcfg_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_HWCFG_IN_NUM_ITEMS];

/** \brief IfxPms_Wkp_In table */
IFX_EXTERN const IfxPms_Wkp_In *IfxPms_Wkp_In_pinTable[IFXPMS_PINMAP_NUM_MODULES][IFXPMS_PINMAP_WKP_IN_NUM_ITEMS];

/** \} */

#endif /* IFXPMS_PINMAP_H */

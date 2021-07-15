/**
 * \file IfxPmu_regdef.h
 * \brief
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC39XB_UM_V1.0.0.R0
 * Specification: TC3xx User Manual V1.0.0
 * MAY BE CHANGED BY USER [yes/no]: No
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
 * \defgroup IfxSfr_Pmu_Registers Pmu Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Pmu_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_union Register unions
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_struct Memory map
 * \ingroup IfxSfr_Pmu_Registers
 */
#ifndef IFXPMU_REGDEF_H
#define IFXPMU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Pmu_Registers_Bitfields
 * \{  */
/** \brief Module Identification Register */
typedef struct _Ifx_PMU_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_PMU_ID_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_pmu_Registers_union
 * \{   */
/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_PMU_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_PMU_ID;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Pmu_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief PMU object */
typedef volatile struct _Ifx_PMU
{
       Ifx_UReg_8Bit                       reserved_0[1288];       /**< \brief 0, \internal Reserved */
       Ifx_PMU_ID                          ID;                     /**< \brief 508, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_50C[31476];    /**< \brief 50C, \internal Reserved */
} Ifx_PMU;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXPMU_REGDEF_H */

/**
 * \file IfxPmu_reg.h
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
 * \defgroup IfxSfr_Pmu_Registers_Cfg Pmu address
 * \ingroup IfxSfr_Pmu_Registers
 * 
 * \defgroup IfxSfr_Pmu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Pmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Pmu_Registers_Cfg_Pmu 2-PMU
 * \ingroup IfxSfr_Pmu_Registers_Cfg
 *
 *
 */
#ifndef IFXPMU_REG_H
#define IFXPMU_REG_H 1
/******************************************************************************/
#include "IfxPmu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Pmu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief PMU object */
#define MODULE_PMU /*lint --e(923, 9078)*/ ((*(Ifx_PMU*)0xF8038000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Pmu_Registers_Cfg_Pmu
 * \{  */
/** \brief 508, Module Identification Register */
#define PMU_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_PMU_ID*)0xF8038508u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXPMU_REG_H */

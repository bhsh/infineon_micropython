/**
 * \file IfxConverter_reg.h
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
 * \defgroup IfxSfr_Converter_Registers_Cfg Converter address
 * \ingroup IfxSfr_Converter_Registers
 * 
 * \defgroup IfxSfr_Converter_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Converter_Registers_Cfg
 *
 * \defgroup IfxSfr_Converter_Registers_Cfg_Convctrl 2-CONVCTRL
 * \ingroup IfxSfr_Converter_Registers_Cfg
 *
 *
 */
#ifndef IFXCONVERTER_REG_H
#define IFXCONVERTER_REG_H 1
/******************************************************************************/
#include "IfxConverter_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Converter_Registers_Cfg_BaseAddress
 * \{  */

/** \brief CONVERTER object */
#define MODULE_CONVCTRL /*lint --e(923, 9078)*/ ((*(Ifx_CONVERTER*)0xF0025000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Converter_Registers_Cfg_Convctrl
 * \{  */
/** \brief 0, Clock Control Register */
#define CONVCTRL_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_CLC*)0xF0025000u)

/** \brief 8, Module Identification Register */
#define CONVCTRL_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_ID*)0xF0025008u)

/** \brief 28, OCDS Control and Status Register */
#define CONVCTRL_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_OCS*)0xF0025028u)

/** \brief 2C, Kernel Reset Status Clear Register */
#define CONVCTRL_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_KRSTCLR*)0xF002502Cu)

/** \brief 30, Kernel Reset Register 1 */
#define CONVCTRL_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_KRST1*)0xF0025030u)

/** \brief 34, Kernel Reset Register 0 */
#define CONVCTRL_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_KRST0*)0xF0025034u)

/** \brief 3C, Access Enable Register 0 */
#define CONVCTRL_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_ACCEN0*)0xF002503Cu)

/** \brief 7C, Converter Control Block Control Register */
#define CONVCTRL_CCCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_CCCTRL*)0xF002507Cu)

/** \brief 80, Phase Synchronizer Configuration Register */
#define CONVCTRL_PHSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_PHSCFG*)0xF0025080u)

/** \brief 84, Phase Synchronizer Safety Control Register */
#define CONVCTRL_PHSSFTY /*lint --e(923, 9078)*/ (*(volatile Ifx_CONVERTER_PHSSFTY*)0xF0025084u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXCONVERTER_REG_H */

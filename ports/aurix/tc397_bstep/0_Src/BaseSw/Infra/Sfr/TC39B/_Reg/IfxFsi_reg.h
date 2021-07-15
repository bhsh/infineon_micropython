/**
 * \file IfxFsi_reg.h
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
 * \defgroup IfxSfr_Fsi_Registers_Cfg Fsi address
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi 2-FSI
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 *
 */
#ifndef IFXFSI_REG_H
#define IFXFSI_REG_H 1
/******************************************************************************/
#include "IfxFsi_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Fsi_Registers_Cfg_BaseAddress
 * \{  */

/** \brief FSI object */
#define MODULE_FSI /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8030000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi
 * \{  */
/** \brief 4, Communication Register 1 */
#define FSI_COMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_1*)0xF8030004u)

/** \brief 5, Communication Register 2 */
#define FSI_COMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_2*)0xF8030005u)

/** \brief 6, HSM Communication Register 1 */
#define FSI_HSMCOMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_1*)0xF8030006u)

/** \brief 7, HSM Communication Register 2 */
#define FSI_HSMCOMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_2*)0xF8030007u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REG_H */

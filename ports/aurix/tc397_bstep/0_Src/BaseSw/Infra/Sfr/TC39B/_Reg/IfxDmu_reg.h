/**
 * \file IfxDmu_reg.h
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
 * \defgroup IfxSfr_Dmu_Registers_Cfg Dmu address
 * \ingroup IfxSfr_Dmu_Registers
 * 
 * \defgroup IfxSfr_Dmu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Dmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Dmu_Registers_Cfg_Dmu 2-DMU
 * \ingroup IfxSfr_Dmu_Registers_Cfg
 *
 *
 */
#ifndef IFXDMU_REG_H
#define IFXDMU_REG_H 1
/******************************************************************************/
#include "IfxDmu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Dmu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief DMU object */
#define MODULE_DMU /*lint --e(923, 9078)*/ ((*(Ifx_DMU*)0xF8040000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Dmu_Registers_Cfg_Dmu
 * \{  */
/** \brief 8, Module Identification Register */
#define DMU_HF_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ID*)0xF8040008u)

/** \brief 10, Flash Status Register */
#define DMU_HF_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_STATUS*)0xF8040010u)

/** \brief 14, Flash Control Register */
#define DMU_HF_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CONTROL*)0xF8040014u)

/** \brief 18, Flash Operation Register */
#define DMU_HF_OPERATION /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_OPERATION*)0xF8040018u)

/** \brief 1C, Flash Protection Status Register */
#define DMU_HF_PROTECT /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROTECT*)0xF804001Cu)

/** \brief 20, Flash Confirm Status Register 0 */
#define DMU_HF_CONFIRM0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CONFIRM0*)0xF8040020u)

/** \brief 24, Flash Confirm Status Register 1 */
#define DMU_HF_CONFIRM1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CONFIRM1*)0xF8040024u)

/** \brief 28, Flash Confirm Status Register 2 */
#define DMU_HF_CONFIRM2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CONFIRM2*)0xF8040028u)

/** \brief 30, Enable Error Interrupt Control Register */
#define DMU_HF_EER /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_EER*)0xF8040030u)

/** \brief 34, Error Status Register */
#define DMU_HF_ERRSR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ERRSR*)0xF8040034u)

/** \brief 38, Clear Error Register */
#define DMU_HF_CLRE /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CLRE*)0xF8040038u)

/** \brief 40, DF0 ECC Read Register */
#define DMU_HF_ECCR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ECCR*)0xF8040040u)

/** \brief 44, DF0 ECC Status Register */
#define DMU_HF_ECCS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ECCS*)0xF8040044u)

/** \brief 48, DF0 ECC Control Register */
#define DMU_HF_ECCC /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ECCC*)0xF8040048u)

/** \brief 4C, DF0 ECC Write Register */
#define DMU_HF_ECCW /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ECCW*)0xF804004Cu)

/** \brief 50, Cranking Control Register */
#define DMU_HF_CCONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_CCONTROL*)0xF8040050u)

/** \brief 60, Power Status Register */
#define DMU_HF_PSTATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PSTATUS*)0xF8040060u)

/** \brief 64, Power Control Register */
#define DMU_HF_PCONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PCONTROL*)0xF8040064u)

/** \brief 68, PFLASH Wait Cycle Register */
#define DMU_HF_PWAIT /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PWAIT*)0xF8040068u)

/** \brief 6C, DFLASH Wait Cycle Register */
#define DMU_HF_DWAIT /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_DWAIT*)0xF804006Cu)

/** \brief 74, DF0 User Mode Control */
#define DMU_HF_PROCONUSR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONUSR*)0xF8040074u)

/** \brief 80, PFLASH Protection Configuration */
#define DMU_HF_PROCONPF /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONPF*)0xF8040080u)

/** \brief 84, Tuning Protection Configuration */
#define DMU_HF_PROCONTP /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONTP*)0xF8040084u)

/** \brief 88, DFLASH Protection Configuration */
#define DMU_HF_PROCONDF /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONDF*)0xF8040088u)

/** \brief 8C, RAM Configuration */
#define DMU_HF_PROCONRAM /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONRAM*)0xF804008Cu)

/** \brief 90, Debug Interface Protection Configuration */
#define DMU_HF_PROCONDBG /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_PROCONDBG*)0xF8040090u)

/** \brief F0, Suspend Control Register */
#define DMU_HF_SUSPEND /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_SUSPEND*)0xF80400F0u)

/** \brief F4, Margin Control Register */
#define DMU_HF_MARGIN /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_MARGIN*)0xF80400F4u)

/** \brief F8, Access Enable Register 1 */
#define DMU_HF_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ACCEN1*)0xF80400F8u)

/** \brief FC, Access Enable Register 0 */
#define DMU_HF_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HF_ACCEN0*)0xF80400FCu)

/** \brief 10000, PFLASH Bank 0 Protection Configuration 0 */
#define DMU_HP0_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050000u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P0.
* To use register names with standard convension, please use DMU_HP0_PROCON_P0.
*/
#define DMU_HP_PROCONP00 (DMU_HP0_PROCON_P0)

/** \brief 10004, PFLASH Bank 0 Protection Configuration 1 */
#define DMU_HP0_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050004u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P1.
* To use register names with standard convension, please use DMU_HP0_PROCON_P1.
*/
#define DMU_HP_PROCONP01 (DMU_HP0_PROCON_P1)

/** \brief 10008, PFLASH Bank 0 Protection Configuration 2 */
#define DMU_HP0_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050008u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P2.
* To use register names with standard convension, please use DMU_HP0_PROCON_P2.
*/
#define DMU_HP_PROCONP02 (DMU_HP0_PROCON_P2)

/** \brief 1000C, PFLASH Bank 0 Protection Configuration 3 */
#define DMU_HP0_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805000Cu)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P3.
* To use register names with standard convension, please use DMU_HP0_PROCON_P3.
*/
#define DMU_HP_PROCONP03 (DMU_HP0_PROCON_P3)

/** \brief 10010, PFLASH Bank 0 Protection Configuration 4 */
#define DMU_HP0_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050010u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P4.
* To use register names with standard convension, please use DMU_HP0_PROCON_P4.
*/
#define DMU_HP_PROCONP04 (DMU_HP0_PROCON_P4)

/** \brief 10014, PFLASH Bank 0 Protection Configuration 5 */
#define DMU_HP0_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050014u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_P5.
* To use register names with standard convension, please use DMU_HP0_PROCON_P5.
*/
#define DMU_HP_PROCONP05 (DMU_HP0_PROCON_P5)

/** \brief 10040, PFLASH Bank 0 OTP Protection Configuration 0 */
#define DMU_HP0_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050040u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP00 (DMU_HP0_PROCON_OTP0)

/** \brief 10044, PFLASH Bank 0 OTP Protection Configuration 1 */
#define DMU_HP0_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050044u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP01 (DMU_HP0_PROCON_OTP1)

/** \brief 10048, PFLASH Bank 0 OTP Protection Configuration 2 */
#define DMU_HP0_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050048u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP02 (DMU_HP0_PROCON_OTP2)

/** \brief 1004C, PFLASH Bank 0 OTP Protection Configuration 3 */
#define DMU_HP0_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805004Cu)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP03 (DMU_HP0_PROCON_OTP3)

/** \brief 10050, PFLASH Bank 0 OTP Protection Configuration 4 */
#define DMU_HP0_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050050u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP04 (DMU_HP0_PROCON_OTP4)

/** \brief 10054, PFLASH Bank 0 OTP Protection Configuration 5 */
#define DMU_HP0_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050054u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP0_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP05 (DMU_HP0_PROCON_OTP5)

/** \brief 10080, PFLASH Bank 0 WOP Configuration 0 */
#define DMU_HP0_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050080u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP00 (DMU_HP0_PROCON_WOP0)

/** \brief 10084, PFLASH Bank 0 WOP Configuration 1 */
#define DMU_HP0_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050084u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP01 (DMU_HP0_PROCON_WOP1)

/** \brief 10088, PFLASH Bank 0 WOP Configuration 2 */
#define DMU_HP0_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050088u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP02 (DMU_HP0_PROCON_WOP2)

/** \brief 1008C, PFLASH Bank 0 WOP Configuration 3 */
#define DMU_HP0_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805008Cu)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP03 (DMU_HP0_PROCON_WOP3)

/** \brief 10090, PFLASH Bank 0 WOP Configuration 4 */
#define DMU_HP0_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050090u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP04 (DMU_HP0_PROCON_WOP4)

/** \brief 10094, PFLASH Bank 0 WOP Configuration 5 */
#define DMU_HP0_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050094u)
/** Alias (User Manual Name) for DMU_HP0_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP0_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP05 (DMU_HP0_PROCON_WOP5)

/** \brief 100A0, PFLASH Bank 0 Erase Counter Priority configuration 0 */
#define DMU_HP0_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80500A0u)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO00 (DMU_HP0_ECPRIO_P0)

/** \brief 100A4, PFLASH Bank 0 Erase Counter Priority Configuration 1 */
#define DMU_HP0_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80500A4u)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO01 (DMU_HP0_ECPRIO_P1)

/** \brief 100A8, PFLASH Bank 0 Erase Counter Priority Configuration 2 */
#define DMU_HP0_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80500A8u)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO02 (DMU_HP0_ECPRIO_P2)

/** \brief 100AC, PFLASH Bank 0 Erase Counter Priority Configuration 3 */
#define DMU_HP0_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80500ACu)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO03 (DMU_HP0_ECPRIO_P3)

/** \brief 100B0, PFLASH Bank 0 Erase Counter Priority Configuration 4 */
#define DMU_HP0_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80500B0u)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO04 (DMU_HP0_ECPRIO_P4)

/** \brief 100B4, PFLASH Bank 0 Erase Counter Priority Configuration 5 */
#define DMU_HP0_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80500B4u)
/** Alias (User Manual Name) for DMU_HP0_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP0_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO05 (DMU_HP0_ECPRIO_P5)

/** \brief 10100, PFLASH Bank 1 Protection Configuration 0 */
#define DMU_HP1_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050100u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P0.
* To use register names with standard convension, please use DMU_HP1_PROCON_P0.
*/
#define DMU_HP_PROCONP10 (DMU_HP1_PROCON_P0)

/** \brief 10104, PFLASH Bank 1 Protection Configuration 1 */
#define DMU_HP1_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050104u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P1.
* To use register names with standard convension, please use DMU_HP1_PROCON_P1.
*/
#define DMU_HP_PROCONP11 (DMU_HP1_PROCON_P1)

/** \brief 10108, PFLASH Bank 1 Protection Configuration 2 */
#define DMU_HP1_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050108u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P2.
* To use register names with standard convension, please use DMU_HP1_PROCON_P2.
*/
#define DMU_HP_PROCONP12 (DMU_HP1_PROCON_P2)

/** \brief 1010C, PFLASH Bank 1 Protection Configuration 3 */
#define DMU_HP1_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805010Cu)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P3.
* To use register names with standard convension, please use DMU_HP1_PROCON_P3.
*/
#define DMU_HP_PROCONP13 (DMU_HP1_PROCON_P3)

/** \brief 10110, PFLASH Bank 1 Protection Configuration 4 */
#define DMU_HP1_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050110u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P4.
* To use register names with standard convension, please use DMU_HP1_PROCON_P4.
*/
#define DMU_HP_PROCONP14 (DMU_HP1_PROCON_P4)

/** \brief 10114, PFLASH Bank 1 Protection Configuration 5 */
#define DMU_HP1_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050114u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_P5.
* To use register names with standard convension, please use DMU_HP1_PROCON_P5.
*/
#define DMU_HP_PROCONP15 (DMU_HP1_PROCON_P5)

/** \brief 10140, PFLASH Bank 1 OTP Protection Configuration 0 */
#define DMU_HP1_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050140u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP10 (DMU_HP1_PROCON_OTP0)

/** \brief 10144, PFLASH Bank 1 OTP Protection Configuration 1 */
#define DMU_HP1_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050144u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP11 (DMU_HP1_PROCON_OTP1)

/** \brief 10148, PFLASH Bank 1 OTP Protection Configuration 2 */
#define DMU_HP1_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050148u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP12 (DMU_HP1_PROCON_OTP2)

/** \brief 1014C, PFLASH Bank 1 OTP Protection Configuration 3 */
#define DMU_HP1_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805014Cu)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP13 (DMU_HP1_PROCON_OTP3)

/** \brief 10150, PFLASH Bank 1 OTP Protection Configuration 4 */
#define DMU_HP1_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050150u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP14 (DMU_HP1_PROCON_OTP4)

/** \brief 10154, PFLASH Bank 1 OTP Protection Configuration 5 */
#define DMU_HP1_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050154u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP1_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP15 (DMU_HP1_PROCON_OTP5)

/** \brief 10180, PFLASH Bank 1 WOP Configuration 0 */
#define DMU_HP1_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050180u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP10 (DMU_HP1_PROCON_WOP0)

/** \brief 10184, PFLASH Bank 1 WOP Configuration 1 */
#define DMU_HP1_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050184u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP11 (DMU_HP1_PROCON_WOP1)

/** \brief 10188, PFLASH Bank 1 WOP Configuration 2 */
#define DMU_HP1_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050188u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP12 (DMU_HP1_PROCON_WOP2)

/** \brief 1018C, PFLASH Bank 1 WOP Configuration 3 */
#define DMU_HP1_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805018Cu)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP13 (DMU_HP1_PROCON_WOP3)

/** \brief 10190, PFLASH Bank 1 WOP Configuration 4 */
#define DMU_HP1_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050190u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP14 (DMU_HP1_PROCON_WOP4)

/** \brief 10194, PFLASH Bank 1 WOP Configuration 5 */
#define DMU_HP1_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050194u)
/** Alias (User Manual Name) for DMU_HP1_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP1_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP15 (DMU_HP1_PROCON_WOP5)

/** \brief 101A0, PFLASH Bank 1 Erase Counter Priority configuration 0 */
#define DMU_HP1_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80501A0u)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO10 (DMU_HP1_ECPRIO_P0)

/** \brief 101A4, PFLASH Bank 1 Erase Counter Priority Configuration 1 */
#define DMU_HP1_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80501A4u)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO11 (DMU_HP1_ECPRIO_P1)

/** \brief 101A8, PFLASH Bank 1 Erase Counter Priority Configuration 2 */
#define DMU_HP1_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80501A8u)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO12 (DMU_HP1_ECPRIO_P2)

/** \brief 101AC, PFLASH Bank 1 Erase Counter Priority Configuration 3 */
#define DMU_HP1_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80501ACu)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO13 (DMU_HP1_ECPRIO_P3)

/** \brief 101B0, PFLASH Bank 1 Erase Counter Priority Configuration 4 */
#define DMU_HP1_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80501B0u)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO14 (DMU_HP1_ECPRIO_P4)

/** \brief 101B4, PFLASH Bank 1 Erase Counter Priority Configuration 5 */
#define DMU_HP1_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80501B4u)
/** Alias (User Manual Name) for DMU_HP1_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP1_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO15 (DMU_HP1_ECPRIO_P5)

/** \brief 10200, PFLASH Bank 2 Protection Configuration 0 */
#define DMU_HP2_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050200u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P0.
* To use register names with standard convension, please use DMU_HP2_PROCON_P0.
*/
#define DMU_HP_PROCONP20 (DMU_HP2_PROCON_P0)

/** \brief 10204, PFLASH Bank 2 Protection Configuration 1 */
#define DMU_HP2_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050204u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P1.
* To use register names with standard convension, please use DMU_HP2_PROCON_P1.
*/
#define DMU_HP_PROCONP21 (DMU_HP2_PROCON_P1)

/** \brief 10208, PFLASH Bank 2 Protection Configuration 2 */
#define DMU_HP2_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050208u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P2.
* To use register names with standard convension, please use DMU_HP2_PROCON_P2.
*/
#define DMU_HP_PROCONP22 (DMU_HP2_PROCON_P2)

/** \brief 1020C, PFLASH Bank 2 Protection Configuration 3 */
#define DMU_HP2_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805020Cu)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P3.
* To use register names with standard convension, please use DMU_HP2_PROCON_P3.
*/
#define DMU_HP_PROCONP23 (DMU_HP2_PROCON_P3)

/** \brief 10210, PFLASH Bank 2 Protection Configuration 4 */
#define DMU_HP2_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050210u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P4.
* To use register names with standard convension, please use DMU_HP2_PROCON_P4.
*/
#define DMU_HP_PROCONP24 (DMU_HP2_PROCON_P4)

/** \brief 10214, PFLASH Bank 2 Protection Configuration 5 */
#define DMU_HP2_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050214u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_P5.
* To use register names with standard convension, please use DMU_HP2_PROCON_P5.
*/
#define DMU_HP_PROCONP25 (DMU_HP2_PROCON_P5)

/** \brief 10240, PFLASH Bank 2 OTP Protection Configuration 0 */
#define DMU_HP2_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050240u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP20 (DMU_HP2_PROCON_OTP0)

/** \brief 10244, PFLASH Bank 2 OTP Protection Configuration 1 */
#define DMU_HP2_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050244u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP21 (DMU_HP2_PROCON_OTP1)

/** \brief 10248, PFLASH Bank 2 OTP Protection Configuration 2 */
#define DMU_HP2_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050248u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP22 (DMU_HP2_PROCON_OTP2)

/** \brief 1024C, PFLASH Bank 2 OTP Protection Configuration 3 */
#define DMU_HP2_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805024Cu)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP23 (DMU_HP2_PROCON_OTP3)

/** \brief 10250, PFLASH Bank 2 OTP Protection Configuration 4 */
#define DMU_HP2_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050250u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP24 (DMU_HP2_PROCON_OTP4)

/** \brief 10254, PFLASH Bank 2 OTP Protection Configuration 5 */
#define DMU_HP2_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050254u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP2_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP25 (DMU_HP2_PROCON_OTP5)

/** \brief 10280, PFLASH Bank 2 WOP Configuration 0 */
#define DMU_HP2_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050280u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP20 (DMU_HP2_PROCON_WOP0)

/** \brief 10284, PFLASH Bank 2 WOP Configuration 1 */
#define DMU_HP2_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050284u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP21 (DMU_HP2_PROCON_WOP1)

/** \brief 10288, PFLASH Bank 2 WOP Configuration 2 */
#define DMU_HP2_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050288u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP22 (DMU_HP2_PROCON_WOP2)

/** \brief 1028C, PFLASH Bank 2 WOP Configuration 3 */
#define DMU_HP2_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805028Cu)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP23 (DMU_HP2_PROCON_WOP3)

/** \brief 10290, PFLASH Bank 2 WOP Configuration 4 */
#define DMU_HP2_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050290u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP24 (DMU_HP2_PROCON_WOP4)

/** \brief 10294, PFLASH Bank 2 WOP Configuration 5 */
#define DMU_HP2_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050294u)
/** Alias (User Manual Name) for DMU_HP2_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP2_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP25 (DMU_HP2_PROCON_WOP5)

/** \brief 102A0, PFLASH Bank 2 Erase Counter Priority configuration 0 */
#define DMU_HP2_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80502A0u)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO20 (DMU_HP2_ECPRIO_P0)

/** \brief 102A4, PFLASH Bank 2 Erase Counter Priority Configuration 1 */
#define DMU_HP2_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80502A4u)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO21 (DMU_HP2_ECPRIO_P1)

/** \brief 102A8, PFLASH Bank 2 Erase Counter Priority Configuration 2 */
#define DMU_HP2_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80502A8u)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO22 (DMU_HP2_ECPRIO_P2)

/** \brief 102AC, PFLASH Bank 2 Erase Counter Priority Configuration 3 */
#define DMU_HP2_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80502ACu)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO23 (DMU_HP2_ECPRIO_P3)

/** \brief 102B0, PFLASH Bank 2 Erase Counter Priority Configuration 4 */
#define DMU_HP2_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80502B0u)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO24 (DMU_HP2_ECPRIO_P4)

/** \brief 102B4, PFLASH Bank 2 Erase Counter Priority Configuration 5 */
#define DMU_HP2_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80502B4u)
/** Alias (User Manual Name) for DMU_HP2_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP2_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO25 (DMU_HP2_ECPRIO_P5)

/** \brief 10300, PFLASH Bank 3 Protection Configuration 0 */
#define DMU_HP3_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050300u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P0.
* To use register names with standard convension, please use DMU_HP3_PROCON_P0.
*/
#define DMU_HP_PROCONP30 (DMU_HP3_PROCON_P0)

/** \brief 10304, PFLASH Bank 3 Protection Configuration 1 */
#define DMU_HP3_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050304u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P1.
* To use register names with standard convension, please use DMU_HP3_PROCON_P1.
*/
#define DMU_HP_PROCONP31 (DMU_HP3_PROCON_P1)

/** \brief 10308, PFLASH Bank 3 Protection Configuration 2 */
#define DMU_HP3_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050308u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P2.
* To use register names with standard convension, please use DMU_HP3_PROCON_P2.
*/
#define DMU_HP_PROCONP32 (DMU_HP3_PROCON_P2)

/** \brief 1030C, PFLASH Bank 3 Protection Configuration 3 */
#define DMU_HP3_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805030Cu)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P3.
* To use register names with standard convension, please use DMU_HP3_PROCON_P3.
*/
#define DMU_HP_PROCONP33 (DMU_HP3_PROCON_P3)

/** \brief 10310, PFLASH Bank 3 Protection Configuration 4 */
#define DMU_HP3_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050310u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P4.
* To use register names with standard convension, please use DMU_HP3_PROCON_P4.
*/
#define DMU_HP_PROCONP34 (DMU_HP3_PROCON_P4)

/** \brief 10314, PFLASH Bank 3 Protection Configuration 5 */
#define DMU_HP3_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050314u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_P5.
* To use register names with standard convension, please use DMU_HP3_PROCON_P5.
*/
#define DMU_HP_PROCONP35 (DMU_HP3_PROCON_P5)

/** \brief 10340, PFLASH Bank 3 OTP Protection Configuration 0 */
#define DMU_HP3_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050340u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP30 (DMU_HP3_PROCON_OTP0)

/** \brief 10344, PFLASH Bank 3 OTP Protection Configuration 1 */
#define DMU_HP3_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050344u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP31 (DMU_HP3_PROCON_OTP1)

/** \brief 10348, PFLASH Bank 3 OTP Protection Configuration 2 */
#define DMU_HP3_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050348u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP32 (DMU_HP3_PROCON_OTP2)

/** \brief 1034C, PFLASH Bank 3 OTP Protection Configuration 3 */
#define DMU_HP3_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805034Cu)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP33 (DMU_HP3_PROCON_OTP3)

/** \brief 10350, PFLASH Bank 3 OTP Protection Configuration 4 */
#define DMU_HP3_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050350u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP34 (DMU_HP3_PROCON_OTP4)

/** \brief 10354, PFLASH Bank 3 OTP Protection Configuration 5 */
#define DMU_HP3_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050354u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP3_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP35 (DMU_HP3_PROCON_OTP5)

/** \brief 10380, PFLASH Bank 3 WOP Configuration 0 */
#define DMU_HP3_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050380u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP30 (DMU_HP3_PROCON_WOP0)

/** \brief 10384, PFLASH Bank 3 WOP Configuration 1 */
#define DMU_HP3_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050384u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP31 (DMU_HP3_PROCON_WOP1)

/** \brief 10388, PFLASH Bank 3 WOP Configuration 2 */
#define DMU_HP3_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050388u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP32 (DMU_HP3_PROCON_WOP2)

/** \brief 1038C, PFLASH Bank 3 WOP Configuration 3 */
#define DMU_HP3_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805038Cu)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP33 (DMU_HP3_PROCON_WOP3)

/** \brief 10390, PFLASH Bank 3 WOP Configuration 4 */
#define DMU_HP3_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050390u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP34 (DMU_HP3_PROCON_WOP4)

/** \brief 10394, PFLASH Bank 3 WOP Configuration 5 */
#define DMU_HP3_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050394u)
/** Alias (User Manual Name) for DMU_HP3_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP3_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP35 (DMU_HP3_PROCON_WOP5)

/** \brief 103A0, PFLASH Bank 3 Erase Counter Priority configuration 0 */
#define DMU_HP3_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80503A0u)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO30 (DMU_HP3_ECPRIO_P0)

/** \brief 103A4, PFLASH Bank 3 Erase Counter Priority Configuration 1 */
#define DMU_HP3_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80503A4u)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO31 (DMU_HP3_ECPRIO_P1)

/** \brief 103A8, PFLASH Bank 3 Erase Counter Priority Configuration 2 */
#define DMU_HP3_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80503A8u)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO32 (DMU_HP3_ECPRIO_P2)

/** \brief 103AC, PFLASH Bank 3 Erase Counter Priority Configuration 3 */
#define DMU_HP3_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80503ACu)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO33 (DMU_HP3_ECPRIO_P3)

/** \brief 103B0, PFLASH Bank 3 Erase Counter Priority Configuration 4 */
#define DMU_HP3_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80503B0u)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO34 (DMU_HP3_ECPRIO_P4)

/** \brief 103B4, PFLASH Bank 3 Erase Counter Priority Configuration 5 */
#define DMU_HP3_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80503B4u)
/** Alias (User Manual Name) for DMU_HP3_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP3_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO35 (DMU_HP3_ECPRIO_P5)

/** \brief 10400, PFLASH Bank 4 Protection Configuration 0 */
#define DMU_HP4_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050400u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P0.
* To use register names with standard convension, please use DMU_HP4_PROCON_P0.
*/
#define DMU_HP_PROCONP40 (DMU_HP4_PROCON_P0)

/** \brief 10404, PFLASH Bank 4 Protection Configuration 1 */
#define DMU_HP4_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050404u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P1.
* To use register names with standard convension, please use DMU_HP4_PROCON_P1.
*/
#define DMU_HP_PROCONP41 (DMU_HP4_PROCON_P1)

/** \brief 10408, PFLASH Bank 4 Protection Configuration 2 */
#define DMU_HP4_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050408u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P2.
* To use register names with standard convension, please use DMU_HP4_PROCON_P2.
*/
#define DMU_HP_PROCONP42 (DMU_HP4_PROCON_P2)

/** \brief 1040C, PFLASH Bank 4 Protection Configuration 3 */
#define DMU_HP4_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805040Cu)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P3.
* To use register names with standard convension, please use DMU_HP4_PROCON_P3.
*/
#define DMU_HP_PROCONP43 (DMU_HP4_PROCON_P3)

/** \brief 10410, PFLASH Bank 4 Protection Configuration 4 */
#define DMU_HP4_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050410u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P4.
* To use register names with standard convension, please use DMU_HP4_PROCON_P4.
*/
#define DMU_HP_PROCONP44 (DMU_HP4_PROCON_P4)

/** \brief 10414, PFLASH Bank 4 Protection Configuration 5 */
#define DMU_HP4_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050414u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_P5.
* To use register names with standard convension, please use DMU_HP4_PROCON_P5.
*/
#define DMU_HP_PROCONP45 (DMU_HP4_PROCON_P5)

/** \brief 10440, PFLASH Bank 4 OTP Protection Configuration 0 */
#define DMU_HP4_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050440u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP40 (DMU_HP4_PROCON_OTP0)

/** \brief 10444, PFLASH Bank 4 OTP Protection Configuration 1 */
#define DMU_HP4_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050444u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP41 (DMU_HP4_PROCON_OTP1)

/** \brief 10448, PFLASH Bank 4 OTP Protection Configuration 2 */
#define DMU_HP4_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050448u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP42 (DMU_HP4_PROCON_OTP2)

/** \brief 1044C, PFLASH Bank 4 OTP Protection Configuration 3 */
#define DMU_HP4_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805044Cu)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP43 (DMU_HP4_PROCON_OTP3)

/** \brief 10450, PFLASH Bank 4 OTP Protection Configuration 4 */
#define DMU_HP4_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050450u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP44 (DMU_HP4_PROCON_OTP4)

/** \brief 10454, PFLASH Bank 4 OTP Protection Configuration 5 */
#define DMU_HP4_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050454u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP4_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP45 (DMU_HP4_PROCON_OTP5)

/** \brief 10480, PFLASH Bank 4 WOP Configuration 0 */
#define DMU_HP4_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050480u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP40 (DMU_HP4_PROCON_WOP0)

/** \brief 10484, PFLASH Bank 4 WOP Configuration 1 */
#define DMU_HP4_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050484u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP41 (DMU_HP4_PROCON_WOP1)

/** \brief 10488, PFLASH Bank 4 WOP Configuration 2 */
#define DMU_HP4_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050488u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP42 (DMU_HP4_PROCON_WOP2)

/** \brief 1048C, PFLASH Bank 4 WOP Configuration 3 */
#define DMU_HP4_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805048Cu)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP43 (DMU_HP4_PROCON_WOP3)

/** \brief 10490, PFLASH Bank 4 WOP Configuration 4 */
#define DMU_HP4_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050490u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP44 (DMU_HP4_PROCON_WOP4)

/** \brief 10494, PFLASH Bank 4 WOP Configuration 5 */
#define DMU_HP4_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050494u)
/** Alias (User Manual Name) for DMU_HP4_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP4_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP45 (DMU_HP4_PROCON_WOP5)

/** \brief 104A0, PFLASH Bank 4 Erase Counter Priority configuration 0 */
#define DMU_HP4_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80504A0u)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO40 (DMU_HP4_ECPRIO_P0)

/** \brief 104A4, PFLASH Bank 4 Erase Counter Priority Configuration 1 */
#define DMU_HP4_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80504A4u)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO41 (DMU_HP4_ECPRIO_P1)

/** \brief 104A8, PFLASH Bank 4 Erase Counter Priority Configuration 2 */
#define DMU_HP4_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80504A8u)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO42 (DMU_HP4_ECPRIO_P2)

/** \brief 104AC, PFLASH Bank 4 Erase Counter Priority Configuration 3 */
#define DMU_HP4_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80504ACu)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO43 (DMU_HP4_ECPRIO_P3)

/** \brief 104B0, PFLASH Bank 4 Erase Counter Priority Configuration 4 */
#define DMU_HP4_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80504B0u)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO44 (DMU_HP4_ECPRIO_P4)

/** \brief 104B4, PFLASH Bank 4 Erase Counter Priority Configuration 5 */
#define DMU_HP4_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80504B4u)
/** Alias (User Manual Name) for DMU_HP4_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP4_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO45 (DMU_HP4_ECPRIO_P5)

/** \brief 10500, PFLASH Bank 5 Protection Configuration 0 */
#define DMU_HP5_PROCON_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P0*)0xF8050500u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P0.
* To use register names with standard convension, please use DMU_HP5_PROCON_P0.
*/
#define DMU_HP_PROCONP50 (DMU_HP5_PROCON_P0)

/** \brief 10504, PFLASH Bank 5 Protection Configuration 1 */
#define DMU_HP5_PROCON_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P1*)0xF8050504u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P1.
* To use register names with standard convension, please use DMU_HP5_PROCON_P1.
*/
#define DMU_HP_PROCONP51 (DMU_HP5_PROCON_P1)

/** \brief 10508, PFLASH Bank 5 Protection Configuration 2 */
#define DMU_HP5_PROCON_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P2*)0xF8050508u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P2.
* To use register names with standard convension, please use DMU_HP5_PROCON_P2.
*/
#define DMU_HP_PROCONP52 (DMU_HP5_PROCON_P2)

/** \brief 1050C, PFLASH Bank 5 Protection Configuration 3 */
#define DMU_HP5_PROCON_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P3*)0xF805050Cu)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P3.
* To use register names with standard convension, please use DMU_HP5_PROCON_P3.
*/
#define DMU_HP_PROCONP53 (DMU_HP5_PROCON_P3)

/** \brief 10510, PFLASH Bank 5 Protection Configuration 4 */
#define DMU_HP5_PROCON_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P4*)0xF8050510u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P4.
* To use register names with standard convension, please use DMU_HP5_PROCON_P4.
*/
#define DMU_HP_PROCONP54 (DMU_HP5_PROCON_P4)

/** \brief 10514, PFLASH Bank 5 Protection Configuration 5 */
#define DMU_HP5_PROCON_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_P5*)0xF8050514u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_P5.
* To use register names with standard convension, please use DMU_HP5_PROCON_P5.
*/
#define DMU_HP_PROCONP55 (DMU_HP5_PROCON_P5)

/** \brief 10540, PFLASH Bank 5 OTP Protection Configuration 0 */
#define DMU_HP5_PROCON_OTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP0*)0xF8050540u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP0.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP0.
*/
#define DMU_HP_PROCONOTP50 (DMU_HP5_PROCON_OTP0)

/** \brief 10544, PFLASH Bank 5 OTP Protection Configuration 1 */
#define DMU_HP5_PROCON_OTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP1*)0xF8050544u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP1.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP1.
*/
#define DMU_HP_PROCONOTP51 (DMU_HP5_PROCON_OTP1)

/** \brief 10548, PFLASH Bank 5 OTP Protection Configuration 2 */
#define DMU_HP5_PROCON_OTP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP2*)0xF8050548u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP2.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP2.
*/
#define DMU_HP_PROCONOTP52 (DMU_HP5_PROCON_OTP2)

/** \brief 1054C, PFLASH Bank 5 OTP Protection Configuration 3 */
#define DMU_HP5_PROCON_OTP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP3*)0xF805054Cu)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP3.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP3.
*/
#define DMU_HP_PROCONOTP53 (DMU_HP5_PROCON_OTP3)

/** \brief 10550, PFLASH Bank 5 OTP Protection Configuration 4 */
#define DMU_HP5_PROCON_OTP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP4*)0xF8050550u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP4.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP4.
*/
#define DMU_HP_PROCONOTP54 (DMU_HP5_PROCON_OTP4)

/** \brief 10554, PFLASH Bank 5 OTP Protection Configuration 5 */
#define DMU_HP5_PROCON_OTP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_OTP5*)0xF8050554u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_OTP5.
* To use register names with standard convension, please use DMU_HP5_PROCON_OTP5.
*/
#define DMU_HP_PROCONOTP55 (DMU_HP5_PROCON_OTP5)

/** \brief 10580, PFLASH Bank 5 WOP Configuration 0 */
#define DMU_HP5_PROCON_WOP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP0*)0xF8050580u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP0.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP0.
*/
#define DMU_HP_PROCONWOP50 (DMU_HP5_PROCON_WOP0)

/** \brief 10584, PFLASH Bank 5 WOP Configuration 1 */
#define DMU_HP5_PROCON_WOP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP1*)0xF8050584u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP1.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP1.
*/
#define DMU_HP_PROCONWOP51 (DMU_HP5_PROCON_WOP1)

/** \brief 10588, PFLASH Bank 5 WOP Configuration 2 */
#define DMU_HP5_PROCON_WOP2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP2*)0xF8050588u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP2.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP2.
*/
#define DMU_HP_PROCONWOP52 (DMU_HP5_PROCON_WOP2)

/** \brief 1058C, PFLASH Bank 5 WOP Configuration 3 */
#define DMU_HP5_PROCON_WOP3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP3*)0xF805058Cu)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP3.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP3.
*/
#define DMU_HP_PROCONWOP53 (DMU_HP5_PROCON_WOP3)

/** \brief 10590, PFLASH Bank 5 WOP Configuration 4 */
#define DMU_HP5_PROCON_WOP4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP4*)0xF8050590u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP4.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP4.
*/
#define DMU_HP_PROCONWOP54 (DMU_HP5_PROCON_WOP4)

/** \brief 10594, PFLASH Bank 5 WOP Configuration 5 */
#define DMU_HP5_PROCON_WOP5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_PROCON_WOP5*)0xF8050594u)
/** Alias (User Manual Name) for DMU_HP5_PROCON_WOP5.
* To use register names with standard convension, please use DMU_HP5_PROCON_WOP5.
*/
#define DMU_HP_PROCONWOP55 (DMU_HP5_PROCON_WOP5)

/** \brief 105A0, PFLASH Bank 5 Erase Counter Priority configuration 0 */
#define DMU_HP5_ECPRIO_P0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P0*)0xF80505A0u)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P0.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P0.
*/
#define DMU_HP_ECPRIO50 (DMU_HP5_ECPRIO_P0)

/** \brief 105A4, PFLASH Bank 5 Erase Counter Priority Configuration 1 */
#define DMU_HP5_ECPRIO_P1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P1*)0xF80505A4u)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P1.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P1.
*/
#define DMU_HP_ECPRIO51 (DMU_HP5_ECPRIO_P1)

/** \brief 105A8, PFLASH Bank 5 Erase Counter Priority Configuration 2 */
#define DMU_HP5_ECPRIO_P2 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P2*)0xF80505A8u)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P2.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P2.
*/
#define DMU_HP_ECPRIO52 (DMU_HP5_ECPRIO_P2)

/** \brief 105AC, PFLASH Bank 5 Erase Counter Priority Configuration 3 */
#define DMU_HP5_ECPRIO_P3 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P3*)0xF80505ACu)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P3.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P3.
*/
#define DMU_HP_ECPRIO53 (DMU_HP5_ECPRIO_P3)

/** \brief 105B0, PFLASH Bank 5 Erase Counter Priority Configuration 4 */
#define DMU_HP5_ECPRIO_P4 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P4*)0xF80505B0u)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P4.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P4.
*/
#define DMU_HP_ECPRIO54 (DMU_HP5_ECPRIO_P4)

/** \brief 105B4, PFLASH Bank 5 Erase Counter Priority Configuration 5 */
#define DMU_HP5_ECPRIO_P5 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_HP_ECPRIO_P5*)0xF80505B4u)
/** Alias (User Manual Name) for DMU_HP5_ECPRIO_P5.
* To use register names with standard convension, please use DMU_HP5_ECPRIO_P5.
*/
#define DMU_HP_ECPRIO55 (DMU_HP5_ECPRIO_P5)

/** \brief 20010, HSM Flash Status Register */
#define DMU_SF_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_STATUS*)0xF8060010u)

/** \brief 20014, HSM Flash Configuration Register */
#define DMU_SF_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_CONTROL*)0xF8060014u)

/** \brief 20018, HSM Flash Operation Register */
#define DMU_SF_OPERATION /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_OPERATION*)0xF8060018u)

/** \brief 20030, HSM Enable Error Interrupt Control Register */
#define DMU_SF_EER /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_EER*)0xF8060030u)

/** \brief 20034, HSM Error Status Register */
#define DMU_SF_ERRSR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_ERRSR*)0xF8060034u)

/** \brief 20038, HSM Clear Error Register */
#define DMU_SF_CLRE /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_CLRE*)0xF8060038u)

/** \brief 20040, HSM DF1 ECC Read Register */
#define DMU_SF_ECCR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_ECCR*)0xF8060040u)

/** \brief 20044, HSM DF1 ECC Status Register */
#define DMU_SF_ECCS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_ECCS*)0xF8060044u)

/** \brief 20048, HSM DF1 ECC Control Register */
#define DMU_SF_ECCC /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_ECCC*)0xF8060048u)

/** \brief 2004C, HSM DF1 ECC Write Register */
#define DMU_SF_ECCW /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_ECCW*)0xF806004Cu)

/** \brief 20074, HSM DF1 User Mode Control */
#define DMU_SF_PROCONUSR /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_PROCONUSR*)0xF8060074u)

/** \brief 200E8, HSM Suspend Control Register */
#define DMU_SF_SUSPEND /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_SUSPEND*)0xF80600E8u)

/** \brief 200EC, HSM DF1 Margin Control Register */
#define DMU_SF_MARGIN /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SF_MARGIN*)0xF80600ECu)

/** \brief 30000, HSM Protection Configuration */
#define DMU_SP_PROCONHSMCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCFG*)0xF8070000u)

/** \brief 30004, HSM Code Boot Sector */
#define DMU_SP_PROCONHSMCBS /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCBS*)0xF8070004u)

/** \brief 30008, HSM Code Exclusive Protection Configuration */
#define DMU_SP_PROCONHSMCX0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCX0*)0xF8070008u)

/** \brief 3000C, HSM Code Exclusive Protection Configuration */
#define DMU_SP_PROCONHSMCX1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCX1*)0xF807000Cu)

/** \brief 30010, HSM Code OTP Protection Configuration */
#define DMU_SP_PROCONHSMCOTP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCOTP0*)0xF8070010u)

/** \brief 30014, HSM Code OTP Protection Configuration */
#define DMU_SP_PROCONHSMCOTP1 /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSMCOTP1*)0xF8070014u)

/** \brief 30040, HSM Interface Protection Configuration */
#define DMU_SP_PROCONHSM /*lint --e(923, 9078)*/ (*(volatile Ifx_DMU_SP_PROCONHSM*)0xF8070040u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXDMU_REG_H */

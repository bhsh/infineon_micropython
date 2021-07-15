/**
 * \file IfxDom_regdef.h
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
 * \defgroup IfxSfr_Dom_Registers Dom Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Dom_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Dom_Registers
 * 
 * \defgroup IfxSfr_Dom_Registers_union Register unions
 * \ingroup IfxSfr_Dom_Registers
 * 
 * \defgroup IfxSfr_Dom_Registers_struct Memory map
 * \ingroup IfxSfr_Dom_Registers
 */
#ifndef IFXDOM_REGDEF_H
#define IFXDOM_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Dom_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_DOM_ACCEN0_Bits
{
    Ifx_Strict_32Bit EN0:1;           /**< \brief [0:0] Access Enable for Master TAG ID 0 - EN0 (rw) */
    Ifx_Strict_32Bit EN1:1;           /**< \brief [1:1] Access Enable for Master TAG ID 1 - EN1 (rw) */
    Ifx_Strict_32Bit EN2:1;           /**< \brief [2:2] Access Enable for Master TAG ID 2 - EN2 (rw) */
    Ifx_Strict_32Bit EN3:1;           /**< \brief [3:3] Access Enable for Master TAG ID 3 - EN3 (rw) */
    Ifx_Strict_32Bit EN4:1;           /**< \brief [4:4] Access Enable for Master TAG ID 4 - EN4 (rw) */
    Ifx_Strict_32Bit EN5:1;           /**< \brief [5:5] Access Enable for Master TAG ID 5 - EN5 (rw) */
    Ifx_Strict_32Bit EN6:1;           /**< \brief [6:6] Access Enable for Master TAG ID 6 - EN6 (rw) */
    Ifx_Strict_32Bit EN7:1;           /**< \brief [7:7] Access Enable for Master TAG ID 7 - EN7 (rw) */
    Ifx_Strict_32Bit EN8:1;           /**< \brief [8:8] Access Enable for Master TAG ID 8 - EN8 (rw) */
    Ifx_Strict_32Bit EN9:1;           /**< \brief [9:9] Access Enable for Master TAG ID 9 - EN9 (rw) */
    Ifx_Strict_32Bit EN10:1;          /**< \brief [10:10] Access Enable for Master TAG ID 10 - EN10 (rw) */
    Ifx_Strict_32Bit EN11:1;          /**< \brief [11:11] Access Enable for Master TAG ID 11 - EN11 (rw) */
    Ifx_Strict_32Bit EN12:1;          /**< \brief [12:12] Access Enable for Master TAG ID 12 - EN12 (rw) */
    Ifx_Strict_32Bit EN13:1;          /**< \brief [13:13] Access Enable for Master TAG ID 13 - EN13 (rw) */
    Ifx_Strict_32Bit EN14:1;          /**< \brief [14:14] Access Enable for Master TAG ID 14 - EN14 (rw) */
    Ifx_Strict_32Bit EN15:1;          /**< \brief [15:15] Access Enable for Master TAG ID 15 - EN15 (rw) */
    Ifx_Strict_32Bit EN16:1;          /**< \brief [16:16] Access Enable for Master TAG ID 16 - EN16 (rw) */
    Ifx_Strict_32Bit EN17:1;          /**< \brief [17:17] Access Enable for Master TAG ID 17 - EN17 (rw) */
    Ifx_Strict_32Bit EN18:1;          /**< \brief [18:18] Access Enable for Master TAG ID 18 - EN18 (rw) */
    Ifx_Strict_32Bit EN19:1;          /**< \brief [19:19] Access Enable for Master TAG ID 19 - EN19 (rw) */
    Ifx_Strict_32Bit EN20:1;          /**< \brief [20:20] Access Enable for Master TAG ID 20 - EN20 (rw) */
    Ifx_Strict_32Bit EN21:1;          /**< \brief [21:21] Access Enable for Master TAG ID 21 - EN21 (rw) */
    Ifx_Strict_32Bit EN22:1;          /**< \brief [22:22] Access Enable for Master TAG ID 22 - EN22 (rw) */
    Ifx_Strict_32Bit EN23:1;          /**< \brief [23:23] Access Enable for Master TAG ID 23 - EN23 (rw) */
    Ifx_Strict_32Bit EN24:1;          /**< \brief [24:24] Access Enable for Master TAG ID 24 - EN24 (rw) */
    Ifx_Strict_32Bit EN25:1;          /**< \brief [25:25] Access Enable for Master TAG ID 25 - EN25 (rw) */
    Ifx_Strict_32Bit EN26:1;          /**< \brief [26:26] Access Enable for Master TAG ID 26 - EN26 (rw) */
    Ifx_Strict_32Bit EN27:1;          /**< \brief [27:27] Access Enable for Master TAG ID 27 - EN27 (rw) */
    Ifx_Strict_32Bit EN28:1;          /**< \brief [28:28] Access Enable for Master TAG ID 28 - EN28 (rw) */
    Ifx_Strict_32Bit EN29:1;          /**< \brief [29:29] Access Enable for Master TAG ID 29 - EN29 (rw) */
    Ifx_Strict_32Bit EN30:1;          /**< \brief [30:30] Access Enable for Master TAG ID 30 - EN30 (rw) */
    Ifx_Strict_32Bit EN31:1;          /**< \brief [31:31] Access Enable for Master TAG ID 31 - EN31 (rw) */
} Ifx_DOM_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_DOM_ACCEN1_Bits
{
    Ifx_Strict_32Bit reserved_0:32;    /**< \brief [31:0] \internal Reserved */
} Ifx_DOM_ACCEN1_Bits;

/** \brief Bridge Control Register */
typedef struct _Ifx_DOM_BRCON_Bits
{
    Ifx_Strict_32Bit OLDAEN:1;        /**< \brief [0:0] Online Data Acquisition Enable - OLDAEN (rw) */
    Ifx_Strict_32Bit reserved_1:31;    /**< \brief [31:1] \internal Reserved */
} Ifx_DOM_BRCON_Bits;

/** \brief Identification Register */
typedef struct _Ifx_DOM_ID_Bits
{
    Ifx_Strict_32Bit MOD_REV:8;       /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_Strict_32Bit MOD_TYPE:8;      /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_Strict_32Bit MOD_NUMBER:16;    /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_DOM_ID_Bits;

/** \brief Protocol Error Status Register */
typedef struct _Ifx_DOM_PESTAT_Bits
{
    Ifx_Strict_32Bit reserved_0:16;    /**< \brief [15:0] \internal Reserved */
    Ifx_Strict_32Bit PESCI0:1;        /**< \brief [16:16] Protocol Error status of SCI0 - PESCI0 (rwh) */
    Ifx_Strict_32Bit PESCI1:1;        /**< \brief [17:17] Protocol Error status of SCI1 - PESCI1 (rwh) */
    Ifx_Strict_32Bit PESCI2:1;        /**< \brief [18:18] Protocol Error status of SCI2 - PESCI2 (rwh) */
    Ifx_Strict_32Bit PESCI3:1;        /**< \brief [19:19] Protocol Error status of SCI3 - PESCI3 (rwh) */
    Ifx_Strict_32Bit PESCI4:1;        /**< \brief [20:20] Protocol Error status of SCI4 - PESCI4 (rwh) */
    Ifx_Strict_32Bit PESCI5:1;        /**< \brief [21:21] Protocol Error status of SCI5 - PESCI5 (rwh) */
    Ifx_Strict_32Bit PESCI6:1;        /**< \brief [22:22] Protocol Error status of SCI6 - PESCI6 (rwh) */
    Ifx_Strict_32Bit PESCI7:1;        /**< \brief [23:23] Protocol Error status of SCI7 - PESCI7 (rwh) */
    Ifx_Strict_32Bit PESCI8:1;        /**< \brief [24:24] Protocol Error status of SCI8 - PESCI8 (rwh) */
    Ifx_Strict_32Bit PESCI9:1;        /**< \brief [25:25] Protocol Error status of SCI9 - PESCI9 (rwh) */
    Ifx_Strict_32Bit PESCI10:1;       /**< \brief [26:26] Protocol Error status of SCI10 - PESCI10 (rwh) */
    Ifx_Strict_32Bit PESCI11:1;       /**< \brief [27:27] Protocol Error status of SCI11 - PESCI11 (rwh) */
    Ifx_Strict_32Bit PESCI12:1;       /**< \brief [28:28] Protocol Error status of SCI12 - PESCI12 (rwh) */
    Ifx_Strict_32Bit PESCI13:1;       /**< \brief [29:29] Protocol Error status of SCI13 - PESCI13 (rwh) */
    Ifx_Strict_32Bit PESCI14:1;       /**< \brief [30:30] Protocol Error status of SCI14 - PESCI14 (rwh) */
    Ifx_Strict_32Bit PESCI15:1;       /**< \brief [31:31] Protocol Error status of SCI15 - PESCI15 (rwh) */
} Ifx_DOM_PESTAT_Bits;

/** \brief SCI ${x} Error Capture Register */
typedef struct _Ifx_DOM_SCICTRL_ERR_Bits
{
    Ifx_Strict_32Bit RD_N:1;          /**< \brief [0:0] Read Status - RD (rh) */
    Ifx_Strict_32Bit WR_N:1;          /**< \brief [1:1] Write Status - WR (rh) */
    Ifx_Strict_32Bit SVM:1;           /**< \brief [2:2] Supervisor Mode Status - SVM (rh) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit OPC:4;           /**< \brief [7:4] Operation Code - OPC (rh) */
    Ifx_Strict_32Bit TR_ID:8;         /**< \brief [15:8] Transaction ID - TR_ID (rh) */
    Ifx_Strict_32Bit ADDR_EDC:8;      /**< \brief [23:16] Address Phase Error Detection Information - ADDR_EDC (rh) */
    Ifx_Strict_32Bit MCI_SBS:8;       /**< \brief [31:24] MCI Sideband Signals [7:0] - MCI_SBS (rh) */
} Ifx_DOM_SCICTRL_ERR_Bits;

/** \brief SCI ${x} Error Address Capture Register */
typedef struct _Ifx_DOM_SCICTRL_ERRADDR_Bits
{
    Ifx_Strict_32Bit ADDR:32;         /**< \brief [31:0] Transaction Address - ADDR (rh) */
} Ifx_DOM_SCICTRL_ERRADDR_Bits;

/** \brief Protocol Error Control Register ${x} */
typedef struct _Ifx_DOM_SCICTRL_PECON_Bits
{
    Ifx_Strict_32Bit PEEN:1;          /**< \brief [0:0] Protocol Error Enable - PEEN (rw) */
    Ifx_Strict_32Bit reserved_1:1;    /**< \brief [1:1] \internal Reserved */
    Ifx_Strict_32Bit SETPE:1;         /**< \brief [2:2] Set Protocol Error - SETPE (rwh) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit PEACK:1;         /**< \brief [4:4] Protocol Error Acknowledge - PEACK (rwh) */
    Ifx_Strict_32Bit reserved_5:27;    /**< \brief [31:5] \internal Reserved */
} Ifx_DOM_SCICTRL_PECON_Bits;

/** \brief SCI${x} Arbiter Priority Register */
typedef struct _Ifx_DOM_SCICTRL_PRIORITY_Bits
{
    Ifx_Strict_32Bit MCI0_P:1;        /**< \brief [0:0] MCI0 Priority - MCI0_P (rw) */
    Ifx_Strict_32Bit MCI1_P:1;        /**< \brief [1:1] MCI1 Priority - MCI1_P (rw) */
    Ifx_Strict_32Bit MCI2_P:1;        /**< \brief [2:2] MCI2 Priority - MCI2_P (rw) */
    Ifx_Strict_32Bit MCI3_P:1;        /**< \brief [3:3] MCI3 Priority - MCI3_P (rw) */
    Ifx_Strict_32Bit MCI4_P:1;        /**< \brief [4:4] MCI4 Priority - MCI4_P (rw) */
    Ifx_Strict_32Bit MCI5_P:1;        /**< \brief [5:5] MCI5 Priority - MCI5_P (rw) */
    Ifx_Strict_32Bit MCI6_P:1;        /**< \brief [6:6] MCI6 Priority - MCI6_P (rw) */
    Ifx_Strict_32Bit MCI7_P:1;        /**< \brief [7:7] MCI7 Priority - MCI7_P (rw) */
    Ifx_Strict_32Bit MCI8_P:1;        /**< \brief [8:8] MCI8 Priority - MCI8_P (rw) */
    Ifx_Strict_32Bit MCI9_P:1;        /**< \brief [9:9] MCI9 Priority - MCI9_P (rw) */
    Ifx_Strict_32Bit MCI10_P:1;       /**< \brief [10:10] MCI10 Priority - MCI10_P (rw) */
    Ifx_Strict_32Bit MCI11_P:1;       /**< \brief [11:11] MCI11 Priority - MCI11_P (rw) */
    Ifx_Strict_32Bit reserved_12:4;    /**< \brief [15:12] \internal Reserved */
    Ifx_Strict_32Bit HPRS:3;          /**< \brief [18:16] High Priority Round Share - HPRS (rw) */
    Ifx_Strict_32Bit reserved_19:13;    /**< \brief [31:19] \internal Reserved */
} Ifx_DOM_SCICTRL_PRIORITY_Bits;

/** \brief Transaction ID Enable Register */
typedef struct _Ifx_DOM_TIDEN_Bits
{
    Ifx_Strict_32Bit ENSCI0:1;        /**< \brief [0:0] E0able Transaction ID Error from SCIn - ENSCI0 (rw) */
    Ifx_Strict_32Bit ENSCI1:1;        /**< \brief [1:1] E1able Transaction ID Error from SCIn - ENSCI1 (rw) */
    Ifx_Strict_32Bit ENSCI2:1;        /**< \brief [2:2] E2able Transaction ID Error from SCIn - ENSCI2 (rw) */
    Ifx_Strict_32Bit ENSCI3:1;        /**< \brief [3:3] E3able Transaction ID Error from SCIn - ENSCI3 (rw) */
    Ifx_Strict_32Bit ENSCI4:1;        /**< \brief [4:4] E4able Transaction ID Error from SCIn - ENSCI4 (rw) */
    Ifx_Strict_32Bit ENSCI5:1;        /**< \brief [5:5] E5able Transaction ID Error from SCIn - ENSCI5 (rw) */
    Ifx_Strict_32Bit ENSCI6:1;        /**< \brief [6:6] E6able Transaction ID Error from SCIn - ENSCI6 (rw) */
    Ifx_Strict_32Bit ENSCI7:1;        /**< \brief [7:7] E7able Transaction ID Error from SCIn - ENSCI7 (rw) */
    Ifx_Strict_32Bit ENSCI8:1;        /**< \brief [8:8] E8able Transaction ID Error from SCIn - ENSCI8 (rw) */
    Ifx_Strict_32Bit ENSCI9:1;        /**< \brief [9:9] E9able Transaction ID Error from SCIn - ENSCI9 (rw) */
    Ifx_Strict_32Bit ENSCI10:1;       /**< \brief [10:10] E10able Transaction ID Error from SCIn - ENSCI10 (rw) */
    Ifx_Strict_32Bit ENSCI11:1;       /**< \brief [11:11] E11able Transaction ID Error from SCIn - ENSCI11 (rw) */
    Ifx_Strict_32Bit ENSCI12:1;       /**< \brief [12:12] E12able Transaction ID Error from SCIn - ENSCI12 (rw) */
    Ifx_Strict_32Bit ENSCI13:1;       /**< \brief [13:13] E13able Transaction ID Error from SCIn - ENSCI13 (rw) */
    Ifx_Strict_32Bit ENSCI14:1;       /**< \brief [14:14] E14able Transaction ID Error from SCIn - ENSCI14 (rw) */
    Ifx_Strict_32Bit ENSCI15:1;       /**< \brief [15:15] E15able Transaction ID Error from SCIn - ENSCI15 (rw) */
    Ifx_Strict_32Bit ENMCI0:1;        /**< \brief [16:16] E0able Transaction ID Error from MCIn - ENMCI0 (rw) */
    Ifx_Strict_32Bit ENMCI1:1;        /**< \brief [17:17] E1able Transaction ID Error from MCIn - ENMCI1 (rw) */
    Ifx_Strict_32Bit ENMCI2:1;        /**< \brief [18:18] E2able Transaction ID Error from MCIn - ENMCI2 (rw) */
    Ifx_Strict_32Bit ENMCI3:1;        /**< \brief [19:19] E3able Transaction ID Error from MCIn - ENMCI3 (rw) */
    Ifx_Strict_32Bit ENMCI4:1;        /**< \brief [20:20] E4able Transaction ID Error from MCIn - ENMCI4 (rw) */
    Ifx_Strict_32Bit ENMCI5:1;        /**< \brief [21:21] E5able Transaction ID Error from MCIn - ENMCI5 (rw) */
    Ifx_Strict_32Bit ENMCI6:1;        /**< \brief [22:22] E6able Transaction ID Error from MCIn - ENMCI6 (rw) */
    Ifx_Strict_32Bit ENMCI7:1;        /**< \brief [23:23] E7able Transaction ID Error from MCIn - ENMCI7 (rw) */
    Ifx_Strict_32Bit ENMCI8:1;        /**< \brief [24:24] E8able Transaction ID Error from MCIn - ENMCI8 (rw) */
    Ifx_Strict_32Bit ENMCI9:1;        /**< \brief [25:25] E9able Transaction ID Error from MCIn - ENMCI9 (rw) */
    Ifx_Strict_32Bit ENMCI10:1;       /**< \brief [26:26] E10able Transaction ID Error from MCIn - ENMCI10 (rw) */
    Ifx_Strict_32Bit ENMCI11:1;       /**< \brief [27:27] E11able Transaction ID Error from MCIn - ENMCI11 (rw) */
    Ifx_Strict_32Bit reserved_28:4;    /**< \brief [31:28] \internal Reserved */
} Ifx_DOM_TIDEN_Bits;

/** \brief Transaction ID Status Register */
typedef struct _Ifx_DOM_TIDSTAT_Bits
{
    Ifx_Strict_32Bit TIDSCI0:1;       /**< \brief [0:0] Tra0saction ID Error from SCIn Status - TIDSCI0 (rwh) */
    Ifx_Strict_32Bit TIDSCI1:1;       /**< \brief [1:1] Tra1saction ID Error from SCIn Status - TIDSCI1 (rwh) */
    Ifx_Strict_32Bit TIDSCI2:1;       /**< \brief [2:2] Tra2saction ID Error from SCIn Status - TIDSCI2 (rwh) */
    Ifx_Strict_32Bit TIDSCI3:1;       /**< \brief [3:3] Tra3saction ID Error from SCIn Status - TIDSCI3 (rwh) */
    Ifx_Strict_32Bit TIDSCI4:1;       /**< \brief [4:4] Tra4saction ID Error from SCIn Status - TIDSCI4 (rwh) */
    Ifx_Strict_32Bit TIDSCI5:1;       /**< \brief [5:5] Tra5saction ID Error from SCIn Status - TIDSCI5 (rwh) */
    Ifx_Strict_32Bit TIDSCI6:1;       /**< \brief [6:6] Tra6saction ID Error from SCIn Status - TIDSCI6 (rwh) */
    Ifx_Strict_32Bit TIDSCI7:1;       /**< \brief [7:7] Tra7saction ID Error from SCIn Status - TIDSCI7 (rwh) */
    Ifx_Strict_32Bit TIDSCI8:1;       /**< \brief [8:8] Tra8saction ID Error from SCIn Status - TIDSCI8 (rwh) */
    Ifx_Strict_32Bit TIDSCI9:1;       /**< \brief [9:9] Tra9saction ID Error from SCIn Status - TIDSCI9 (rwh) */
    Ifx_Strict_32Bit TIDSCI10:1;      /**< \brief [10:10] Tra10saction ID Error from SCIn Status - TIDSCI10 (rwh) */
    Ifx_Strict_32Bit TIDSCI11:1;      /**< \brief [11:11] Tra11saction ID Error from SCIn Status - TIDSCI11 (rwh) */
    Ifx_Strict_32Bit TIDSCI12:1;      /**< \brief [12:12] Tra12saction ID Error from SCIn Status - TIDSCI12 (rwh) */
    Ifx_Strict_32Bit TIDSCI13:1;      /**< \brief [13:13] Tra13saction ID Error from SCIn Status - TIDSCI13 (rwh) */
    Ifx_Strict_32Bit TIDSCI14:1;      /**< \brief [14:14] Tra14saction ID Error from SCIn Status - TIDSCI14 (rwh) */
    Ifx_Strict_32Bit TIDSCI15:1;      /**< \brief [15:15] Tra15saction ID Error from SCIn Status - TIDSCI15 (rwh) */
    Ifx_Strict_32Bit TIDMCI0:1;       /**< \brief [16:16] Tra0saction ID Error from MCIn Status - TIDMCI0 (rwh) */
    Ifx_Strict_32Bit TIDMCI1:1;       /**< \brief [17:17] Tra1saction ID Error from MCIn Status - TIDMCI1 (rwh) */
    Ifx_Strict_32Bit TIDMCI2:1;       /**< \brief [18:18] Tra2saction ID Error from MCIn Status - TIDMCI2 (rwh) */
    Ifx_Strict_32Bit TIDMCI3:1;       /**< \brief [19:19] Tra3saction ID Error from MCIn Status - TIDMCI3 (rwh) */
    Ifx_Strict_32Bit TIDMCI4:1;       /**< \brief [20:20] Tra4saction ID Error from MCIn Status - TIDMCI4 (rwh) */
    Ifx_Strict_32Bit TIDMCI5:1;       /**< \brief [21:21] Tra5saction ID Error from MCIn Status - TIDMCI5 (rwh) */
    Ifx_Strict_32Bit TIDMCI6:1;       /**< \brief [22:22] Tra6saction ID Error from MCIn Status - TIDMCI6 (rwh) */
    Ifx_Strict_32Bit TIDMCI7:1;       /**< \brief [23:23] Tra7saction ID Error from MCIn Status - TIDMCI7 (rwh) */
    Ifx_Strict_32Bit TIDMCI8:1;       /**< \brief [24:24] Tra8saction ID Error from MCIn Status - TIDMCI8 (rwh) */
    Ifx_Strict_32Bit TIDMCI9:1;       /**< \brief [25:25] Tra9saction ID Error from MCIn Status - TIDMCI9 (rwh) */
    Ifx_Strict_32Bit TIDMCI10:1;      /**< \brief [26:26] Tra10saction ID Error from MCIn Status - TIDMCI10 (rwh) */
    Ifx_Strict_32Bit TIDMCI11:1;      /**< \brief [27:27] Tra11saction ID Error from MCIn Status - TIDMCI11 (rwh) */
    Ifx_Strict_32Bit reserved_28:4;    /**< \brief [31:28] \internal Reserved */
} Ifx_DOM_TIDSTAT_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_dom_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_ACCEN0_Bits B;            /**< \brief Bitfield access */
} Ifx_DOM_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_ACCEN1_Bits B;            /**< \brief Bitfield access */
} Ifx_DOM_ACCEN1;

/** \brief Bridge Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_BRCON_Bits B;             /**< \brief Bitfield access */
} Ifx_DOM_BRCON;

/** \brief Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_DOM_ID;

/** \brief Protocol Error Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_PESTAT_Bits B;            /**< \brief Bitfield access */
} Ifx_DOM_PESTAT;

/** \brief SCI ${x} Error Capture Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_SCICTRL_ERR_Bits B;       /**< \brief Bitfield access */
} Ifx_DOM_SCICTRL_ERR;

/** \brief SCI ${x} Error Address Capture Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_SCICTRL_ERRADDR_Bits B;    /**< \brief Bitfield access */
} Ifx_DOM_SCICTRL_ERRADDR;

/** \brief Protocol Error Control Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_SCICTRL_PECON_Bits B;     /**< \brief Bitfield access */
} Ifx_DOM_SCICTRL_PECON;

/** \brief SCI${x} Arbiter Priority Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_SCICTRL_PRIORITY_Bits B;    /**< \brief Bitfield access */
} Ifx_DOM_SCICTRL_PRIORITY;

/** \brief Transaction ID Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_TIDEN_Bits B;             /**< \brief Bitfield access */
} Ifx_DOM_TIDEN;

/** \brief Transaction ID Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DOM_TIDSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_DOM_TIDSTAT;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Dom_SCICTRL_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief SCICTRL object */
typedef volatile struct _Ifx_DOM_SCICTRL
{
       Ifx_DOM_SCICTRL_PECON               PECON;                  /**< \brief 0, Protocol Error Control Register ${x}*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_DOM_SCICTRL_PRIORITY            PRIORITY;               /**< \brief 8, SCI${x} Arbiter Priority Register*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_DOM_SCICTRL_ERRADDR             ERRADDR;                /**< \brief 10, SCI ${x} Error Address Capture Register*/
       Ifx_UReg_8Bit                       reserved_14[4];         /**< \brief 14, \internal Reserved */
       Ifx_DOM_SCICTRL_ERR                 ERR;                    /**< \brief 18, SCI ${x} Error Capture Register*/
       Ifx_UReg_8Bit                       reserved_1C[4];         /**< \brief 1C, \internal Reserved */
} Ifx_DOM_SCICTRL;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Dom_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief DOM object */
typedef volatile struct _Ifx_DOM
{
       Ifx_DOM_SCICTRL                     SCICTRL[16];            /**< \brief 0, */
       Ifx_UReg_8Bit                       reserved_200[520];      /**< \brief 200, \internal Reserved */
       Ifx_DOM_ID                          ID;                     /**< \brief 408, Identification Register*/
       Ifx_UReg_8Bit                       reserved_40C[4];        /**< \brief 40C, \internal Reserved */
       Ifx_DOM_PESTAT                      PESTAT;                 /**< \brief 410, Protocol Error Status Register*/
       Ifx_UReg_8Bit                       reserved_414[4];        /**< \brief 414, \internal Reserved */
       Ifx_DOM_TIDSTAT                     TIDSTAT;                /**< \brief 418, Transaction ID Status Register*/
       Ifx_UReg_8Bit                       reserved_41C[4];        /**< \brief 41C, \internal Reserved */
       Ifx_DOM_TIDEN                       TIDEN;                  /**< \brief 420, Transaction ID Enable Register*/
       Ifx_UReg_8Bit                       reserved_424[12];       /**< \brief 424, \internal Reserved */
       Ifx_DOM_BRCON                       BRCON;                  /**< \brief 430, */
       Ifx_UReg_8Bit                       reserved_434[188];      /**< \brief 434, \internal Reserved */
       Ifx_DOM_ACCEN0                      ACCEN0;                 /**< \brief 4F0, Access Enable Register 0*/
       Ifx_UReg_8Bit                       reserved_4F4[4];        /**< \brief 4F4, \internal Reserved */
       Ifx_DOM_ACCEN1                      ACCEN1;                 /**< \brief 4F8, Access Enable Register 1*/
       Ifx_UReg_8Bit                       reserved_4FC[64260];    /**< \brief 4FC, \internal Reserved */
} Ifx_DOM;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXDOM_REGDEF_H */

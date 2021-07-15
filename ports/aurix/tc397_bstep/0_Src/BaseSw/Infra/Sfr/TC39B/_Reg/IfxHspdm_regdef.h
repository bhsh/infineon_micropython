/**
 * \file IfxHspdm_regdef.h
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
 * \defgroup IfxSfr_Hspdm_Registers Hspdm Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Hspdm_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Hspdm_Registers
 * 
 * \defgroup IfxSfr_Hspdm_Registers_union Register unions
 * \ingroup IfxSfr_Hspdm_Registers
 * 
 * \defgroup IfxSfr_Hspdm_Registers_struct Memory map
 * \ingroup IfxSfr_Hspdm_Registers
 */
#ifndef IFXHSPDM_REGDEF_H
#define IFXHSPDM_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Hspdm_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_HSPDM_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID 0 - EN0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID 1 - EN1 (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID 2 - EN2 (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID 3 - EN3 (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID 4 - EN4 (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID 5 - EN5 (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID 6 - EN6 (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID 7 - EN7 (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID 8 - EN8 (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID 9 - EN9 (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID 10 - EN10 (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID 11 - EN11 (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID 12 - EN12 (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID 13 - EN13 (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID 14 - EN14 (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID 15 - EN15 (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID 16 - EN16 (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID 17 - EN17 (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID 18 - EN18 (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID 19 - EN19 (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID 20 - EN20 (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID 21 - EN21 (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID 22 - EN22 (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID 23 - EN23 (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID 24 - EN24 (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID 25 - EN25 (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID 26 - EN26 (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID 27 - EN27 (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID 28 - EN28 (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID 29 - EN29 (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID 30 - EN30 (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID 31 - EN31 (rw) */
} Ifx_HSPDM_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_HSPDM_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_HSPDM_ACCEN1_Bits;

/** \brief ADC Trigger Register */
typedef struct _Ifx_HSPDM_ADCTG_Bits
{
    Ifx_UReg_32Bit OFFSET:16;         /**< \brief [15:0] Offset Delay from the Start of the Ramp  - OFFSET (rw) */
    Ifx_UReg_32Bit PERIOD:16;         /**< \brief [31:16] PERIOD of the ADC Trigger Signal - PERIOD (rw) */
} Ifx_HSPDM_ADCTG_Bits;

/** \brief ADC Trigger Count Register */
typedef struct _Ifx_HSPDM_ADCTGCNT_Bits
{
    Ifx_UReg_32Bit TGCNT:16;          /**< \brief [15:0] Number of Trigger Signals in a Single Ramp - TGCNT (rw) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_HSPDM_ADCTGCNT_Bits;

/** \brief RAM Buffer A Register 0 */
typedef struct _Ifx_HSPDM_BUFA0_Bits
{
    Ifx_UReg_32Bit STARTA:13;         /**< \brief [12:0] Start Address of Buffer A - STARTA (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit ENDA:13;           /**< \brief [28:16] End Address of Buffer A - ENDA (rw) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_HSPDM_BUFA0_Bits;

/** \brief RAM Buffer B Register 0 */
typedef struct _Ifx_HSPDM_BUFB0_Bits
{
    Ifx_UReg_32Bit STARTB:13;         /**< \brief [12:0] Start Address of Buffer B - STARTB (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit ENDB:13;           /**< \brief [28:16] End Address of Buffer B - ENDB (rw) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_HSPDM_BUFB0_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_HSPDM_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_HSPDM_CLC_Bits;

/** \brief Configuration Register */
typedef struct _Ifx_HSPDM_CON_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Enable Bit Streaming Block BSB 0 - EN0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Enable Bit Streaming Block BSB 1 - EN1 (rw) */
    Ifx_UReg_32Bit SM:2;              /**< \brief [3:2] Streaming Mode: Direct Shifting or Sigma-Delta Mode - SM (rw) */
    Ifx_UReg_32Bit PAC:1;             /**< \brief [4:4] PAC enable or disable - PAC (rw) */
    Ifx_UReg_32Bit ITMDIV:2;          /**< \brief [6:5] ITM divider value - ITMDIV (rw) */
    Ifx_UReg_32Bit MM:1;              /**< \brief [7:7] Memory Mode - MM (rw) */
    Ifx_UReg_32Bit RUN:1;             /**< \brief [8:8] Run bit - RUN (rh) */
    Ifx_UReg_32Bit MPOL:1;            /**< \brief [9:9] Mute Polarity - MPOL (rw) */
    Ifx_UReg_32Bit ADCTGEN:1;         /**< \brief [10:10] ADC Trigger Block enable or disable - ADCTGEN (rw) */
    Ifx_UReg_32Bit DITH:3;            /**< \brief [13:11] Dither levels  - DITHER (rw) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit RUNC:1;            /**< \brief [16:16] Run Bit Clear (w) */
    Ifx_UReg_32Bit RUNS:1;            /**< \brief [17:17] Run Bit Set (w) */
    Ifx_UReg_32Bit HREN:1;            /**< \brief [18:18] Hardware Run Signal Enable (rw) */
    Ifx_UReg_32Bit HRAE:1;            /**< \brief [19:19] Hardware Run Active Edge Selection (rw) */
    Ifx_UReg_32Bit HRSEL:1;           /**< \brief [20:20] Hardware Run Input Selection (rw) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_HSPDM_CON_Bits;

/** \brief Current Address Register */
typedef struct _Ifx_HSPDM_CURRAD_Bits
{
    Ifx_UReg_32Bit CURRAD:13;         /**< \brief [12:0] Current Address in RAM - CURRADC (rh) */
    Ifx_UReg_32Bit reserved_13:19;    /**< \brief [31:13] \internal Reserved */
} Ifx_HSPDM_CURRAD_Bits;

/** \brief Flags Register */
typedef struct _Ifx_HSPDM_FLAGS_Bits
{
    Ifx_UReg_32Bit BAS:1;             /**< \brief [0:0] Buffer A Start Flag - BAS (rh) */
    Ifx_UReg_32Bit BAE:1;             /**< \brief [1:1] Buffer A End Flag - BAE (rh) */
    Ifx_UReg_32Bit BBS:1;             /**< \brief [2:2] Buffer B Start Flag - BBS (rh) */
    Ifx_UReg_32Bit BBE:1;             /**< \brief [3:3] Buffer B End Flag - BBE (rh) */
    Ifx_UReg_32Bit M0S:1;             /**< \brief [4:4] Mute 0 start flag - M0S (rh) */
    Ifx_UReg_32Bit M0E:1;             /**< \brief [5:5] Mute 0 end Flag - M0E (rh) */
    Ifx_UReg_32Bit M1S:1;             /**< \brief [6:6] Mute 1 start flag - M1S (rh) */
    Ifx_UReg_32Bit M1E:1;             /**< \brief [7:7] Mute 1 end flag - M1E (rh) */
    Ifx_UReg_32Bit ER:1;              /**< \brief [8:8] Error RAM Overflow - ER (rh) */
    Ifx_UReg_32Bit MUTE:1;            /**< \brief [9:9] Mute signal status - MUTE (rh) */
    Ifx_UReg_32Bit reserved_10:22;    /**< \brief [31:10] \internal Reserved */
} Ifx_HSPDM_FLAGS_Bits;

/** \brief Flags Clear Register */
typedef struct _Ifx_HSPDM_FLAGSCLEAR_Bits
{
    Ifx_UReg_32Bit BAS:1;             /**< \brief [0:0] Buffer A Start Flag, Clear Bit - BAS (w) */
    Ifx_UReg_32Bit BAE:1;             /**< \brief [1:1] Buffer A End Flag, Clear Bit - BAE (w) */
    Ifx_UReg_32Bit BBS:1;             /**< \brief [2:2] Buffer B Start Flag, Clear Bit - BBS (w) */
    Ifx_UReg_32Bit BBE:1;             /**< \brief [3:3] Buffer B End Flag, Clear Bit - BBE (w) */
    Ifx_UReg_32Bit M0S:1;             /**< \brief [4:4] Mute 0 Start Flag, Clear Bit - M0S (w) */
    Ifx_UReg_32Bit M0E:1;             /**< \brief [5:5] Mute 0 End Flag, Clear Bit - M0E (w) */
    Ifx_UReg_32Bit M1S:1;             /**< \brief [6:6] Mute 1 Start Flag, Clear Bit - M1S (w) */
    Ifx_UReg_32Bit M1E:1;             /**< \brief [7:7] Mute 1 End Flag, Clear Bit - M1E (w) */
    Ifx_UReg_32Bit ER:1;              /**< \brief [8:8] Error RAM Overflow, Clear Bit - ER (w) */
    Ifx_UReg_32Bit reserved_9:23;     /**< \brief [31:9] \internal Reserved */
} Ifx_HSPDM_FLAGSCLEAR_Bits;

/** \brief Flags Enable Register */
typedef struct _Ifx_HSPDM_FLAGSEN_Bits
{
    Ifx_UReg_32Bit BAS:1;             /**< \brief [0:0] Buffer A Start, Enable Bit - BAS (rw) */
    Ifx_UReg_32Bit BAE:1;             /**< \brief [1:1] Buffer A End, Enable Bit - BAE (rw) */
    Ifx_UReg_32Bit BBS:1;             /**< \brief [2:2] Buffer B Start, Enable Bit - BBS (rw) */
    Ifx_UReg_32Bit BBE:1;             /**< \brief [3:3] Buffer B End, Enable Bit - BBE (rw) */
    Ifx_UReg_32Bit M0S:1;             /**< \brief [4:4] Mute 0 Start, Enable Bit - M0S (rw) */
    Ifx_UReg_32Bit M0E:1;             /**< \brief [5:5] Mute 0 End, Enable Bit - M0E (rw) */
    Ifx_UReg_32Bit M1S:1;             /**< \brief [6:6] Mute 1 Start, Enable Bit - M1S (rw) */
    Ifx_UReg_32Bit M1E:1;             /**< \brief [7:7] Mute 1 End, Enable Bit - M1E (rw) */
    Ifx_UReg_32Bit ER:1;              /**< \brief [8:8] Error RAM Overflow, Enable Bit - ER (rw) */
    Ifx_UReg_32Bit reserved_9:23;     /**< \brief [31:9] \internal Reserved */
} Ifx_HSPDM_FLAGSEN_Bits;

/** \brief Flags Set Register */
typedef struct _Ifx_HSPDM_FLAGSSET_Bits
{
    Ifx_UReg_32Bit BAS:1;             /**< \brief [0:0] Buffer A Start Flag, Set Bit - BAS (w) */
    Ifx_UReg_32Bit BAE:1;             /**< \brief [1:1] Buffer A End Flag, Set Bit - BAE (w) */
    Ifx_UReg_32Bit BBS:1;             /**< \brief [2:2] Buffer B Start Flag, Set Bit - BBS (w) */
    Ifx_UReg_32Bit BBE:1;             /**< \brief [3:3] Buffer B End Flag, Set Bit - BBE (w) */
    Ifx_UReg_32Bit M0S:1;             /**< \brief [4:4] Mute 0 Start Flag, Set Bit - M0S (w) */
    Ifx_UReg_32Bit M0E:1;             /**< \brief [5:5] Mute 0 End Flag, Set Bit - M0E (w) */
    Ifx_UReg_32Bit M1S:1;             /**< \brief [6:6] Mute 1 Start Flag, Set Bit - M1S (w) */
    Ifx_UReg_32Bit M1E:1;             /**< \brief [7:7] Mute 1 End Flag, Set Bit - M1E (w) */
    Ifx_UReg_32Bit ER:1;              /**< \brief [8:8] Error RAM Overflow, Set Bit - ER (w) */
    Ifx_UReg_32Bit reserved_9:23;     /**< \brief [31:9] \internal Reserved */
} Ifx_HSPDM_FLAGSSET_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_HSPDM_ID_Bits
{
    Ifx_UReg_32Bit MODREV:8;          /**< \brief [7:0] Module Revision Number - MODREV (r) */
    Ifx_UReg_32Bit MODTYPE:8;         /**< \brief [15:8] Module Type - MODTYPE (r) */
    Ifx_UReg_32Bit MODNUMBER:16;      /**< \brief [31:16] Module Number Value - MODNUMBER (r) */
} Ifx_HSPDM_ID_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_HSPDM_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_HSPDM_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_HSPDM_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSPDM_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_HSPDM_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSPDM_KRSTCLR_Bits;

/** \brief MUTE0 Register */
typedef struct _Ifx_HSPDM_MUTE0_Bits
{
    Ifx_UReg_32Bit START0:13;         /**< \brief [12:0] Start Address 0 - START0 (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit END0:13;           /**< \brief [28:16] End Address 1 - END0 (rw) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_HSPDM_MUTE0_Bits;

/** \brief MUTE1 Register */
typedef struct _Ifx_HSPDM_MUTE1_Bits
{
    Ifx_UReg_32Bit START1:13;         /**< \brief [12:0] Start Address 1 - START1 (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit END1:13;           /**< \brief [28:16] End Address1 - END1 (rw) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_HSPDM_MUTE1_Bits;

/** \brief OCDS Control and Status Register */
typedef struct _Ifx_HSPDM_OCS_Bits
{
    Ifx_UReg_32Bit reserved_0:24;     /**< \brief [23:0] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_HSPDM_OCS_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_hspdm_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_ACCEN0_Bits B;          /**< \brief Bitfield access */
} Ifx_HSPDM_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_ACCEN1_Bits B;          /**< \brief Bitfield access */
} Ifx_HSPDM_ACCEN1;

/** \brief ADC Trigger Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_ADCTG_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_ADCTG;

/** \brief ADC Trigger Count Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_ADCTGCNT_Bits B;        /**< \brief Bitfield access */
} Ifx_HSPDM_ADCTGCNT;

/** \brief RAM Buffer A Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_BUFA0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_BUFA0;

/** \brief RAM Buffer B Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_BUFB0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_BUFB0;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_CLC_Bits B;             /**< \brief Bitfield access */
} Ifx_HSPDM_CLC;

/** \brief Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_CON_Bits B;             /**< \brief Bitfield access */
} Ifx_HSPDM_CON;

/** \brief Current Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_CURRAD_Bits B;          /**< \brief Bitfield access */
} Ifx_HSPDM_CURRAD;

/** \brief Flags Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_FLAGS_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_FLAGS;

/** \brief Flags Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_FLAGSCLEAR_Bits B;      /**< \brief Bitfield access */
} Ifx_HSPDM_FLAGSCLEAR;

/** \brief Flags Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_FLAGSEN_Bits B;         /**< \brief Bitfield access */
} Ifx_HSPDM_FLAGSEN;

/** \brief Flags Set Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_FLAGSSET_Bits B;        /**< \brief Bitfield access */
} Ifx_HSPDM_FLAGSSET;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_ID_Bits B;              /**< \brief Bitfield access */
} Ifx_HSPDM_ID;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_KRST0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_KRST1_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_KRSTCLR_Bits B;         /**< \brief Bitfield access */
} Ifx_HSPDM_KRSTCLR;

/** \brief MUTE0 Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_MUTE0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_MUTE0;

/** \brief MUTE1 Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_MUTE1_Bits B;           /**< \brief Bitfield access */
} Ifx_HSPDM_MUTE1;

/** \brief OCDS Control and Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSPDM_OCS_Bits B;             /**< \brief Bitfield access */
} Ifx_HSPDM_OCS;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Hspdm_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief HSPDM object */
typedef volatile struct _Ifx_HSPDM
{
       Ifx_UReg_32Bit                      SRAM[2048];            /**< \brief 0, SRAM*/
       Ifx_HSPDM_CLC                       CLC;                    /**< \brief 2000, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_2004[4];       /**< \brief 2004, \internal Reserved */
       Ifx_HSPDM_ID                        ID;                     /**< \brief 2008, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_200C[4];       /**< \brief 200C, \internal Reserved */
       Ifx_HSPDM_BUFA0                     BUFA0;                  /**< \brief 2010, RAM Buffer A Register 0*/
       Ifx_UReg_8Bit                       reserved_2014[4];       /**< \brief 2014, \internal Reserved */
       Ifx_HSPDM_BUFB0                     BUFB0;                  /**< \brief 2018, RAM Buffer B Register 0*/
       Ifx_HSPDM_CURRAD                    CURRAD;                 /**< \brief 201C, Current Address Register*/
       Ifx_HSPDM_MUTE0                     MUTE0;                  /**< \brief 2020, MUTE0 Register*/
       Ifx_HSPDM_MUTE1                     MUTE1;                  /**< \brief 2024, MUTE1 Register*/
       Ifx_UReg_8Bit                       reserved_2028[8];       /**< \brief 2028, \internal Reserved */
       Ifx_HSPDM_ADCTG                     ADCTG;                  /**< \brief 2030, ADC Trigger Register*/
       Ifx_HSPDM_ADCTGCNT                  ADCTGCNT;               /**< \brief 2034, ADC Trigger Count Register*/
       Ifx_HSPDM_CON                       CON;                    /**< \brief 2038, Configuration Register*/
       Ifx_UReg_8Bit                       reserved_203C[8];       /**< \brief 203C, \internal Reserved */
       Ifx_HSPDM_FLAGS                     FLAGS;                  /**< \brief 2044, Flags Register*/
       Ifx_HSPDM_FLAGSSET                  FLAGSSET;               /**< \brief 2048, Flags Set Register*/
       Ifx_HSPDM_FLAGSCLEAR                FLAGSCLEAR;             /**< \brief 204C, Flags Clear Register*/
       Ifx_HSPDM_FLAGSEN                   FLAGSEN;                /**< \brief 2050, Flags Enable Register*/
       Ifx_UReg_8Bit                       reserved_2054[148];     /**< \brief 2054, \internal Reserved */
       Ifx_HSPDM_OCS                       OCS;                    /**< \brief 20E8, OCDS Control and Status Register*/
       Ifx_HSPDM_KRSTCLR                   KRSTCLR;                /**< \brief 20EC, Kernel Reset Status Clear Register*/
       Ifx_HSPDM_KRST1                     KRST1;                  /**< \brief 20F0, Kernel Reset Register 1*/
       Ifx_HSPDM_KRST0                     KRST0;                  /**< \brief 20F4, Kernel Reset Register 0*/
       Ifx_HSPDM_ACCEN1                    ACCEN1;                 /**< \brief 20F8, Access Enable Register 1*/
       Ifx_HSPDM_ACCEN0                    ACCEN0;                 /**< \brief 20FC, Access Enable Register 0*/
} Ifx_HSPDM;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXHSPDM_REGDEF_H */
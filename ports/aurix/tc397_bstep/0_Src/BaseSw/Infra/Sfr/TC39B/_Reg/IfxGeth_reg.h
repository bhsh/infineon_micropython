/**
 * \file IfxGeth_reg.h
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
 * \defgroup IfxSfr_Geth_Registers_Cfg Geth address
 * \ingroup IfxSfr_Geth_Registers
 * 
 * \defgroup IfxSfr_Geth_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Geth_Registers_Cfg
 *
 * \defgroup IfxSfr_Geth_Registers_Cfg_Geth 2-GETH
 * \ingroup IfxSfr_Geth_Registers_Cfg
 *
 *
 */
#ifndef IFXGETH_REG_H
#define IFXGETH_REG_H 1
/******************************************************************************/
#include "IfxGeth_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Geth_Registers_Cfg_BaseAddress
 * \{  */

/** \brief GETH object */
#define MODULE_GETH /*lint --e(923, 9078)*/ ((*(Ifx_GETH*)0xF001D000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Geth_Registers_Cfg_Geth
 * \{  */
/** \brief 0, MAC Configuration Register */
#define GETH_MAC_CONFIGURATION /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_CONFIGURATION*)0xF001D000u)

/** \brief 4, MAC Extended Configuration Register */
#define GETH_MAC_EXT_CONFIGURATION /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_EXT_CONFIGURATION*)0xF001D004u)

/** \brief 8, MAC Packet Filter Register */
#define GETH_MAC_PACKET_FILTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PACKET_FILTER*)0xF001D008u)

/** \brief C, MAC Watchdog Timeout Register */
#define GETH_MAC_WATCHDOG_TIMEOUT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_WATCHDOG_TIMEOUT*)0xF001D00Cu)

/** \brief 50, MAC VLAN Tag Control Register */
#define GETH_MAC_VLAN_TAG_CTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_TAG_CTRL*)0xF001D050u)

/** \brief 54, MAC VLAN Tag Data Register */
#define GETH_MAC_VLAN_TAG_DATA /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_TAG_DATA*)0xF001D054u)

/** \brief 54, MAC VLAN Tag Filter ${i} Register */
#define GETH_MAC_VLAN_TAG_FILTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_TAG_FILTER*)0xF001D054u)
/** Alias (User Manual Name) for GETH_MAC_VLAN_TAG_FILTER.
* To use register names with standard convension, please use GETH_MAC_VLAN_TAG_FILTER.
*/
#define GETH_MAC_VLAN_TAG_FILTER_I (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_0 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_1 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_2 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_3 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_4 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_5 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_6 (GETH_MAC_VLAN_TAG_FILTER)
#define GETH_MAC_VLAN_TAG_FILTER_7 (GETH_MAC_VLAN_TAG_FILTER)

/** \brief 58, MAC VLAN Hash Table Register */
#define GETH_MAC_VLAN_HASH_TABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_HASH_TABLE*)0xF001D058u)

/** \brief 60, MAC VLAN Tag Inclusion or Replacement Register */
#define GETH_MAC_VLAN_INCL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_INCL*)0xF001D060u)

/** \brief 60, MAC VLAN Tag Inclusion or Replacement Register per Queue */
#define GETH_MAC_VLAN_INCL_Q /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VLAN_INCL_Q*)0xF001D060u)
/** Alias (User Manual Name) for GETH_MAC_VLAN_INCL_Q.
* To use register names with standard convension, please use GETH_MAC_VLAN_INCL_Q.
*/
#define GETH_MAC_VLAN_INCL_Q_I (GETH_MAC_VLAN_INCL_Q)
#define GETH_MAC_VLAN_INCL_Q_0 (GETH_MAC_VLAN_INCL_Q)
#define GETH_MAC_VLAN_INCL_Q_1 (GETH_MAC_VLAN_INCL_Q)
#define GETH_MAC_VLAN_INCL_Q_2 (GETH_MAC_VLAN_INCL_Q)
#define GETH_MAC_VLAN_INCL_Q_3 (GETH_MAC_VLAN_INCL_Q)

/** \brief 64, MAC Inner VLAN Tag Inclusion or Replacement Register */
#define GETH_MAC_INNER_VLAN_INCL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_INNER_VLAN_INCL*)0xF001D064u)
/** Alias (User Manual Name) for GETH_MAC_INNER_VLAN_INCL.
* To use register names with standard convension, please use GETH_MAC_INNER_VLAN_INCL.
*/
#define GETH_MAC_INNER_VLAN_INCL_I (GETH_MAC_INNER_VLAN_INCL)
#define GETH_MAC_INNER_VLAN_INCL_0 (GETH_MAC_INNER_VLAN_INCL)
#define GETH_MAC_INNER_VLAN_INCL_1 (GETH_MAC_INNER_VLAN_INCL)
#define GETH_MAC_INNER_VLAN_INCL_2 (GETH_MAC_INNER_VLAN_INCL)
#define GETH_MAC_INNER_VLAN_INCL_3 (GETH_MAC_INNER_VLAN_INCL)

/** \brief 70, MAC Queue 0 TX Flow Control Register */
#define GETH_MAC_Q0_TX_FLOW_CTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_Q0_TX_FLOW_CTRL*)0xF001D070u)

/** \brief 90, MAC Receive Flow Control Register */
#define GETH_MAC_RX_FLOW_CTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RX_FLOW_CTRL*)0xF001D090u)

/** \brief 94, MAC Receive Queue Control 4 register  */
#define GETH_MAC_RXQ_CTRL4 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RXQ_CTRL4*)0xF001D094u)

/** \brief A0, MAC Receive Queue Control 0 Register */
#define GETH_MAC_RXQ_CTRL0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RXQ_CTRL0*)0xF001D0A0u)

/** \brief A4, MAC Receive Queue Control 1 Register */
#define GETH_MAC_RXQ_CTRL1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RXQ_CTRL1*)0xF001D0A4u)

/** \brief A8, MAC Receive Queue Control 2 Register */
#define GETH_MAC_RXQ_CTRL2 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RXQ_CTRL2*)0xF001D0A8u)

/** \brief B0, MAC Interrupt Status Register */
#define GETH_MAC_INTERRUPT_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_INTERRUPT_STATUS*)0xF001D0B0u)

/** \brief B4, MAC Interrupt Enable Register */
#define GETH_MAC_INTERRUPT_ENABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_INTERRUPT_ENABLE*)0xF001D0B4u)

/** \brief B8, MAC Receive Transmit Status Register */
#define GETH_MAC_RX_TX_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RX_TX_STATUS*)0xF001D0B8u)

/** \brief C0, MAC PMT Control and Status Register */
#define GETH_MAC_PMT_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PMT_CONTROL_STATUS*)0xF001D0C0u)

/** \brief C4, MAC Wake-up Packet Filter Register */
#define GETH_MAC_RWK_PACKET_FILTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_RWK_PACKET_FILTER*)0xF001D0C4u)

/** \brief C4, MAC Wake-up Filter Command 0 Register */
#define GETH_RWK_FILTER_COMMAND_0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RWK_FILTER_COMMAND_0*)0xF001D0C4u)

/** \brief C4, MAC Wake-up Filter Offset 0 Register */
#define GETH_RWK_FILTER_OFFSET_0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RWK_FILTER_OFFSET_0*)0xF001D0C4u)

/** \brief C4, MAC Wake-up Filter CRC ${i} Register */
#define GETH_RWK_FILTER_CRC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RWK_FILTER_CRC*)0xF001D0C4u)
/** Alias (User Manual Name) for GETH_RWK_FILTER_CRC.
* To use register names with standard convension, please use GETH_RWK_FILTER_CRC.
*/
#define GETH_RWK_FILTER_CRC_I (GETH_RWK_FILTER_CRC)
#define GETH_RWK_FILTER_CRC_0 (GETH_RWK_FILTER_CRC)
#define GETH_RWK_FILTER_CRC_1 (GETH_RWK_FILTER_CRC)

/** \brief C4, MAC Wake-up ${i} Filter Byte Mask register */
#define GETH_RWK_FILTER_BYTE_MASK /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RWK_FILTER_BYTE_MASK*)0xF001D0C4u)
/** Alias (User Manual Name) for GETH_RWK_FILTER_BYTE_MASK.
* To use register names with standard convension, please use GETH_RWK_FILTER_BYTE_MASK.
*/
#define GETH_RWK_FILTER_BYTE_MASK_I (GETH_RWK_FILTER_BYTE_MASK)
#define GETH_RWK_FILTER_BYTE_MASK_0 (GETH_RWK_FILTER_BYTE_MASK)
#define GETH_RWK_FILTER_BYTE_MASK_1 (GETH_RWK_FILTER_BYTE_MASK)
#define GETH_RWK_FILTER_BYTE_MASK_2 (GETH_RWK_FILTER_BYTE_MASK)
#define GETH_RWK_FILTER_BYTE_MASK_3 (GETH_RWK_FILTER_BYTE_MASK)

/** \brief D0, MAC LPI Control and Status Register */
#define GETH_MAC_LPI_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_LPI_CONTROL_STATUS*)0xF001D0D0u)

/** \brief D4, MAC LPI Timers Control Register */
#define GETH_MAC_LPI_TIMERS_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_LPI_TIMERS_CONTROL*)0xF001D0D4u)

/** \brief D8, MAC LPI Entry Timer Register */
#define GETH_MAC_LPI_ENTRY_TIMER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_LPI_ENTRY_TIMER*)0xF001D0D8u)

/** \brief DC, MAC One Microsecond Tic Counter Register */
#define GETH_MAC_1US_TIC_COUNTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_1US_TIC_COUNTER*)0xF001D0DCu)

/** \brief F8, MAC PHY Interface Control and Status Register */
#define GETH_MAC_PHYIF_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PHYIF_CONTROL_STATUS*)0xF001D0F8u)

/** \brief 110, MAC Version Register */
#define GETH_MAC_VERSION /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_VERSION*)0xF001D110u)

/** \brief 114, MAC Debug Register */
#define GETH_MAC_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_DEBUG*)0xF001D114u)

/** \brief 11C, MAC Hardware Feature Register 0 */
#define GETH_MAC_HW_FEATURE0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_HW_FEATURE0*)0xF001D11Cu)

/** \brief 120, MAC Hardware Feature Register 1 */
#define GETH_MAC_HW_FEATURE1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_HW_FEATURE1*)0xF001D120u)

/** \brief 124, MAC Hardware Feature Register 2 */
#define GETH_MAC_HW_FEATURE2 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_HW_FEATURE2*)0xF001D124u)

/** \brief 128, MAC Hardware Feature Register 3 */
#define GETH_MAC_HW_FEATURE3 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_HW_FEATURE3*)0xF001D128u)

/** \brief 200, MAC MDIO Address Register */
#define GETH_MAC_MDIO_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_MDIO_ADDRESS*)0xF001D200u)

/** \brief 204, MAC MDIO Data Register */
#define GETH_MAC_MDIO_DATA /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_MDIO_DATA*)0xF001D204u)

/** \brief 230, MAC CSR Software Controls Register */
#define GETH_MAC_CSR_SW_CTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_CSR_SW_CTRL*)0xF001D230u)

/** \brief 300, MAC Address 0 High Register */
#define GETH_MAC_ADDRESS_HIGH0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH0*)0xF001D300u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH0.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH0.
*/
#define GETH_MAC_ADDRESS0_HIGH (GETH_MAC_ADDRESS_HIGH0)

/** \brief 304, MAC Address 0 Low Register */
#define GETH_MAC_ADDRESS_LOW0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW0*)0xF001D304u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW0.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW0.
*/
#define GETH_MAC_ADDRESS0_LOW (GETH_MAC_ADDRESS_LOW0)

/** \brief 308, MAC Address 1 High Register */
#define GETH_MAC_ADDRESS_HIGH1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D308u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH1.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH1.
*/
#define GETH_MAC_ADDRESS1_HIGH (GETH_MAC_ADDRESS_HIGH1)

/** \brief 30C, MAC Address 1 Low Register */
#define GETH_MAC_ADDRESS_LOW1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D30Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW1.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW1.
*/
#define GETH_MAC_ADDRESS1_LOW (GETH_MAC_ADDRESS_LOW1)

/** \brief 310, MAC Address 2 High Register */
#define GETH_MAC_ADDRESS_HIGH2 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D310u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH2.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH2.
*/
#define GETH_MAC_ADDRESS2_HIGH (GETH_MAC_ADDRESS_HIGH2)

/** \brief 314, MAC Address 2 Low Register */
#define GETH_MAC_ADDRESS_LOW2 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D314u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW2.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW2.
*/
#define GETH_MAC_ADDRESS2_LOW (GETH_MAC_ADDRESS_LOW2)

/** \brief 318, MAC Address 3 High Register */
#define GETH_MAC_ADDRESS_HIGH3 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D318u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH3.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH3.
*/
#define GETH_MAC_ADDRESS3_HIGH (GETH_MAC_ADDRESS_HIGH3)

/** \brief 31C, MAC Address 3 Low Register */
#define GETH_MAC_ADDRESS_LOW3 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D31Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW3.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW3.
*/
#define GETH_MAC_ADDRESS3_LOW (GETH_MAC_ADDRESS_LOW3)

/** \brief 320, MAC Address 4 High Register */
#define GETH_MAC_ADDRESS_HIGH4 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D320u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH4.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH4.
*/
#define GETH_MAC_ADDRESS4_HIGH (GETH_MAC_ADDRESS_HIGH4)

/** \brief 324, MAC Address 4 Low Register */
#define GETH_MAC_ADDRESS_LOW4 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D324u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW4.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW4.
*/
#define GETH_MAC_ADDRESS4_LOW (GETH_MAC_ADDRESS_LOW4)

/** \brief 328, MAC Address 5 High Register */
#define GETH_MAC_ADDRESS_HIGH5 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D328u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH5.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH5.
*/
#define GETH_MAC_ADDRESS5_HIGH (GETH_MAC_ADDRESS_HIGH5)

/** \brief 32C, MAC Address 5 Low Register */
#define GETH_MAC_ADDRESS_LOW5 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D32Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW5.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW5.
*/
#define GETH_MAC_ADDRESS5_LOW (GETH_MAC_ADDRESS_LOW5)

/** \brief 330, MAC Address 6 High Register */
#define GETH_MAC_ADDRESS_HIGH6 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D330u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH6.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH6.
*/
#define GETH_MAC_ADDRESS6_HIGH (GETH_MAC_ADDRESS_HIGH6)

/** \brief 334, MAC Address 6 Low Register */
#define GETH_MAC_ADDRESS_LOW6 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D334u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW6.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW6.
*/
#define GETH_MAC_ADDRESS6_LOW (GETH_MAC_ADDRESS_LOW6)

/** \brief 338, MAC Address 7 High Register */
#define GETH_MAC_ADDRESS_HIGH7 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D338u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH7.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH7.
*/
#define GETH_MAC_ADDRESS7_HIGH (GETH_MAC_ADDRESS_HIGH7)

/** \brief 33C, MAC Address 7 Low Register */
#define GETH_MAC_ADDRESS_LOW7 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D33Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW7.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW7.
*/
#define GETH_MAC_ADDRESS7_LOW (GETH_MAC_ADDRESS_LOW7)

/** \brief 340, MAC Address 8 High Register */
#define GETH_MAC_ADDRESS_HIGH8 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D340u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH8.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH8.
*/
#define GETH_MAC_ADDRESS8_HIGH (GETH_MAC_ADDRESS_HIGH8)

/** \brief 344, MAC Address 8 Low Register */
#define GETH_MAC_ADDRESS_LOW8 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D344u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW8.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW8.
*/
#define GETH_MAC_ADDRESS8_LOW (GETH_MAC_ADDRESS_LOW8)

/** \brief 348, MAC Address 9 High Register */
#define GETH_MAC_ADDRESS_HIGH9 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D348u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH9.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH9.
*/
#define GETH_MAC_ADDRESS9_HIGH (GETH_MAC_ADDRESS_HIGH9)

/** \brief 34C, MAC Address 9 Low Register */
#define GETH_MAC_ADDRESS_LOW9 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D34Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW9.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW9.
*/
#define GETH_MAC_ADDRESS9_LOW (GETH_MAC_ADDRESS_LOW9)

/** \brief 350, MAC Address 10 High Register */
#define GETH_MAC_ADDRESS_HIGH10 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D350u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH10.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH10.
*/
#define GETH_MAC_ADDRESS10_HIGH (GETH_MAC_ADDRESS_HIGH10)

/** \brief 354, MAC Address 10 Low Register */
#define GETH_MAC_ADDRESS_LOW10 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D354u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW10.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW10.
*/
#define GETH_MAC_ADDRESS10_LOW (GETH_MAC_ADDRESS_LOW10)

/** \brief 358, MAC Address 11 High Register */
#define GETH_MAC_ADDRESS_HIGH11 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D358u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH11.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH11.
*/
#define GETH_MAC_ADDRESS11_HIGH (GETH_MAC_ADDRESS_HIGH11)

/** \brief 35C, MAC Address 11 Low Register */
#define GETH_MAC_ADDRESS_LOW11 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D35Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW11.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW11.
*/
#define GETH_MAC_ADDRESS11_LOW (GETH_MAC_ADDRESS_LOW11)

/** \brief 360, MAC Address 12 High Register */
#define GETH_MAC_ADDRESS_HIGH12 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D360u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH12.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH12.
*/
#define GETH_MAC_ADDRESS12_HIGH (GETH_MAC_ADDRESS_HIGH12)

/** \brief 364, MAC Address 12 Low Register */
#define GETH_MAC_ADDRESS_LOW12 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D364u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW12.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW12.
*/
#define GETH_MAC_ADDRESS12_LOW (GETH_MAC_ADDRESS_LOW12)

/** \brief 368, MAC Address 13 High Register */
#define GETH_MAC_ADDRESS_HIGH13 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D368u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH13.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH13.
*/
#define GETH_MAC_ADDRESS13_HIGH (GETH_MAC_ADDRESS_HIGH13)

/** \brief 36C, MAC Address 13 Low Register */
#define GETH_MAC_ADDRESS_LOW13 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D36Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW13.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW13.
*/
#define GETH_MAC_ADDRESS13_LOW (GETH_MAC_ADDRESS_LOW13)

/** \brief 370, MAC Address 14 High Register */
#define GETH_MAC_ADDRESS_HIGH14 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D370u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH14.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH14.
*/
#define GETH_MAC_ADDRESS14_HIGH (GETH_MAC_ADDRESS_HIGH14)

/** \brief 374, MAC Address 14 Low Register */
#define GETH_MAC_ADDRESS_LOW14 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D374u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW14.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW14.
*/
#define GETH_MAC_ADDRESS14_LOW (GETH_MAC_ADDRESS_LOW14)

/** \brief 378, MAC Address 15 High Register */
#define GETH_MAC_ADDRESS_HIGH15 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D378u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH15.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH15.
*/
#define GETH_MAC_ADDRESS15_HIGH (GETH_MAC_ADDRESS_HIGH15)

/** \brief 37C, MAC Address 15 Low Register */
#define GETH_MAC_ADDRESS_LOW15 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D37Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW15.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW15.
*/
#define GETH_MAC_ADDRESS15_LOW (GETH_MAC_ADDRESS_LOW15)

/** \brief 380, MAC Address 16 High Register */
#define GETH_MAC_ADDRESS_HIGH16 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D380u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH16.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH16.
*/
#define GETH_MAC_ADDRESS16_HIGH (GETH_MAC_ADDRESS_HIGH16)

/** \brief 384, MAC Address 16 Low Register */
#define GETH_MAC_ADDRESS_LOW16 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D384u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW16.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW16.
*/
#define GETH_MAC_ADDRESS16_LOW (GETH_MAC_ADDRESS_LOW16)

/** \brief 388, MAC Address 17 High Register */
#define GETH_MAC_ADDRESS_HIGH17 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D388u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH17.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH17.
*/
#define GETH_MAC_ADDRESS17_HIGH (GETH_MAC_ADDRESS_HIGH17)

/** \brief 38C, MAC Address 17 Low Register */
#define GETH_MAC_ADDRESS_LOW17 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D38Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW17.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW17.
*/
#define GETH_MAC_ADDRESS17_LOW (GETH_MAC_ADDRESS_LOW17)

/** \brief 390, MAC Address 18 High Register */
#define GETH_MAC_ADDRESS_HIGH18 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D390u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH18.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH18.
*/
#define GETH_MAC_ADDRESS18_HIGH (GETH_MAC_ADDRESS_HIGH18)

/** \brief 394, MAC Address 18 Low Register */
#define GETH_MAC_ADDRESS_LOW18 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D394u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW18.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW18.
*/
#define GETH_MAC_ADDRESS18_LOW (GETH_MAC_ADDRESS_LOW18)

/** \brief 398, MAC Address 19 High Register */
#define GETH_MAC_ADDRESS_HIGH19 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D398u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH19.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH19.
*/
#define GETH_MAC_ADDRESS19_HIGH (GETH_MAC_ADDRESS_HIGH19)

/** \brief 39C, MAC Address 19 Low Register */
#define GETH_MAC_ADDRESS_LOW19 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D39Cu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW19.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW19.
*/
#define GETH_MAC_ADDRESS19_LOW (GETH_MAC_ADDRESS_LOW19)

/** \brief 3A0, MAC Address 20 High Register */
#define GETH_MAC_ADDRESS_HIGH20 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3A0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH20.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH20.
*/
#define GETH_MAC_ADDRESS20_HIGH (GETH_MAC_ADDRESS_HIGH20)

/** \brief 3A4, MAC Address 20 Low Register */
#define GETH_MAC_ADDRESS_LOW20 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3A4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW20.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW20.
*/
#define GETH_MAC_ADDRESS20_LOW (GETH_MAC_ADDRESS_LOW20)

/** \brief 3A8, MAC Address 21 High Register */
#define GETH_MAC_ADDRESS_HIGH21 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3A8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH21.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH21.
*/
#define GETH_MAC_ADDRESS21_HIGH (GETH_MAC_ADDRESS_HIGH21)

/** \brief 3AC, MAC Address 21 Low Register */
#define GETH_MAC_ADDRESS_LOW21 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3ACu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW21.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW21.
*/
#define GETH_MAC_ADDRESS21_LOW (GETH_MAC_ADDRESS_LOW21)

/** \brief 3B0, MAC Address 22 High Register */
#define GETH_MAC_ADDRESS_HIGH22 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3B0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH22.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH22.
*/
#define GETH_MAC_ADDRESS22_HIGH (GETH_MAC_ADDRESS_HIGH22)

/** \brief 3B4, MAC Address 22 Low Register */
#define GETH_MAC_ADDRESS_LOW22 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3B4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW22.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW22.
*/
#define GETH_MAC_ADDRESS22_LOW (GETH_MAC_ADDRESS_LOW22)

/** \brief 3B8, MAC Address 23 High Register */
#define GETH_MAC_ADDRESS_HIGH23 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3B8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH23.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH23.
*/
#define GETH_MAC_ADDRESS23_HIGH (GETH_MAC_ADDRESS_HIGH23)

/** \brief 3BC, MAC Address 23 Low Register */
#define GETH_MAC_ADDRESS_LOW23 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3BCu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW23.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW23.
*/
#define GETH_MAC_ADDRESS23_LOW (GETH_MAC_ADDRESS_LOW23)

/** \brief 3C0, MAC Address 24 High Register */
#define GETH_MAC_ADDRESS_HIGH24 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3C0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH24.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH24.
*/
#define GETH_MAC_ADDRESS24_HIGH (GETH_MAC_ADDRESS_HIGH24)

/** \brief 3C4, MAC Address 24 Low Register */
#define GETH_MAC_ADDRESS_LOW24 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3C4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW24.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW24.
*/
#define GETH_MAC_ADDRESS24_LOW (GETH_MAC_ADDRESS_LOW24)

/** \brief 3C8, MAC Address 25 High Register */
#define GETH_MAC_ADDRESS_HIGH25 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3C8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH25.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH25.
*/
#define GETH_MAC_ADDRESS25_HIGH (GETH_MAC_ADDRESS_HIGH25)

/** \brief 3CC, MAC Address 25 Low Register */
#define GETH_MAC_ADDRESS_LOW25 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3CCu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW25.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW25.
*/
#define GETH_MAC_ADDRESS25_LOW (GETH_MAC_ADDRESS_LOW25)

/** \brief 3D0, MAC Address 26 High Register */
#define GETH_MAC_ADDRESS_HIGH26 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3D0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH26.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH26.
*/
#define GETH_MAC_ADDRESS26_HIGH (GETH_MAC_ADDRESS_HIGH26)

/** \brief 3D4, MAC Address 26 Low Register */
#define GETH_MAC_ADDRESS_LOW26 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3D4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW26.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW26.
*/
#define GETH_MAC_ADDRESS26_LOW (GETH_MAC_ADDRESS_LOW26)

/** \brief 3D8, MAC Address 27 High Register */
#define GETH_MAC_ADDRESS_HIGH27 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3D8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH27.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH27.
*/
#define GETH_MAC_ADDRESS27_HIGH (GETH_MAC_ADDRESS_HIGH27)

/** \brief 3DC, MAC Address 27 Low Register */
#define GETH_MAC_ADDRESS_LOW27 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3DCu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW27.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW27.
*/
#define GETH_MAC_ADDRESS27_LOW (GETH_MAC_ADDRESS_LOW27)

/** \brief 3E0, MAC Address 28 High Register */
#define GETH_MAC_ADDRESS_HIGH28 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3E0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH28.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH28.
*/
#define GETH_MAC_ADDRESS28_HIGH (GETH_MAC_ADDRESS_HIGH28)

/** \brief 3E4, MAC Address 28 Low Register */
#define GETH_MAC_ADDRESS_LOW28 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3E4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW28.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW28.
*/
#define GETH_MAC_ADDRESS28_LOW (GETH_MAC_ADDRESS_LOW28)

/** \brief 3E8, MAC Address 29 High Register */
#define GETH_MAC_ADDRESS_HIGH29 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3E8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH29.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH29.
*/
#define GETH_MAC_ADDRESS29_HIGH (GETH_MAC_ADDRESS_HIGH29)

/** \brief 3EC, MAC Address 29 Low Register */
#define GETH_MAC_ADDRESS_LOW29 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3ECu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW29.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW29.
*/
#define GETH_MAC_ADDRESS29_LOW (GETH_MAC_ADDRESS_LOW29)

/** \brief 3F0, MAC Address 30 High Register */
#define GETH_MAC_ADDRESS_HIGH30 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3F0u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH30.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH30.
*/
#define GETH_MAC_ADDRESS30_HIGH (GETH_MAC_ADDRESS_HIGH30)

/** \brief 3F4, MAC Address 30 Low Register */
#define GETH_MAC_ADDRESS_LOW30 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3F4u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW30.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW30.
*/
#define GETH_MAC_ADDRESS30_LOW (GETH_MAC_ADDRESS_LOW30)

/** \brief 3F8, MAC Address 31 High Register */
#define GETH_MAC_ADDRESS_HIGH31 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_HIGH*)0xF001D3F8u)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_HIGH31.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_HIGH31.
*/
#define GETH_MAC_ADDRESS31_HIGH (GETH_MAC_ADDRESS_HIGH31)

/** \brief 3FC, MAC Address 31 Low Register */
#define GETH_MAC_ADDRESS_LOW31 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_ADDRESS_LOW*)0xF001D3FCu)
/** Alias (User Manual Name) for GETH_MAC_ADDRESS_LOW31.
* To use register names with standard convension, please use GETH_MAC_ADDRESS_LOW31.
*/
#define GETH_MAC_ADDRESS31_LOW (GETH_MAC_ADDRESS_LOW31)

/** \brief 700, MMC Control Register */
#define GETH_MMC_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_CONTROL*)0xF001D700u)

/** \brief 704, MMC Receive Interrupts Register */
#define GETH_MMC_RX_INTERRUPT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_RX_INTERRUPT*)0xF001D704u)

/** \brief 708, MMC Transmit Interrupts Register */
#define GETH_MMC_TX_INTERRUPT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_TX_INTERRUPT*)0xF001D708u)

/** \brief 70C, MMC Receive Interrupts Mask Register */
#define GETH_MMC_RX_INTERRUPT_MASK /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_RX_INTERRUPT_MASK*)0xF001D70Cu)

/** \brief 710, MMC Transmit Interrupts Mask Register */
#define GETH_MMC_TX_INTERRUPT_MASK /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_TX_INTERRUPT_MASK*)0xF001D710u)

/** \brief 714, Good And Bad Transmitted Octet Count Register */
#define GETH_TX_OCTET_COUNT_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_OCTET_COUNT_GOOD_BAD*)0xF001D714u)

/** \brief 718, Good And Bad Transmitted Packets Count Register */
#define GETH_TX_PACKET_COUNT_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_PACKET_COUNT_GOOD_BAD*)0xF001D718u)

/** \brief 71C, Good Transmitted Broadcast Packets Count Register */
#define GETH_TX_BROADCAST_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_BROADCAST_PACKETS_GOOD*)0xF001D71Cu)

/** \brief 720, Good Transmitted Multicast Packets Count Register */
#define GETH_TX_MULTICAST_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_MULTICAST_PACKETS_GOOD*)0xF001D720u)

/** \brief 724, Good And Bad 64 Octets Packets Transmitted Count Register */
#define GETH_TX_64OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_64OCTETS_PACKETS_GOOD_BAD*)0xF001D724u)

/** \brief 728, Good And Bad 65to127 Octets Packets Transmitted Count Register */
#define GETH_TX_65TO127OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_65TO127OCTETS_PACKETS_GOOD_BAD*)0xF001D728u)

/** \brief 72C, Good And Bad 128to255 Octets Packets Transmitted Count Register */
#define GETH_TX_128TO255OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_128TO255OCTETS_PACKETS_GOOD_BAD*)0xF001D72Cu)

/** \brief 730, Good And Bad 256to511 Octets Packets Transmitted Count Register */
#define GETH_TX_256TO511OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_256TO511OCTETS_PACKETS_GOOD_BAD*)0xF001D730u)

/** \brief 734, Good And Bad 512to1023 Octets Packets Transmitted Count Register */
#define GETH_TX_512TO1023OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_512TO1023OCTETS_PACKETS_GOOD_BAD*)0xF001D734u)

/** \brief 738, Good And Bad 1024toMax Octets Packets Transmitted Count Register */
#define GETH_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD*)0xF001D738u)

/** \brief 73C, Good Transmitted Unicat Packets Count Register */
#define GETH_TX_UNICAST_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_UNICAST_PACKETS_GOOD_BAD*)0xF001D73Cu)

/** \brief 740, Good And Bad Transmitted Multicast Packets Count Register */
#define GETH_TX_MULTICAST_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_MULTICAST_PACKETS_GOOD_BAD*)0xF001D740u)

/** \brief 744, Good And Bad Transmitted Broadcast Packets Count Register */
#define GETH_TX_BROADCAST_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_BROADCAST_PACKETS_GOOD_BAD*)0xF001D744u)

/** \brief 748, Transmitted Underflow Error Packets Count Register */
#define GETH_TX_UNDERFLOW_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_UNDERFLOW_ERROR_PACKETS*)0xF001D748u)

/** \brief 74C, Good Transmitted Single Collision Count Register */
#define GETH_TX_SINGLE_COLLISION_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_SINGLE_COLLISION_GOOD_PACKETS*)0xF001D74Cu)

/** \brief 750, Transmitted Multiple Collision Count Register */
#define GETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS*)0xF001D750u)

/** \brief 754, Transmitted Deferred Packets Count Register */
#define GETH_TX_DEFERRED_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_DEFERRED_PACKETS*)0xF001D754u)

/** \brief 758, Transmitted Late Collision Packets Count Register */
#define GETH_TX_LATE_COLLISION_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_LATE_COLLISION_PACKETS*)0xF001D758u)

/** \brief 75C, Transmitted Excessive Collision Packets Count Register */
#define GETH_TX_EXCESSIVE_COLLISION_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_EXCESSIVE_COLLISION_PACKETS*)0xF001D75Cu)

/** \brief 760, Transmitted Carrier Error Packets Count Register */
#define GETH_TX_CARRIER_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_CARRIER_ERROR_PACKETS*)0xF001D760u)

/** \brief 764, Good Transmitted Octet Count Register */
#define GETH_TX_OCTET_COUNT_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_OCTET_COUNT_GOOD*)0xF001D764u)

/** \brief 768, Good Transmitted Packet Count Register */
#define GETH_TX_PACKET_COUNT_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_PACKET_COUNT_GOOD*)0xF001D768u)

/** \brief 76C, Transmitted Excessive Deferral Error Count Register */
#define GETH_TX_EXCESSIVE_DEFERRAL_ERROR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_EXCESSIVE_DEFERRAL_ERROR*)0xF001D76Cu)

/** \brief 770, Transmitted Pause Packets Count Register */
#define GETH_TX_PAUSE_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_PAUSE_PACKETS*)0xF001D770u)

/** \brief 774, Good Transmitted VLAN Packets Count Register */
#define GETH_TX_VLAN_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_VLAN_PACKETS_GOOD*)0xF001D774u)

/** \brief 778, Good Transmitted Osize Packets Count Register */
#define GETH_TX_OSIZE_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_OSIZE_PACKETS_GOOD*)0xF001D778u)

/** \brief 780, Good And Bad Received Packets Count Register */
#define GETH_RX_PACKETS_COUNT_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_PACKETS_COUNT_GOOD_BAD*)0xF001D780u)

/** \brief 784, Good And Bad Received Octet Count Register */
#define GETH_RX_OCTET_COUNT_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_OCTET_COUNT_GOOD_BAD*)0xF001D784u)

/** \brief 788, Good Received Octet Count Register */
#define GETH_RX_OCTET_COUNT_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_OCTET_COUNT_GOOD*)0xF001D788u)

/** \brief 78C, Good Received Broadcast Packets Count Register */
#define GETH_RX_BROADCAST_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_BROADCAST_PACKETS_GOOD*)0xF001D78Cu)

/** \brief 790, Good Received Multicast Packets Count Register */
#define GETH_RX_MULTICAST_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_MULTICAST_PACKETS_GOOD*)0xF001D790u)

/** \brief 794, Received CRC Error Packets Count Register */
#define GETH_RX_CRC_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_CRC_ERROR_PACKETS*)0xF001D794u)

/** \brief 798, Received Alignment Error Count Register */
#define GETH_RX_ALIGNMENT_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_ALIGNMENT_ERROR_PACKETS*)0xF001D798u)

/** \brief 79C, Received Runtime Error Count Register */
#define GETH_RX_RUNT_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_RUNT_ERROR_PACKETS*)0xF001D79Cu)

/** \brief 7A0, Received Jabber Error Count Register */
#define GETH_RX_JABBER_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_JABBER_ERROR_PACKETS*)0xF001D7A0u)

/** \brief 7A4, Good Received Undersized Packets Count Register */
#define GETH_RX_UNDERSIZE_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_UNDERSIZE_PACKETS_GOOD*)0xF001D7A4u)

/** \brief 7A8, Good Received Oversized Packets Count Register */
#define GETH_RX_OVERSIZE_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_OVERSIZE_PACKETS_GOOD*)0xF001D7A8u)

/** \brief 7AC, Good And Bad 64 Octets Packets Received Count Register */
#define GETH_RX_64OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_64OCTETS_PACKETS_GOOD_BAD*)0xF001D7ACu)

/** \brief 7B0, Good And Bad 65to127 Octets Packets Received Count Register */
#define GETH_RX_65TO127OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_65TO127OCTETS_PACKETS_GOOD_BAD*)0xF001D7B0u)

/** \brief 7B4, Good And Bad 128to255 Octets Packets Received Count Register */
#define GETH_RX_128TO255OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_128TO255OCTETS_PACKETS_GOOD_BAD*)0xF001D7B4u)

/** \brief 7B8, Good And Bad 256to511 Octets Packets Received Count Register */
#define GETH_RX_256TO511OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_256TO511OCTETS_PACKETS_GOOD_BAD*)0xF001D7B8u)

/** \brief 7BC, Good And Bad 512to1023 Octets Packets Received Count Register */
#define GETH_RX_512TO1023OCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_512TO1023OCTETS_PACKETS_GOOD_BAD*)0xF001D7BCu)

/** \brief 7C0, Good And Bad 1024toMax Octets Packets Received Count Register */
#define GETH_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD*)0xF001D7C0u)

/** \brief 7C4, Good Received Unicat Packets Count Register */
#define GETH_RX_UNICAST_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_UNICAST_PACKETS_GOOD*)0xF001D7C4u)

/** \brief 7C8, Received Length Error Packets Count Register */
#define GETH_RX_LENGTH_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_LENGTH_ERROR_PACKETS*)0xF001D7C8u)

/** \brief 7CC, Received Out Of Range Type Count Register */
#define GETH_RX_OUT_OF_RANGE_TYPE_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_OUT_OF_RANGE_TYPE_PACKETS*)0xF001D7CCu)

/** \brief 7D0, Received Pause Packets Count Register */
#define GETH_RX_PAUSE_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_PAUSE_PACKETS*)0xF001D7D0u)

/** \brief 7D4, Received FIFO Overflow Count Register */
#define GETH_RX_FIFO_OVERFLOW_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_FIFO_OVERFLOW_PACKETS*)0xF001D7D4u)

/** \brief 7D8, Good And Bad Received VLAN Packets Count Registerv */
#define GETH_RX_VLAN_PACKETS_GOOD_BAD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_VLAN_PACKETS_GOOD_BAD*)0xF001D7D8u)

/** \brief 7DC, Received Watchdog Error Count Register */
#define GETH_RX_WATCHDOG_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_WATCHDOG_ERROR_PACKETS*)0xF001D7DCu)

/** \brief 7E0, Received Receive Error Count Register */
#define GETH_RX_RECEIVE_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_RECEIVE_ERROR_PACKETS*)0xF001D7E0u)

/** \brief 7E4, Good Received Control Packets Count Register */
#define GETH_RX_CONTROL_PACKETS_GOOD /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_CONTROL_PACKETS_GOOD*)0xF001D7E4u)

/** \brief 7EC, Transmitted LPI Microseconds Count Register */
#define GETH_TX_LPI_USEC_CNTR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_LPI_USEC_CNTR*)0xF001D7ECu)

/** \brief 7F0, Transmitted LPI Transition Count Register */
#define GETH_TX_LPI_TRAN_CNTR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_TX_LPI_TRAN_CNTR*)0xF001D7F0u)

/** \brief 7F4, Received Microseconds LPI Count Register */
#define GETH_RX_LPI_USEC_CNTR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_LPI_USEC_CNTR*)0xF001D7F4u)

/** \brief 7F8, Received LPI Transition Count Register */
#define GETH_RX_LPI_TRAN_CNTR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RX_LPI_TRAN_CNTR*)0xF001D7F8u)

/** \brief 800, MMC IPC Receive Interrupts Mask Register */
#define GETH_MMC_IPC_RX_INTERRUPT_MASK /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_IPC_RX_INTERRUPT_MASK*)0xF001D800u)

/** \brief 808, MMC IPC Receive Interrupts Register */
#define GETH_MMC_IPC_RX_INTERRUPT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MMC_IPC_RX_INTERRUPT*)0xF001D808u)

/** \brief 810, Good Received RxIPv4 Packets Count Register */
#define GETH_RXIPV4_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_GOOD_PACKETS*)0xF001D810u)

/** \brief 814, Received IPv4 Header Error Packets Count Register */
#define GETH_RXIPV4_HEADER_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_HEADER_ERROR_PACKETS*)0xF001D814u)

/** \brief 818, Received IPv4 No Payload Packets Count Register */
#define GETH_RXIPV4_NO_PAYLOAD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_NO_PAYLOAD_PACKETS*)0xF001D818u)

/** \brief 81C, Received IPv4 Fragmented Packets Count Register */
#define GETH_RXIPV4_FRAGMENTED_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_FRAGMENTED_PACKETS*)0xF001D81Cu)

/** \brief 820, Received IPv4 UPD Checksum Disabled Packets Count Register */
#define GETH_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS*)0xF001D820u)

/** \brief 824, Good Received RxIPv6 Packets Count Register */
#define GETH_RXIPV6_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_GOOD_PACKETS*)0xF001D824u)

/** \brief 828, Received IPv6 Header Error Packets Count Register */
#define GETH_RXIPV6_HEADER_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_HEADER_ERROR_PACKETS*)0xF001D828u)

/** \brief 82C, Received IPv6 No Payload Packets Count Register */
#define GETH_RXIPV6_NO_PAYLOAD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_NO_PAYLOAD_PACKETS*)0xF001D82Cu)

/** \brief 830, Good Received UDP Packets Count Register */
#define GETH_RXUDP_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXUDP_GOOD_PACKETS*)0xF001D830u)

/** \brief 834, Received UDP Error Packets Count Register */
#define GETH_RXUDP_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXUDP_ERROR_PACKETS*)0xF001D834u)

/** \brief 838, Good Received TCP Packets Count Register */
#define GETH_RXTCP_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXTCP_GOOD_PACKETS*)0xF001D838u)

/** \brief 83C, Received TCP Error Packets Count Register */
#define GETH_RXTCP_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXTCP_ERROR_PACKETS*)0xF001D83Cu)

/** \brief 840, Good Received ICMP Packets Count Register */
#define GETH_RXICMP_GOOD_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXICMP_GOOD_PACKETS*)0xF001D840u)

/** \brief 844, Received ICMP Error Packets Count Register */
#define GETH_RXICMP_ERROR_PACKETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXICMP_ERROR_PACKETS*)0xF001D844u)

/** \brief 850, Good Received IPV4 Octets Count Register */
#define GETH_RXIPV4_GOOD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_GOOD_OCTETS*)0xF001D850u)

/** \brief 854, Received IPV4 Header Error Octets Count Register */
#define GETH_RXIPV4_HEADER_ERROR_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_HEADER_ERROR_OCTETS*)0xF001D854u)

/** \brief 858, Received IPV4 No Payload Octets Count Register */
#define GETH_RXIPV4_NO_PAYLOAD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_NO_PAYLOAD_OCTETS*)0xF001D858u)

/** \brief 85C, Received IPV4 Fragmented Octets Count Register */
#define GETH_RXIPV4_FRAGMENTED_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_FRAGMENTED_OCTETS*)0xF001D85Cu)

/** \brief 860, Received IPV4 UPD Checksum Disabled Octets Count Register */
#define GETH_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS*)0xF001D860u)

/** \brief 864, Good Received IPV6 Octets Count Register */
#define GETH_RXIPV6_GOOD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_GOOD_OCTETS*)0xF001D864u)

/** \brief 868, Received IPV6 Header Error Octets Count Register */
#define GETH_RXIPV6_HEADER_ERROR_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_HEADER_ERROR_OCTETS*)0xF001D868u)

/** \brief 86C, Received IPV6 No Payload Octets Count Register */
#define GETH_RXIPV6_NO_PAYLOAD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXIPV6_NO_PAYLOAD_OCTETS*)0xF001D86Cu)

/** \brief 870, Good Received UDP Octets Count Register */
#define GETH_RXUDP_GOOD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXUDP_GOOD_OCTETS*)0xF001D870u)

/** \brief 874, Received UDP Error Octets Count Register */
#define GETH_RXUDP_ERROR_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXUDP_ERROR_OCTETS*)0xF001D874u)

/** \brief 878, Good Received TCP Octets Count Register */
#define GETH_RXTCP_GOOD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXTCP_GOOD_OCTETS*)0xF001D878u)

/** \brief 87C, Received TCP Error Octets Count Register */
#define GETH_RXTCP_ERROR_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXTCP_ERROR_OCTETS*)0xF001D87Cu)

/** \brief 880, Good Received ICMP Octets Count Register */
#define GETH_RXICMP_GOOD_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXICMP_GOOD_OCTETS*)0xF001D880u)

/** \brief 884, Received ICMP Error Octets Count Register */
#define GETH_RXICMP_ERROR_OCTETS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_RXICMP_ERROR_OCTETS*)0xF001D884u)

/** \brief B00, MAC Timestamp Control Register */
#define GETH_MAC_TIMESTAMP_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_CONTROL*)0xF001DB00u)

/** \brief B04, MAC Sub-Second Increment Register */
#define GETH_MAC_SUB_SECOND_INCREMENT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SUB_SECOND_INCREMENT*)0xF001DB04u)

/** \brief B08, MAC System Time Seconds Register */
#define GETH_MAC_SYSTEM_TIME_SECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SYSTEM_TIME_SECONDS*)0xF001DB08u)

/** \brief B0C, MAC System Time Nanoseconds Register */
#define GETH_MAC_SYSTEM_TIME_NANOSECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SYSTEM_TIME_NANOSECONDS*)0xF001DB0Cu)

/** \brief B10, MAC System Time Seconds Update Register */
#define GETH_MAC_SYSTEM_TIME_SECONDS_UPDATE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SYSTEM_TIME_SECONDS_UPDATE*)0xF001DB10u)

/** \brief B14, MAC System Time Nanoseconds Update Register */
#define GETH_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE*)0xF001DB14u)

/** \brief B18, MAC Timestamp Addend Register */
#define GETH_MAC_TIMESTAMP_ADDEND /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_ADDEND*)0xF001DB18u)

/** \brief B1C, MAC System Time Higher Word Seconds Register */
#define GETH_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS*)0xF001DB1Cu)

/** \brief B20, MAC Timestamp Status Register */
#define GETH_MAC_TIMESTAMP_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_STATUS*)0xF001DB20u)

/** \brief B30, MAC Transmit Timestamp Nanoseconds Status Register */
#define GETH_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS*)0xF001DB30u)

/** \brief B34, MAC Transmit Timestamp Seconds Status Register */
#define GETH_MAC_TX_TIMESTAMP_STATUS_SECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TX_TIMESTAMP_STATUS_SECONDS*)0xF001DB34u)

/** \brief B50, MAC Timestamp Ingress Asymmetry Correction Register */
#define GETH_MAC_TIMESTAMP_INGRESS_ASYM_CORR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_INGRESS_ASYM_CORR*)0xF001DB50u)

/** \brief B54, MAC Timestamp Egress Asymmetry Correction Register */
#define GETH_MAC_TIMESTAMP_EGRESS_ASYM_CORR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_EGRESS_ASYM_CORR*)0xF001DB54u)

/** \brief B58, MAC Timestamp Ingress Correction Nanoseconds Register */
#define GETH_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND*)0xF001DB58u)

/** \brief B5C, MAC Timestamp Egress Correction Nanoseconds Register */
#define GETH_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND*)0xF001DB5Cu)

/** \brief B60, MAC Timestamp Ingress Correction Subnanoseconds Register */
#define GETH_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC*)0xF001DB60u)

/** \brief B64, MAC Timestamp Egress Correction Subnanoseconds Register */
#define GETH_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC*)0xF001DB64u)

/** \brief B70, MAC PPS Control Register */
#define GETH_MAC_PPS_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PPS_CONTROL*)0xF001DB70u)

/** \brief B80, MAC PPS 0 Target Time Seconds Register */
#define GETH_MAC_PPS0_TARGET_TIME_SECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PPS0_TARGET_TIME_SECONDS*)0xF001DB80u)

/** \brief B84, MAC PPS 0 Target Time Nanoeconds Register */
#define GETH_MAC_PPS0_TARGET_TIME_NANOSECONDS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PPS0_TARGET_TIME_NANOSECONDS*)0xF001DB84u)

/** \brief B88, MAC PPS 0 Interval Register */
#define GETH_MAC_PPS0_INTERVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PPS0_INTERVAL*)0xF001DB88u)

/** \brief B8C, MAC PPS 0 Width Register */
#define GETH_MAC_PPS0_WIDTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MAC_PPS0_WIDTH*)0xF001DB8Cu)

/** \brief C00, MTL Operation Mode Register */
#define GETH_MTL_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_OPERATION_MODE*)0xF001DC00u)

/** \brief C20, MTL Interrupt Status Register */
#define GETH_MTL_INTERRUPT_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_INTERRUPT_STATUS*)0xF001DC20u)

/** \brief C30, MTL Receive Queue and DMA Channel Mapping 0 Register */
#define GETH_MTL_RXQ_DMA_MAP0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_DMA_MAP0*)0xF001DC30u)

/** \brief D00, MTL Queue 0 Transmit Operation Mode Register */
#define GETH_MTL_TXQ0_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ0_OPERATION_MODE*)0xF001DD00u)

/** \brief D04, MTL Queue 0 Transmit Underflow Counter Register */
#define GETH_MTL_TXQ0_UNDERFLOW /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ0_UNDERFLOW*)0xF001DD04u)

/** \brief D08, MTL Queue 0 Transmit Debug Register */
#define GETH_MTL_TXQ0_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ0_DEBUG*)0xF001DD08u)

/** \brief D14, MTL Queue 0 Transmit Status Register */
#define GETH_MTL_TXQ0_ETS_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ0_ETS_STATUS*)0xF001DD14u)

/** \brief D18, MTL Queue 0 Transmit Quantum or Weights Register */
#define GETH_MTL_TXQ0_QUANTUM_WEIGHT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ0_QUANTUM_WEIGHT*)0xF001DD18u)

/** \brief D2C, MTL Queue 0 Interrupt Control Status Register */
#define GETH_MTL_Q0_INTERRUPT_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_Q0_INTERRUPT_CONTROL_STATUS*)0xF001DD2Cu)

/** \brief D30, MTL Queue 0 Receive Operation Mode Register */
#define GETH_MTL_RXQ0_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ0_OPERATION_MODE*)0xF001DD30u)

/** \brief D34, MTL Queue 0 Receive Missed Packet and Overflow Counter Register */
#define GETH_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT*)0xF001DD34u)

/** \brief D38, MTL Queue 0 Receive Debug Register */
#define GETH_MTL_RXQ0_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ0_DEBUG*)0xF001DD38u)

/** \brief D3C, MTL Queue 0 Receive Control Register */
#define GETH_MTL_RXQ0_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ0_CONTROL*)0xF001DD3Cu)

/** \brief D40, MTL Queue 1 Transmit Operation Mode Register */
#define GETH_MTL_TXQ1_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_OPERATION_MODE*)0xF001DD40u)

/** \brief D44, MTL Queue 1 Transmit Underflow Counter Register */
#define GETH_MTL_TXQ1_UNDERFLOW /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_UNDERFLOW*)0xF001DD44u)

/** \brief D48, MTL Queue 1 Transmit Debug Register */
#define GETH_MTL_TXQ1_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_DEBUG*)0xF001DD48u)

/** \brief D50, MTL Queue 1 Transmit ETS Control Register */
#define GETH_MTL_TXQ1_ETS_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_CONTROL*)0xF001DD50u)

/** \brief D54, MTL Queue 1 Transmit ETS Status Register */
#define GETH_MTL_TXQ1_ETS_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_STATUS*)0xF001DD54u)

/** \brief D58, MTL Queue 1 Transmit Quantum or Weights Register */
#define GETH_MTL_TXQ1_QUANTUM_WEIGHT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_QUANTUM_WEIGHT*)0xF001DD58u)

/** \brief D5C, MTL Queue 1 Transmit SendSlopeCredit Register */
#define GETH_MTL_TXQ1_SENDSLOPECREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_SENDSLOPECREDIT*)0xF001DD5Cu)

/** \brief D60, MTL Queue 1 Transmit HiCredit Register */
#define GETH_MTL_TXQ1_HICREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_HICREDIT*)0xF001DD60u)

/** \brief D64, MTL Queue 1 Transmit LoCredit Register */
#define GETH_MTL_TXQ1_LOCREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_LOCREDIT*)0xF001DD64u)

/** \brief D6C, MTL Queue 1 Interrupt Status Register */
#define GETH_MTL_Q1_INTERRUPT_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_Q_INTERRUPT_CONTROL_STATUS*)0xF001DD6Cu)

/** \brief D70, MTL Queue 1 Receive Operation Mode Register */
#define GETH_MTL_RXQ1_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_OPERATION_MODE*)0xF001DD70u)

/** \brief D74, MTL Queue 1 Receive Missed Packet and Overflow Counter Register */
#define GETH_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_MISSED_PACKET_OVERFLOW_CNT*)0xF001DD74u)

/** \brief D78, MTL Queue 1 Receive Debug Register */
#define GETH_MTL_RXQ1_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_DEBUG*)0xF001DD78u)

/** \brief D7C, MTL Queue 1 Receive Control Register */
#define GETH_MTL_RXQ1_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_CONTROL*)0xF001DD7Cu)

/** \brief D80, MTL Queue 2 Transmit Operation Mode Register */
#define GETH_MTL_TXQ2_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_OPERATION_MODE*)0xF001DD80u)

/** \brief D84, MTL Queue 2 Transmit Underflow Counter Register */
#define GETH_MTL_TXQ2_UNDERFLOW /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_UNDERFLOW*)0xF001DD84u)

/** \brief D88, MTL Queue 2 Transmit Debug Register */
#define GETH_MTL_TXQ2_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_DEBUG*)0xF001DD88u)

/** \brief D90, MTL Queue 2 Transmit ETS Control Register */
#define GETH_MTL_TXQ2_ETS_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_CONTROL*)0xF001DD90u)

/** \brief D94, MTL Queue 2 Transmit ETS Status Register */
#define GETH_MTL_TXQ2_ETS_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_STATUS*)0xF001DD94u)

/** \brief D98, MTL Queue 2 Transmit Quantum or Weights Register */
#define GETH_MTL_TXQ2_QUANTUM_WEIGHT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_QUANTUM_WEIGHT*)0xF001DD98u)

/** \brief D9C, MTL Queue 2 Transmit SendSlopeCredit Register */
#define GETH_MTL_TXQ2_SENDSLOPECREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_SENDSLOPECREDIT*)0xF001DD9Cu)

/** \brief DA0, MTL Queue 2 Transmit HiCredit Register */
#define GETH_MTL_TXQ2_HICREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_HICREDIT*)0xF001DDA0u)

/** \brief DA4, MTL Queue 2 Transmit LoCredit Register */
#define GETH_MTL_TXQ2_LOCREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_LOCREDIT*)0xF001DDA4u)

/** \brief DAC, MTL Queue 2 Interrupt Status Register */
#define GETH_MTL_Q2_INTERRUPT_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_Q_INTERRUPT_CONTROL_STATUS*)0xF001DDACu)

/** \brief DB0, MTL Queue 2 Receive Operation Mode Register */
#define GETH_MTL_RXQ2_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_OPERATION_MODE*)0xF001DDB0u)

/** \brief DB4, MTL Queue 2 Receive Missed Packet and Overflow Counter Register */
#define GETH_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_MISSED_PACKET_OVERFLOW_CNT*)0xF001DDB4u)

/** \brief DB8, MTL Queue 2 Receive Debug Register */
#define GETH_MTL_RXQ2_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_DEBUG*)0xF001DDB8u)

/** \brief DBC, MTL Queue 2 Receive Control Register */
#define GETH_MTL_RXQ2_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_CONTROL*)0xF001DDBCu)

/** \brief DC0, MTL Queue 3 Transmit Operation Mode Register */
#define GETH_MTL_TXQ3_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_OPERATION_MODE*)0xF001DDC0u)

/** \brief DC4, MTL Queue 3 Transmit Underflow Counter Register */
#define GETH_MTL_TXQ3_UNDERFLOW /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_UNDERFLOW*)0xF001DDC4u)

/** \brief DC8, MTL Queue 3 Transmit Debug Register */
#define GETH_MTL_TXQ3_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_DEBUG*)0xF001DDC8u)

/** \brief DD0, MTL Queue 3 Transmit ETS Control Register */
#define GETH_MTL_TXQ3_ETS_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_CONTROL*)0xF001DDD0u)

/** \brief DD4, MTL Queue 3 Transmit ETS Status Register */
#define GETH_MTL_TXQ3_ETS_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_ETS_STATUS*)0xF001DDD4u)

/** \brief DD8, MTL Queue 3 Transmit Quantum or Weights Register */
#define GETH_MTL_TXQ3_QUANTUM_WEIGHT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_QUANTUM_WEIGHT*)0xF001DDD8u)

/** \brief DDC, MTL Queue 3 Transmit SendSlopeCredit Register */
#define GETH_MTL_TXQ3_SENDSLOPECREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_SENDSLOPECREDIT*)0xF001DDDCu)

/** \brief DE0, MTL Queue 3 Transmit HiCredit Register */
#define GETH_MTL_TXQ3_HICREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_HICREDIT*)0xF001DDE0u)

/** \brief DE4, MTL Queue 3 Transmit LoCredit Register */
#define GETH_MTL_TXQ3_LOCREDIT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_TXQ_LOCREDIT*)0xF001DDE4u)

/** \brief DEC, MTL Queue 3 Interrupt Status Register */
#define GETH_MTL_Q3_INTERRUPT_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_Q_INTERRUPT_CONTROL_STATUS*)0xF001DDECu)

/** \brief DF0, MTL Queue 3 Receive Operation Mode Register */
#define GETH_MTL_RXQ3_OPERATION_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_OPERATION_MODE*)0xF001DDF0u)

/** \brief DF4, MTL Queue 3 Receive Missed Packet and Overflow Counter Register */
#define GETH_MTL_RXQ3_MISSED_PACKET_OVERFLOW_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_MISSED_PACKET_OVERFLOW_CNT*)0xF001DDF4u)

/** \brief DF8, MTL Queue 3 Receive Debug Register */
#define GETH_MTL_RXQ3_DEBUG /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_DEBUG*)0xF001DDF8u)

/** \brief DFC, MTL Queue 3 Receive Control Register */
#define GETH_MTL_RXQ3_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_MTL_RXQ_CONTROL*)0xF001DDFCu)

/** \brief 1000, DMA Bus Mode Register */
#define GETH_DMA_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_MODE*)0xF001E000u)

/** \brief 1004, DMA System Bus Mode Register */
#define GETH_DMA_SYSBUS_MODE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_SYSBUS_MODE*)0xF001E004u)

/** \brief 1008, DMA Interrupt Status Register */
#define GETH_DMA_INTERRUPT_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_INTERRUPT_STATUS*)0xF001E008u)

/** \brief 100C, DMA Debug Status 0 Register */
#define GETH_DMA_DEBUG_STATUS0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_DEBUG_STATUS0*)0xF001E00Cu)

/** \brief 1010, DMA Debug Status 1 Register */
#define GETH_DMA_DEBUG_STATUS1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_DEBUG_STATUS1*)0xF001E010u)

/** \brief 1100, DMA Channel 0 Control Register */
#define GETH_DMA_CH0_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CONTROL*)0xF001E100u)

/** \brief 1104, DMA Channel 0 Transmit Control Register */
#define GETH_DMA_CH0_TX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TX_CONTROL*)0xF001E104u)

/** \brief 1108, DMA Channel 0 Receive Control Register */
#define GETH_DMA_CH0_RX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_CONTROL*)0xF001E108u)

/** \brief 1114, DMA Channel 0 Transmit Descriptor List Address Register */
#define GETH_DMA_CH0_TXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_LIST_ADDRESS*)0xF001E114u)

/** \brief 111C, DMA Channel 0 Receive Descriptor List Address Register */
#define GETH_DMA_CH0_RXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_LIST_ADDRESS*)0xF001E11Cu)

/** \brief 1120, DMA Channel 0 Transmit Descriptor Tail Pointer Register */
#define GETH_DMA_CH0_TXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_TAIL_POINTER*)0xF001E120u)

/** \brief 1128, DMA Channel 0 Recieve Descriptor Tail Pointer Register */
#define GETH_DMA_CH0_RXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_TAIL_POINTER*)0xF001E128u)

/** \brief 112C, DMA Channel 0 Transmit Descriptor Ring Length Register */
#define GETH_DMA_CH0_TXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_RING_LENGTH*)0xF001E12Cu)

/** \brief 1130, DMA Channel 0 Recieve Descriptor Ring Length Register */
#define GETH_DMA_CH0_RXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_RING_LENGTH*)0xF001E130u)

/** \brief 1134, DMA Channel 0 Interrupt Enable Register */
#define GETH_DMA_CH0_INTERRUPT_ENABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_INTERRUPT_ENABLE*)0xF001E134u)

/** \brief 1138, DMA Channel 0 Recieve Interrupt Watchdog Timer Register */
#define GETH_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_INTERRUPT_WATCHDOG_TIMER*)0xF001E138u)

/** \brief 113C, DMA Channel 0 Slot Function Control and Status Register */
#define GETH_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_SLOT_FUNCTION_CONTROL_STATUS*)0xF001E13Cu)

/** \brief 1144, DMA Channel 0 Current Application Transmit Descriptor Register */
#define GETH_DMA_CH0_CURRENT_APP_TXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXDESC*)0xF001E144u)

/** \brief 114C, DMA Channel 0 Current Application Receive Descriptor Register */
#define GETH_DMA_CH0_CURRENT_APP_RXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXDESC*)0xF001E14Cu)

/** \brief 1154, DMA Channel 0 Current Application Transmit Buffer Address Register */
#define GETH_DMA_CH0_CURRENT_APP_TXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXBUFFER*)0xF001E154u)

/** \brief 115C, DMA Channel 0 Current Application Receive Buffer Address Register */
#define GETH_DMA_CH0_CURRENT_APP_RXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXBUFFER*)0xF001E15Cu)

/** \brief 1160, DMA Channel 0 Status Register */
#define GETH_DMA_CH0_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_STATUS*)0xF001E160u)

/** \brief 1164, DMA Channel 0 Missed Frames Count Register */
#define GETH_DMA_CH0_MISS_FRAME_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_MISS_FRAME_CNT*)0xF001E164u)

/** \brief 1180, DMA Channel 1 Control Register */
#define GETH_DMA_CH1_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CONTROL*)0xF001E180u)

/** \brief 1184, DMA Channel 1 Transmit Control Register */
#define GETH_DMA_CH1_TX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TX_CONTROL*)0xF001E184u)

/** \brief 1188, DMA Channel 1 Receive Control Register */
#define GETH_DMA_CH1_RX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_CONTROL*)0xF001E188u)

/** \brief 1194, DMA Channel 1 Transmit Descriptor List Address Register */
#define GETH_DMA_CH1_TXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_LIST_ADDRESS*)0xF001E194u)

/** \brief 119C, DMA Channel 1 Receive Descriptor List Address Register */
#define GETH_DMA_CH1_RXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_LIST_ADDRESS*)0xF001E19Cu)

/** \brief 11A0, DMA Channel 1 Transmit Descriptor Tail Pointer Register */
#define GETH_DMA_CH1_TXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_TAIL_POINTER*)0xF001E1A0u)

/** \brief 11A8, DMA Channel 1 Recieve Descriptor Tail Pointer Register */
#define GETH_DMA_CH1_RXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_TAIL_POINTER*)0xF001E1A8u)

/** \brief 11AC, DMA Channel 1 Transmit Descriptor Ring Length Register */
#define GETH_DMA_CH1_TXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_RING_LENGTH*)0xF001E1ACu)

/** \brief 11B0, DMA Channel 1 Recieve Descriptor Ring Length Register */
#define GETH_DMA_CH1_RXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_RING_LENGTH*)0xF001E1B0u)

/** \brief 11B4, DMA Channel 1 Interrupt Enable Register */
#define GETH_DMA_CH1_INTERRUPT_ENABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_INTERRUPT_ENABLE*)0xF001E1B4u)

/** \brief 11B8, DMA Channel 1 Recieve Interrupt Watchdog Timer Register */
#define GETH_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_INTERRUPT_WATCHDOG_TIMER*)0xF001E1B8u)

/** \brief 11BC, DMA Channel 1 Slot Function Control and Status Register */
#define GETH_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_SLOT_FUNCTION_CONTROL_STATUS*)0xF001E1BCu)

/** \brief 11C4, DMA Channel 1 Current Application Transmit Descriptor Register */
#define GETH_DMA_CH1_CURRENT_APP_TXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXDESC*)0xF001E1C4u)

/** \brief 11CC, DMA Channel 1 Current Application Receive Descriptor Register */
#define GETH_DMA_CH1_CURRENT_APP_RXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXDESC*)0xF001E1CCu)

/** \brief 11D4, DMA Channel 1 Current Application Transmit Buffer Address Register */
#define GETH_DMA_CH1_CURRENT_APP_TXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXBUFFER*)0xF001E1D4u)

/** \brief 11DC, DMA Channel 1 Current Application Receive Buffer Address Register */
#define GETH_DMA_CH1_CURRENT_APP_RXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXBUFFER*)0xF001E1DCu)

/** \brief 11E0, DMA Channel 1 Status Register */
#define GETH_DMA_CH1_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_STATUS*)0xF001E1E0u)

/** \brief 11E4, DMA Channel 1 Missed Frames Count Register */
#define GETH_DMA_CH1_MISS_FRAME_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_MISS_FRAME_CNT*)0xF001E1E4u)

/** \brief 1200, DMA Channel 2 Control Register */
#define GETH_DMA_CH2_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CONTROL*)0xF001E200u)

/** \brief 1204, DMA Channel 2 Transmit Control Register */
#define GETH_DMA_CH2_TX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TX_CONTROL*)0xF001E204u)

/** \brief 1208, DMA Channel 2 Receive Control Register */
#define GETH_DMA_CH2_RX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_CONTROL*)0xF001E208u)

/** \brief 1214, DMA Channel 2 Transmit Descriptor List Address Register */
#define GETH_DMA_CH2_TXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_LIST_ADDRESS*)0xF001E214u)

/** \brief 121C, DMA Channel 2 Receive Descriptor List Address Register */
#define GETH_DMA_CH2_RXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_LIST_ADDRESS*)0xF001E21Cu)

/** \brief 1220, DMA Channel 2 Transmit Descriptor Tail Pointer Register */
#define GETH_DMA_CH2_TXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_TAIL_POINTER*)0xF001E220u)

/** \brief 1228, DMA Channel 2 Recieve Descriptor Tail Pointer Register */
#define GETH_DMA_CH2_RXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_TAIL_POINTER*)0xF001E228u)

/** \brief 122C, DMA Channel 2 Transmit Descriptor Ring Length Register */
#define GETH_DMA_CH2_TXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_RING_LENGTH*)0xF001E22Cu)

/** \brief 1230, DMA Channel 2 Recieve Descriptor Ring Length Register */
#define GETH_DMA_CH2_RXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_RING_LENGTH*)0xF001E230u)

/** \brief 1234, DMA Channel 2 Interrupt Enable Register */
#define GETH_DMA_CH2_INTERRUPT_ENABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_INTERRUPT_ENABLE*)0xF001E234u)

/** \brief 1238, DMA Channel 2 Recieve Interrupt Watchdog Timer Register */
#define GETH_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_INTERRUPT_WATCHDOG_TIMER*)0xF001E238u)

/** \brief 123C, DMA Channel 2 Slot Function Control and Status Register */
#define GETH_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_SLOT_FUNCTION_CONTROL_STATUS*)0xF001E23Cu)

/** \brief 1244, DMA Channel 2 Current Application Transmit Descriptor Register */
#define GETH_DMA_CH2_CURRENT_APP_TXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXDESC*)0xF001E244u)

/** \brief 124C, DMA Channel 2 Current Application Receive Descriptor Register */
#define GETH_DMA_CH2_CURRENT_APP_RXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXDESC*)0xF001E24Cu)

/** \brief 1254, DMA Channel 2 Current Application Transmit Buffer Address Register */
#define GETH_DMA_CH2_CURRENT_APP_TXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXBUFFER*)0xF001E254u)

/** \brief 125C, DMA Channel 2 Current Application Receive Buffer Address Register */
#define GETH_DMA_CH2_CURRENT_APP_RXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXBUFFER*)0xF001E25Cu)

/** \brief 1260, DMA Channel 2 Status Register */
#define GETH_DMA_CH2_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_STATUS*)0xF001E260u)

/** \brief 1264, DMA Channel 2 Missed Frames Count Register */
#define GETH_DMA_CH2_MISS_FRAME_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_MISS_FRAME_CNT*)0xF001E264u)

/** \brief 1280, DMA Channel 3 Control Register */
#define GETH_DMA_CH3_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CONTROL*)0xF001E280u)

/** \brief 1284, DMA Channel 3 Transmit Control Register */
#define GETH_DMA_CH3_TX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TX_CONTROL*)0xF001E284u)

/** \brief 1288, DMA Channel 3 Receive Control Register */
#define GETH_DMA_CH3_RX_CONTROL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_CONTROL*)0xF001E288u)

/** \brief 1294, DMA Channel 3 Transmit Descriptor List Address Register */
#define GETH_DMA_CH3_TXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_LIST_ADDRESS*)0xF001E294u)

/** \brief 129C, DMA Channel 3 Receive Descriptor List Address Register */
#define GETH_DMA_CH3_RXDESC_LIST_ADDRESS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_LIST_ADDRESS*)0xF001E29Cu)

/** \brief 12A0, DMA Channel 3 Transmit Descriptor Tail Pointer Register */
#define GETH_DMA_CH3_TXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_TAIL_POINTER*)0xF001E2A0u)

/** \brief 12A8, DMA Channel 3 Recieve Descriptor Tail Pointer Register */
#define GETH_DMA_CH3_RXDESC_TAIL_POINTER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_TAIL_POINTER*)0xF001E2A8u)

/** \brief 12AC, DMA Channel 3 Transmit Descriptor Ring Length Register */
#define GETH_DMA_CH3_TXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_TXDESC_RING_LENGTH*)0xF001E2ACu)

/** \brief 12B0, DMA Channel 3 Recieve Descriptor Ring Length Register */
#define GETH_DMA_CH3_RXDESC_RING_LENGTH /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RXDESC_RING_LENGTH*)0xF001E2B0u)

/** \brief 12B4, DMA Channel 3 Interrupt Enable Register */
#define GETH_DMA_CH3_INTERRUPT_ENABLE /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_INTERRUPT_ENABLE*)0xF001E2B4u)

/** \brief 12B8, DMA Channel 3 Recieve Interrupt Watchdog Timer Register */
#define GETH_DMA_CH3_RX_INTERRUPT_WATCHDOG_TIMER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_RX_INTERRUPT_WATCHDOG_TIMER*)0xF001E2B8u)

/** \brief 12BC, DMA Channel 3 Slot Function Control and Status Register */
#define GETH_DMA_CH3_SLOT_FUNCTION_CONTROL_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_SLOT_FUNCTION_CONTROL_STATUS*)0xF001E2BCu)

/** \brief 12C4, DMA Channel 3 Current Application Transmit Descriptor Register */
#define GETH_DMA_CH3_CURRENT_APP_TXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXDESC*)0xF001E2C4u)

/** \brief 12CC, DMA Channel 3 Current Application Receive Descriptor Register */
#define GETH_DMA_CH3_CURRENT_APP_RXDESC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXDESC*)0xF001E2CCu)

/** \brief 12D4, DMA Channel 3 Current Application Transmit Buffer Address Register */
#define GETH_DMA_CH3_CURRENT_APP_TXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_TXBUFFER*)0xF001E2D4u)

/** \brief 12DC, DMA Channel 3 Current Application Receive Buffer Address Register */
#define GETH_DMA_CH3_CURRENT_APP_RXBUFFER /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_CURRENT_APP_RXBUFFER*)0xF001E2DCu)

/** \brief 12E0, DMA Channel 3 Status Register */
#define GETH_DMA_CH3_STATUS /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_STATUS*)0xF001E2E0u)

/** \brief 12E4, DMA Channel 3 Missed Frames Count Register */
#define GETH_DMA_CH3_MISS_FRAME_CNT /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_DMA_CH_MISS_FRAME_CNT*)0xF001E2E4u)

/** \brief 0, Clock Control Register */
#define GETH_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_CLC*)0xF001F000u)

/** \brief 4, Module Identification Register */
#define GETH_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ID*)0xF001F004u)

/** \brief 8, General Purpose Control Register */
#define GETH_GPCTL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_GPCTL*)0xF001F008u)

/** \brief C, Access Enable Register 0 */
#define GETH_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEN0*)0xF001F00Cu)

/** \brief 10, Access Enable Register 1 */
#define GETH_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEN1*)0xF001F010u)

/** \brief 14, Kernel Reset Register 0 */
#define GETH_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_KRST0*)0xF001F014u)

/** \brief 18, Kernel Reset Register 1 */
#define GETH_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_KRST1*)0xF001F018u)

/** \brief 1C, Kernel Reset Status Clear Register */
#define GETH_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_KRSTCLR*)0xF001F01Cu)

/** \brief 20, Access Enable Register 0 for DMA0 */
#define GETH_ACCEND0_ACCEN0D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN0D*)0xF001F020u)
/** Alias (User Manual Name) for GETH_ACCEND0_ACCEN0D.
* To use register names with standard convension, please use GETH_ACCEND0_ACCEN0D.
*/
#define GETH_ACCEN0D0 (GETH_ACCEND0_ACCEN0D)

/** \brief 24, Access Enable Register 1 for DMA0 */
#define GETH_ACCEND0_ACCEN1D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN1D*)0xF001F024u)
/** Alias (User Manual Name) for GETH_ACCEND0_ACCEN1D.
* To use register names with standard convension, please use GETH_ACCEND0_ACCEN1D.
*/
#define GETH_ACCEN1D0 (GETH_ACCEND0_ACCEN1D)

/** \brief 28, Access Enable Register 0 for DMA1 */
#define GETH_ACCEND1_ACCEN0D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN0D*)0xF001F028u)
/** Alias (User Manual Name) for GETH_ACCEND1_ACCEN0D.
* To use register names with standard convension, please use GETH_ACCEND1_ACCEN0D.
*/
#define GETH_ACCEN0D1 (GETH_ACCEND1_ACCEN0D)

/** \brief 2C, Access Enable Register 1 for DMA1 */
#define GETH_ACCEND1_ACCEN1D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN1D*)0xF001F02Cu)
/** Alias (User Manual Name) for GETH_ACCEND1_ACCEN1D.
* To use register names with standard convension, please use GETH_ACCEND1_ACCEN1D.
*/
#define GETH_ACCEN1D1 (GETH_ACCEND1_ACCEN1D)

/** \brief 30, Access Enable Register 0 for DMA2 */
#define GETH_ACCEND2_ACCEN0D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN0D*)0xF001F030u)
/** Alias (User Manual Name) for GETH_ACCEND2_ACCEN0D.
* To use register names with standard convension, please use GETH_ACCEND2_ACCEN0D.
*/
#define GETH_ACCEN0D2 (GETH_ACCEND2_ACCEN0D)

/** \brief 34, Access Enable Register 1 for DMA2 */
#define GETH_ACCEND2_ACCEN1D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN1D*)0xF001F034u)
/** Alias (User Manual Name) for GETH_ACCEND2_ACCEN1D.
* To use register names with standard convension, please use GETH_ACCEND2_ACCEN1D.
*/
#define GETH_ACCEN1D2 (GETH_ACCEND2_ACCEN1D)

/** \brief 38, Access Enable Register 0 for DMA3 */
#define GETH_ACCEND3_ACCEN0D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN0D*)0xF001F038u)
/** Alias (User Manual Name) for GETH_ACCEND3_ACCEN0D.
* To use register names with standard convension, please use GETH_ACCEND3_ACCEN0D.
*/
#define GETH_ACCEN0D3 (GETH_ACCEND3_ACCEN0D)

/** \brief 3C, Access Enable Register 1 for DMA3 */
#define GETH_ACCEND3_ACCEN1D /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_ACCEND_ACCEN1D*)0xF001F03Cu)
/** Alias (User Manual Name) for GETH_ACCEND3_ACCEN1D.
* To use register names with standard convension, please use GETH_ACCEND3_ACCEN1D.
*/
#define GETH_ACCEN1D3 (GETH_ACCEND3_ACCEN1D)

/** \brief 40, Skew Control Register */
#define GETH_SKEWCTL /*lint --e(923, 9078)*/ (*(volatile Ifx_GETH_SKEWCTL*)0xF001F040u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXGETH_REG_H */

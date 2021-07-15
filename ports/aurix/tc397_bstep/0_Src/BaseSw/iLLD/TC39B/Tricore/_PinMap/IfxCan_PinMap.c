/**
 * \file IfxCan_PinMap.c
 * \brief CAN I/O map
 * \ingroup IfxLld_Can
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
 */

#include "IfxCan_PinMap.h"

IfxCan_Rxd_In IfxCan_RXD00A_P02_1_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P02, 1}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD00B_P20_7_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P20, 7}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD00C_P12_0_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P12, 0}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD00D_P33_12_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P33,12}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD00E_P33_7_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P33, 7}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD00F_P01_8_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P01, 8}, Ifx_RxSel_f};
IfxCan_Rxd_In IfxCan_RXD00G_P34_2_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P34, 2}, Ifx_RxSel_g};
IfxCan_Rxd_In IfxCan_RXD00H_P02_14_IN = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P02,14}, Ifx_RxSel_h};
IfxCan_Rxd_In IfxCan_RXD01A_P15_3_IN = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P15, 3}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD01B_P14_1_IN = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P14, 1}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD01C_P01_4_IN = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P01, 4}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD01D_P33_10_IN = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P33,10}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD01E_P02_10_IN = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P02,10}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD02A_P15_1_IN = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P15, 1}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD02B_P02_3_IN = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P02, 3}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD02C_P32_6_IN = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P32, 6}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD02D_P14_8_IN = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P14, 8}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD02E_P10_2_IN = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P10, 2}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD03A_P00_3_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD03B_P32_2_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P32, 2}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD03C_P20_0_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P20, 0}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD03D_P11_10_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P11,10}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD03E_P20_9_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P20, 9}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD03F_P01_0_IN = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P01, 0}, Ifx_RxSel_f};
IfxCan_Rxd_In IfxCan_RXD10A_P00_1_IN = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P00, 1}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD10B_P14_7_IN = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P14, 7}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD10C_P23_0_IN = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P23, 0}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD10D_P13_1_IN = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P13, 1}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD11A_P02_4_IN = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P02, 4}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD11B_P00_5_IN = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P00, 5}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD11C_P23_7_IN = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P23, 7}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD11D_P11_7_IN = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P11, 7}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD12A_P20_6_IN = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P20, 6}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD12B_P10_8_IN = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P10, 8}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD12C_P23_3_IN = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P23, 3}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD12D_P11_8_IN = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P11, 8}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD13A_P14_7_IN = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P14, 7}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD13B_P33_5_IN = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P33, 5}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD13C_P22_5_IN = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P22, 5}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD13D_P11_13_IN = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P11,13}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD20A_P10_5_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P10, 5}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD20B_P10_8_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P10, 8}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD20C_P34_2_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P34, 2}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD20D_P02_14_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P02,14}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD20E_P01_8_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P01, 8}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD20F_P11_14_IN = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P11,14}, Ifx_RxSel_f};
IfxCan_Rxd_In IfxCan_RXD21A_P00_3_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD21B_P13_12_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P13,12}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD21C_P20_0_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P20, 0}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD21D_P32_2_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P32, 2}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD21E_P01_0_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P01, 0}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD21F_P22_7_IN = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P22, 7}, Ifx_RxSel_f};
IfxCan_Rxd_In IfxCan_RXD22A_P33_13_IN = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P33,13}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD22B_P32_7_IN = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P32, 7}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD22C_P23_6_IN = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P23, 6}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD22D_P14_14_IN = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P14,14}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD22E_P22_9_IN = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P22, 9}, Ifx_RxSel_e};
IfxCan_Rxd_In IfxCan_RXD23A_P14_10_IN = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P14,10}, Ifx_RxSel_a};
IfxCan_Rxd_In IfxCan_RXD23B_P23_3_IN = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P23, 3}, Ifx_RxSel_b};
IfxCan_Rxd_In IfxCan_RXD23C_P14_15_IN = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P14,15}, Ifx_RxSel_c};
IfxCan_Rxd_In IfxCan_RXD23D_P13_5_IN = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P13, 5}, Ifx_RxSel_d};
IfxCan_Rxd_In IfxCan_RXD23E_P22_11_IN = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P22,11}, Ifx_RxSel_e};
IfxCan_Txd_Out IfxCan_TXD00_P01_13_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P01,13}, IfxPort_OutputIdx_alt4};
IfxCan_Txd_Out IfxCan_TXD00_P02_0_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P02, 0}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD00_P02_13_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P02,13}, IfxPort_OutputIdx_alt4};
IfxCan_Txd_Out IfxCan_TXD00_P12_1_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P12, 1}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD00_P20_8_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P20, 8}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD00_P33_13_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P33,13}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD00_P33_8_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P33, 8}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD00_P34_1_OUT = {&MODULE_CAN0, IfxCan_NodeId_0, {&MODULE_P34, 1}, IfxPort_OutputIdx_alt4};
IfxCan_Txd_Out IfxCan_TXD01_P01_3_OUT = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P01, 3}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD01_P02_9_OUT = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P02, 9}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD01_P14_0_OUT = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P14, 0}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD01_P15_2_OUT = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P15, 2}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD01_P33_9_OUT = {&MODULE_CAN0, IfxCan_NodeId_1, {&MODULE_P33, 9}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD02_P02_2_OUT = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD02_P10_3_OUT = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P10, 3}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD02_P14_10_OUT = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P14,10}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD02_P15_0_OUT = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P15, 0}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD02_P32_5_OUT = {&MODULE_CAN0, IfxCan_NodeId_2, {&MODULE_P32, 5}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD03_P00_2_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P00, 2}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD03_P01_2_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P01, 2}, IfxPort_OutputIdx_alt3};
IfxCan_Txd_Out IfxCan_TXD03_P11_12_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P11,12}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD03_P20_10_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P20,10}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD03_P20_3_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P20, 3}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD03_P32_3_OUT = {&MODULE_CAN0, IfxCan_NodeId_3, {&MODULE_P32, 3}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD10_P00_0_OUT = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P00, 0}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD10_P13_0_OUT = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P13, 0}, IfxPort_OutputIdx_alt7};
IfxCan_Txd_Out IfxCan_TXD10_P14_9_OUT = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt4};
IfxCan_Txd_Out IfxCan_TXD10_P23_1_OUT = {&MODULE_CAN1, IfxCan_NodeId_0, {&MODULE_P23, 1}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD11_P00_4_OUT = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt3};
IfxCan_Txd_Out IfxCan_TXD11_P02_5_OUT = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P02, 5}, IfxPort_OutputIdx_alt2};
IfxCan_Txd_Out IfxCan_TXD11_P11_0_OUT = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P11, 0}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD11_P23_6_OUT = {&MODULE_CAN1, IfxCan_NodeId_1, {&MODULE_P23, 6}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD12_P10_7_OUT = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P10, 7}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD12_P11_1_OUT = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P11, 1}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD12_P20_7_OUT = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P20, 7}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD12_P23_2_OUT = {&MODULE_CAN1, IfxCan_NodeId_2, {&MODULE_P23, 2}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD13_P11_4_OUT = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P11, 4}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD13_P14_6_OUT = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P14, 6}, IfxPort_OutputIdx_alt4};
IfxCan_Txd_Out IfxCan_TXD13_P22_4_OUT = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P22, 4}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD13_P33_4_OUT = {&MODULE_CAN1, IfxCan_NodeId_3, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt7};
IfxCan_Txd_Out IfxCan_TXD20_P01_13_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P01,13}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD20_P02_13_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P02,13}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD20_P10_6_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P10, 6}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD20_P10_7_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P10, 7}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD20_P11_5_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P11, 5}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD20_P34_1_OUT = {&MODULE_CAN2, IfxCan_NodeId_0, {&MODULE_P34, 1}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD21_P00_2_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P00, 2}, IfxPort_OutputIdx_alt3};
IfxCan_Txd_Out IfxCan_TXD21_P01_2_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P01, 2}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD21_P13_9_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P13, 9}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD21_P20_3_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P20, 3}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD21_P22_6_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P22, 6}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD21_P32_3_OUT = {&MODULE_CAN2, IfxCan_NodeId_1, {&MODULE_P32, 3}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD22_P14_13_OUT = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P14,13}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD22_P22_8_OUT = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P22, 8}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD22_P23_5_OUT = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P23, 5}, IfxPort_OutputIdx_alt6};
IfxCan_Txd_Out IfxCan_TXD22_P32_6_OUT = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P32, 6}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD22_P33_12_OUT = {&MODULE_CAN2, IfxCan_NodeId_2, {&MODULE_P33,12}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD23_P13_4_OUT = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P13, 4}, IfxPort_OutputIdx_alt7};
IfxCan_Txd_Out IfxCan_TXD23_P14_14_OUT = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P14,14}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD23_P14_9_OUT = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt2};
IfxCan_Txd_Out IfxCan_TXD23_P22_10_OUT = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P22,10}, IfxPort_OutputIdx_alt5};
IfxCan_Txd_Out IfxCan_TXD23_P23_2_OUT = {&MODULE_CAN2, IfxCan_NodeId_3, {&MODULE_P23, 2}, IfxPort_OutputIdx_alt4};


const IfxCan_Rxd_In *IfxCan_Rxd_In_pinTable[IFXCAN_PINMAP_NUM_MODULES][IFXCAN_PINMAP_NUM_NODES][IFXCAN_PINMAP_RXD_IN_NUM_ITEMS] = {
    {
        {
            &IfxCan_RXD00A_P02_1_IN,
            &IfxCan_RXD00B_P20_7_IN,
            &IfxCan_RXD00C_P12_0_IN,
            &IfxCan_RXD00D_P33_12_IN,
            &IfxCan_RXD00E_P33_7_IN,
            &IfxCan_RXD00F_P01_8_IN,
            &IfxCan_RXD00G_P34_2_IN,
            &IfxCan_RXD00H_P02_14_IN
        },
        {
            &IfxCan_RXD01A_P15_3_IN,
            &IfxCan_RXD01B_P14_1_IN,
            &IfxCan_RXD01C_P01_4_IN,
            &IfxCan_RXD01D_P33_10_IN,
            &IfxCan_RXD01E_P02_10_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD02A_P15_1_IN,
            &IfxCan_RXD02B_P02_3_IN,
            &IfxCan_RXD02C_P32_6_IN,
            &IfxCan_RXD02D_P14_8_IN,
            &IfxCan_RXD02E_P10_2_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD03A_P00_3_IN,
            &IfxCan_RXD03B_P32_2_IN,
            &IfxCan_RXD03C_P20_0_IN,
            &IfxCan_RXD03D_P11_10_IN,
            &IfxCan_RXD03E_P20_9_IN,
            &IfxCan_RXD03F_P01_0_IN,
            NULL_PTR,
            NULL_PTR
        }
    },
    {
        {
            &IfxCan_RXD10A_P00_1_IN,
            &IfxCan_RXD10B_P14_7_IN,
            &IfxCan_RXD10C_P23_0_IN,
            &IfxCan_RXD10D_P13_1_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD11A_P02_4_IN,
            &IfxCan_RXD11B_P00_5_IN,
            &IfxCan_RXD11C_P23_7_IN,
            &IfxCan_RXD11D_P11_7_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD12A_P20_6_IN,
            &IfxCan_RXD12B_P10_8_IN,
            &IfxCan_RXD12C_P23_3_IN,
            &IfxCan_RXD12D_P11_8_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD13A_P14_7_IN,
            &IfxCan_RXD13B_P33_5_IN,
            &IfxCan_RXD13C_P22_5_IN,
            &IfxCan_RXD13D_P11_13_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    },
    {
        {
            &IfxCan_RXD20A_P10_5_IN,
            &IfxCan_RXD20B_P10_8_IN,
            &IfxCan_RXD20C_P34_2_IN,
            &IfxCan_RXD20D_P02_14_IN,
            &IfxCan_RXD20E_P01_8_IN,
            &IfxCan_RXD20F_P11_14_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD21A_P00_3_IN,
            &IfxCan_RXD21B_P13_12_IN,
            &IfxCan_RXD21C_P20_0_IN,
            &IfxCan_RXD21D_P32_2_IN,
            &IfxCan_RXD21E_P01_0_IN,
            &IfxCan_RXD21F_P22_7_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD22A_P33_13_IN,
            &IfxCan_RXD22B_P32_7_IN,
            &IfxCan_RXD22C_P23_6_IN,
            &IfxCan_RXD22D_P14_14_IN,
            &IfxCan_RXD22E_P22_9_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_RXD23A_P14_10_IN,
            &IfxCan_RXD23B_P23_3_IN,
            &IfxCan_RXD23C_P14_15_IN,
            &IfxCan_RXD23D_P13_5_IN,
            &IfxCan_RXD23E_P22_11_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};

const IfxCan_Txd_Out *IfxCan_Txd_Out_pinTable[IFXCAN_PINMAP_NUM_MODULES][IFXCAN_PINMAP_NUM_NODES][IFXCAN_PINMAP_TXD_OUT_NUM_ITEMS] = {
    {
        {
            &IfxCan_TXD00_P01_13_OUT,
            &IfxCan_TXD00_P02_0_OUT,
            &IfxCan_TXD00_P02_13_OUT,
            &IfxCan_TXD00_P12_1_OUT,
            &IfxCan_TXD00_P20_8_OUT,
            &IfxCan_TXD00_P33_8_OUT,
            &IfxCan_TXD00_P33_13_OUT,
            &IfxCan_TXD00_P34_1_OUT
        },
        {
            &IfxCan_TXD01_P01_3_OUT,
            &IfxCan_TXD01_P02_9_OUT,
            &IfxCan_TXD01_P14_0_OUT,
            &IfxCan_TXD01_P15_2_OUT,
            &IfxCan_TXD01_P33_9_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD02_P02_2_OUT,
            &IfxCan_TXD02_P10_3_OUT,
            &IfxCan_TXD02_P14_10_OUT,
            &IfxCan_TXD02_P15_0_OUT,
            &IfxCan_TXD02_P32_5_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD03_P00_2_OUT,
            &IfxCan_TXD03_P01_2_OUT,
            &IfxCan_TXD03_P11_12_OUT,
            &IfxCan_TXD03_P20_3_OUT,
            &IfxCan_TXD03_P20_10_OUT,
            &IfxCan_TXD03_P32_3_OUT,
            NULL_PTR,
            NULL_PTR
        }
    },
    {
        {
            &IfxCan_TXD10_P00_0_OUT,
            &IfxCan_TXD10_P13_0_OUT,
            &IfxCan_TXD10_P14_9_OUT,
            &IfxCan_TXD10_P23_1_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD11_P00_4_OUT,
            &IfxCan_TXD11_P02_5_OUT,
            &IfxCan_TXD11_P11_0_OUT,
            &IfxCan_TXD11_P23_6_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD12_P10_7_OUT,
            &IfxCan_TXD12_P11_1_OUT,
            &IfxCan_TXD12_P20_7_OUT,
            &IfxCan_TXD12_P23_2_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD13_P11_4_OUT,
            &IfxCan_TXD13_P14_6_OUT,
            &IfxCan_TXD13_P22_4_OUT,
            &IfxCan_TXD13_P33_4_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    },
    {
        {
            &IfxCan_TXD20_P01_13_OUT,
            &IfxCan_TXD20_P02_13_OUT,
            &IfxCan_TXD20_P10_6_OUT,
            &IfxCan_TXD20_P10_7_OUT,
            &IfxCan_TXD20_P11_5_OUT,
            &IfxCan_TXD20_P34_1_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD21_P00_2_OUT,
            &IfxCan_TXD21_P01_2_OUT,
            &IfxCan_TXD21_P13_9_OUT,
            &IfxCan_TXD21_P20_3_OUT,
            &IfxCan_TXD21_P22_6_OUT,
            &IfxCan_TXD21_P32_3_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD22_P14_13_OUT,
            &IfxCan_TXD22_P22_8_OUT,
            &IfxCan_TXD22_P23_5_OUT,
            &IfxCan_TXD22_P32_6_OUT,
            &IfxCan_TXD22_P33_12_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxCan_TXD23_P13_4_OUT,
            &IfxCan_TXD23_P14_9_OUT,
            &IfxCan_TXD23_P14_14_OUT,
            &IfxCan_TXD23_P22_10_OUT,
            &IfxCan_TXD23_P23_2_OUT,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};

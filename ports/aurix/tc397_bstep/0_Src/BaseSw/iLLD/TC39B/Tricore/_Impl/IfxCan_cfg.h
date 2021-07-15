/**
 * \file IfxCan_cfg.h
 * \brief CAN on-chip implementation data
 * \ingroup IfxLld_Can
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 *
 *
 * \defgroup IfxLld_Can CAN
 * \ingroup IfxLld
 * \defgroup IfxLld_Can_Impl Implementation Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Std Standard Interface
 * \ingroup IfxLld_Can
 * \defgroup IfxLld_Can_Impl_Enum Enumerations
 * \ingroup IfxLld_Can_Impl
 */

#ifndef IFXCAN_CFG_H
#define IFXCAN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCan_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CAN modules
 */
#define IFXCAN_NUM_MODULES (3)

/** \brief Number of nodes per each CAN module
 */
#define IFXCAN_NUM_NODES   4

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Can_Impl_Enum
 * \{ */
/** \brief List of the available can resources
 */
typedef enum
{
    IfxCan_Index_none = -1,  /**< \brief Not Selected */
    IfxCan_Index_0    = 0,   /**< \brief CAN index 0  */
    IfxCan_Index_1,          /**< \brief CAN index 1  */
    IfxCan_Index_2           /**< \brief CAN index 2  */
} IfxCan_Index;

/** \brief CAN Node number
 */
typedef enum
{
    IfxCan_NodeId_none = -1, /**< \brief None of the CAN Nodes */
    IfxCan_NodeId_0,         /**< \brief Node Id 0  */
    IfxCan_NodeId_1,         /**< \brief Node Id 1  */
    IfxCan_NodeId_2,         /**< \brief Node Id 2  */
    IfxCan_NodeId_3          /**< \brief Node Id 3  */
} IfxCan_NodeId;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxCan_cfg_indexMap[IFXCAN_NUM_MODULES];

#endif /* IFXCAN_CFG_H */

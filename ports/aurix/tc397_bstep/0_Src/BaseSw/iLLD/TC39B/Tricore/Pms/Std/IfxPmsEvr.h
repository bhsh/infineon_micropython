/**
 * \file IfxPmsEvr.h
 * \brief PMS  basic functionality
 * \ingroup IfxLld_Pms
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
 * \defgroup IfxLld_Pms_Std_Evr EVR
 * \ingroup IfxLld_Pms_Std
 * \defgroup IfxLld_Pms_Std_Evr_Enum Enumerations
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Over-Voltage Over Voltage Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Module Module Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Under-Voltage Under Voltage Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_EVRC EVRC Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_EVR33 EVR33 Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_SWD SWD Functions
 * \ingroup IfxLld_Pms_Std_Evr
 */

#ifndef IFXPMSEVR_H
#define IFXPMSEVR_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPms_cfg.h"
#include "Cpu/Std/IfxCpu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPms_bf.h"
#include "IfxPms_reg.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPMSEVR_ADC_VDD_LSB               (0.005f)

#define IFXPMSEVR_ADC_VDDP3_LSB             (0.015f)

#define IFXPMSEVR_ADC_VEXT_LSB              (0.02f)

#define IFXPMSEVR_CTRL_UP_WAIT_TIMEOUTCOUNT (0x100)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pms_Std_Evr_Enum
 * \{ */
/** \brief Configure respective interrupts define in register Ifx_PMS.PMSIEN
 */
typedef enum
{
    IfxPmsEvr_EnableInterrupt_ovswd   = 0,   /**< \brief OVSWD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvswd   = 1,   /**< \brief UVSWD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ov33    = 2,   /**< \brief OV33Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uv33    = 3,   /**< \brief UV33 Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovc     = 4,   /**< \brief OVC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvc     = 5,   /**< \brief UVC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovpre   = 6,   /**< \brief OVPRE Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvpre   = 7,   /**< \brief UVPRE Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovddm   = 8,   /**< \brief OVDDM Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvddm   = 9,   /**< \brief UVDDM Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovsb    = 10,  /**< \brief OVSB Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvsb    = 11,  /**< \brief UVSB Interrupt enable */
    IfxPmsEvr_EnableInterrupt_evrcmod = 16,  /**< \brief EVRCMOD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_sdvok   = 17,  /**< \brief SDVOK Interrupt enable */
    IfxPmsEvr_EnableInterrupt_synclck = 18,  /**< \brief SD SYNCLCK Interrupt enable */
    IfxPmsEvr_EnableInterrupt_swdlvl  = 19,  /**< \brief SWDLVL Interrupt enable */
    IfxPmsEvr_EnableInterrupt_wutwkp  = 21,  /**< \brief WUT WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_esr0wkp = 22,  /**< \brief ESR0 WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_esr1wkp = 23,  /**< \brief ESR1 WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_pinawkp = 24,  /**< \brief PINA WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_pinbwkp = 25,  /**< \brief PINB WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrint  = 26,  /**< \brief SCR INT Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrrst  = 27,  /**< \brief SCR RST Interrupt enable */
    IfxPmsEvr_EnableInterrupt_screcc  = 28,  /**< \brief SCR ECC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrwdt  = 29   /**< \brief SCR WDT Interrupt enable */
} IfxPmsEvr_EnableInterrupt;

/** \brief Current operation mode of EVRC Regulator defined in Ifx_PMS.EVR.STAT.B.EVRCMOD
 */
typedef enum
{
    IfxPmsEvr_EvrcMode_pwmMode      = 0,  /**< \brief The step-down converter is in
                                          * normal operational closed loop state */
    IfxPmsEvr_EvrcMode_lowPowerMode = 1,  /**< \brief The step-down converter is in low
                                           * power state */
    IfxPmsEvr_EvrcMode_startupMode  = 2,  /**< \brief The step-down converter is in start-up
                                           * phase */
    IfxPmsEvr_EvrcMode_disableMode  = 3   /**< \brief EVRC is Disable */
} IfxPmsEvr_EvrcMode;

/** \brief Switching frequency division factor for external synchronisation
 * defined in Ifx_PMS.EVRSDCTRL7.B.SYNCDIVFAC
 */
typedef enum
{
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_1  = 0,  /**< \brief fDCDCSYNC = fDCDC. The actual duty cycle is routed. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_2  = 1,  /**< \brief fDCDCSYNC = fDCDC/2. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_4  = 2,  /**< \brief fDCDCSYNC = fDCDC/4. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_8  = 3,  /**< \brief fDCDCSYNC = fDCDC/8. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_16 = 4,  /**< \brief fDCDCSYNC = fDCDC/16. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_32 = 5   /**< \brief fDCDCSYNC = fDCDC/32. Duty cycle is constant at 50%. */
} IfxPmsEvr_ExtSyncSwitchingFreqDivFactor;

/** \brief Monitoring OverVoltage for all bitfields defined
 * in .Ifx_PMS.EVR.MONCTRL register for overvoltage monitoring
 */
typedef enum
{
    IfxPmsEvr_OverVoltageMonitoring_inactive                         = 0, /**< \brief Over-Voltage Monitoring inactive */
    IfxPmsEvr_OverVoltageMonitoring_lowToHighVoltageTransition       = 1, /**< \brief Over-Voltage event is generated when threshold is crossed in lower to higher voltage transition */
    IfxPmsEvr_OverVoltageMonitoring_highToLowVoltageTransition       = 2, /**< \brief Over-Voltage event is generated when threshold is crossed in higher to lower voltage transition */
    IfxPmsEvr_OverVoltageMonitoring_eitherDirectionVoltageTransition = 3  /**< \brief Over-Voltage event is generated when threshold is crossed in either direction */
} IfxPmsEvr_OverVoltageMonitoring;

/** \brief set TRIM Value For respective Voltages.
 * Defined in Ifx_PMS.EVR.TRIM and Ifx_PMS.EVR.TRIM2
 */
typedef enum
{
    IfxPmsEvr_PrimaryAdcTrimValue_0 = 0,      /**< \brief Primary Adc Trim Value 0  */
    IfxPmsEvr_PrimaryAdcTrimValue_1,          /**< \brief Primary Adc Trim Value 1  */
    IfxPmsEvr_PrimaryAdcTrimValue_2,          /**< \brief Primary Adc Trim Value 2  */
    IfxPmsEvr_PrimaryAdcTrimValue_3,          /**< \brief Primary Adc Trim Value 3  */
    IfxPmsEvr_PrimaryAdcTrimValue_4,          /**< \brief Primary Adc Trim Value 4  */
    IfxPmsEvr_PrimaryAdcTrimValue_5,          /**< \brief Primary Adc Trim Value 5  */
    IfxPmsEvr_PrimaryAdcTrimValue_6,          /**< \brief Primary Adc Trim Value 6  */
    IfxPmsEvr_PrimaryAdcTrimValue_7,          /**< \brief Primary Adc Trim Value 7  */
    IfxPmsEvr_PrimaryAdcTrimValue_8,          /**< \brief Primary Adc Trim Value 8  */
    IfxPmsEvr_PrimaryAdcTrimValue_9,          /**< \brief Primary Adc Trim Value 9  */
    IfxPmsEvr_PrimaryAdcTrimValue_10,         /**< \brief Primary Adc Trim Value 10  */
    IfxPmsEvr_PrimaryAdcTrimValue_11,         /**< \brief Primary Adc Trim Value 11  */
    IfxPmsEvr_PrimaryAdcTrimValue_12,         /**< \brief Primary Adc Trim Value 12  */
    IfxPmsEvr_PrimaryAdcTrimValue_13,         /**< \brief Primary Adc Trim Value 13  */
    IfxPmsEvr_PrimaryAdcTrimValue_14,         /**< \brief Primary Adc Trim Value 14  */
    IfxPmsEvr_PrimaryAdcTrimValue_15,         /**< \brief Primary Adc Trim Value 15  */
    IfxPmsEvr_PrimaryAdcTrimValue_16,         /**< \brief Primary Adc Trim Value 16  */
    IfxPmsEvr_PrimaryAdcTrimValue_17,         /**< \brief Primary Adc Trim Value 17  */
    IfxPmsEvr_PrimaryAdcTrimValue_18,         /**< \brief Primary Adc Trim Value 18  */
    IfxPmsEvr_PrimaryAdcTrimValue_19,         /**< \brief Primary Adc Trim Value 19  */
    IfxPmsEvr_PrimaryAdcTrimValue_20,         /**< \brief Primary Adc Trim Value 20  */
    IfxPmsEvr_PrimaryAdcTrimValue_21,         /**< \brief Primary Adc Trim Value 21  */
    IfxPmsEvr_PrimaryAdcTrimValue_22,         /**< \brief Primary Adc Trim Value 22  */
    IfxPmsEvr_PrimaryAdcTrimValue_23,         /**< \brief Primary Adc Trim Value 23  */
    IfxPmsEvr_PrimaryAdcTrimValue_24,         /**< \brief Primary Adc Trim Value 24  */
    IfxPmsEvr_PrimaryAdcTrimValue_25,         /**< \brief Primary Adc Trim Value 25  */
    IfxPmsEvr_PrimaryAdcTrimValue_26,         /**< \brief Primary Adc Trim Value 26  */
    IfxPmsEvr_PrimaryAdcTrimValue_27,         /**< \brief Primary Adc Trim Value 27  */
    IfxPmsEvr_PrimaryAdcTrimValue_28,         /**< \brief Primary Adc Trim Value 28  */
    IfxPmsEvr_PrimaryAdcTrimValue_29,         /**< \brief Primary Adc Trim Value 29  */
    IfxPmsEvr_PrimaryAdcTrimValue_30,         /**< \brief Primary Adc Trim Value 30  */
    IfxPmsEvr_PrimaryAdcTrimValue_31,         /**< \brief Primary Adc Trim Value 31  */
    IfxPmsEvr_PrimaryAdcTrimValue_32,         /**< \brief Primary Adc Trim Value 32  */
    IfxPmsEvr_PrimaryAdcTrimValue_33,         /**< \brief Primary Adc Trim Value 33  */
    IfxPmsEvr_PrimaryAdcTrimValue_34,         /**< \brief Primary Adc Trim Value 34  */
    IfxPmsEvr_PrimaryAdcTrimValue_35,         /**< \brief Primary Adc Trim Value 35  */
    IfxPmsEvr_PrimaryAdcTrimValue_36,         /**< \brief Primary Adc Trim Value 36  */
    IfxPmsEvr_PrimaryAdcTrimValue_37,         /**< \brief Primary Adc Trim Value 37  */
    IfxPmsEvr_PrimaryAdcTrimValue_38,         /**< \brief Primary Adc Trim Value 38  */
    IfxPmsEvr_PrimaryAdcTrimValue_39,         /**< \brief Primary Adc Trim Value 39  */
    IfxPmsEvr_PrimaryAdcTrimValue_40,         /**< \brief Primary Adc Trim Value 40  */
    IfxPmsEvr_PrimaryAdcTrimValue_41,         /**< \brief Primary Adc Trim Value 41  */
    IfxPmsEvr_PrimaryAdcTrimValue_42,         /**< \brief Primary Adc Trim Value 42  */
    IfxPmsEvr_PrimaryAdcTrimValue_43,         /**< \brief Primary Adc Trim Value 43  */
    IfxPmsEvr_PrimaryAdcTrimValue_44,         /**< \brief Primary Adc Trim Value 44  */
    IfxPmsEvr_PrimaryAdcTrimValue_45,         /**< \brief Primary Adc Trim Value 45  */
    IfxPmsEvr_PrimaryAdcTrimValue_46,         /**< \brief Primary Adc Trim Value 46  */
    IfxPmsEvr_PrimaryAdcTrimValue_47,         /**< \brief Primary Adc Trim Value 47  */
    IfxPmsEvr_PrimaryAdcTrimValue_48,         /**< \brief Primary Adc Trim Value 48  */
    IfxPmsEvr_PrimaryAdcTrimValue_49,         /**< \brief Primary Adc Trim Value 49  */
    IfxPmsEvr_PrimaryAdcTrimValue_50,         /**< \brief Primary Adc Trim Value 50  */
    IfxPmsEvr_PrimaryAdcTrimValue_51,         /**< \brief Primary Adc Trim Value 51  */
    IfxPmsEvr_PrimaryAdcTrimValue_52,         /**< \brief Primary Adc Trim Value 52  */
    IfxPmsEvr_PrimaryAdcTrimValue_53,         /**< \brief Primary Adc Trim Value 53  */
    IfxPmsEvr_PrimaryAdcTrimValue_54,         /**< \brief Primary Adc Trim Value 54  */
    IfxPmsEvr_PrimaryAdcTrimValue_55,         /**< \brief Primary Adc Trim Value 55  */
    IfxPmsEvr_PrimaryAdcTrimValue_56,         /**< \brief Primary Adc Trim Value 56  */
    IfxPmsEvr_PrimaryAdcTrimValue_57,         /**< \brief Primary Adc Trim Value 57  */
    IfxPmsEvr_PrimaryAdcTrimValue_58,         /**< \brief Primary Adc Trim Value 58  */
    IfxPmsEvr_PrimaryAdcTrimValue_59,         /**< \brief Primary Adc Trim Value 59  */
    IfxPmsEvr_PrimaryAdcTrimValue_60,         /**< \brief Primary Adc Trim Value 60  */
    IfxPmsEvr_PrimaryAdcTrimValue_61,         /**< \brief Primary Adc Trim Value 61  */
    IfxPmsEvr_PrimaryAdcTrimValue_62,         /**< \brief Primary Adc Trim Value 62  */
    IfxPmsEvr_PrimaryAdcTrimValue_63          /**< \brief Primary Adc Trim Value 63  */
} IfxPmsEvr_PrimaryAdcTrimValue;

/** \brief This Declare the Under and overvoltage counter defined in Ifx_PMS.EVR.MONFILT.B.ERRCNTLIMT
 */
typedef enum
{
    IfxPmsEvr_SecondaryVoltageErrorCounter_level0 = 0,      /**< \brief Error Counter Limit 0  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level1,          /**< \brief Error Counter Limit 1  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level2,          /**< \brief Error Counter Limit 2  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level3,          /**< \brief Error Counter Limit 3  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level4,          /**< \brief Error Counter Limit 4  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level5,          /**< \brief Error Counter Limit 5  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level6,          /**< \brief Error Counter Limit 6  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level7,          /**< \brief Error Counter Limit 7  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level8,          /**< \brief Error Counter Limit 8  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level9,          /**< \brief Error Counter Limit 9  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level10,         /**< \brief Error Counter Limit 10  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level11,         /**< \brief Error Counter Limit 11  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level12,         /**< \brief Error Counter Limit 12  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level13,         /**< \brief Error Counter Limit 13  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level14,         /**< \brief Error Counter Limit 14  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level15,         /**< \brief Error Counter Limit 15  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level16,         /**< \brief Error Counter Limit 16  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level17,         /**< \brief Error Counter Limit 17  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level18,         /**< \brief Error Counter Limit 18  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level19,         /**< \brief Error Counter Limit 19  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level20,         /**< \brief Error Counter Limit 20  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level21,         /**< \brief Error Counter Limit 21  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level22,         /**< \brief Error Counter Limit 22  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level23,         /**< \brief Error Counter Limit 23  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level24,         /**< \brief Error Counter Limit 24  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level25,         /**< \brief Error Counter Limit 25  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level26,         /**< \brief Error Counter Limit 26  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level27,         /**< \brief Error Counter Limit 27  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level28,         /**< \brief Error Counter Limit 28  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level29,         /**< \brief Error Counter Limit 29  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level30,         /**< \brief Error Counter Limit 30  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level31,         /**< \brief Error Counter Limit 31  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level32,         /**< \brief Error Counter Limit 32  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level33,         /**< \brief Error Counter Limit 33  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level34,         /**< \brief Error Counter Limit 34  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level35,         /**< \brief Error Counter Limit 35  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level36,         /**< \brief Error Counter Limit 36  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level37,         /**< \brief Error Counter Limit 37  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level38,         /**< \brief Error Counter Limit 38  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level39,         /**< \brief Error Counter Limit 39  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level40,         /**< \brief Error Counter Limit 40  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level41,         /**< \brief Error Counter Limit 41  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level42,         /**< \brief Error Counter Limit 42  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level43,         /**< \brief Error Counter Limit 43  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level44,         /**< \brief Error Counter Limit 44  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level45,         /**< \brief Error Counter Limit 45  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level46,         /**< \brief Error Counter Limit 46  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level47,         /**< \brief Error Counter Limit 47  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level48,         /**< \brief Error Counter Limit 48  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level49,         /**< \brief Error Counter Limit 49  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level50,         /**< \brief Error Counter Limit 50  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level51,         /**< \brief Error Counter Limit 51  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level52,         /**< \brief Error Counter Limit 52  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level53,         /**< \brief Error Counter Limit 53  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level54,         /**< \brief Error Counter Limit 54  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level55,         /**< \brief Error Counter Limit 55  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level56,         /**< \brief Error Counter Limit 56  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level57,         /**< \brief Error Counter Limit 57  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level58,         /**< \brief Error Counter Limit 58  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level59,         /**< \brief Error Counter Limit 59  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level60,         /**< \brief Error Counter Limit 60  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level61,         /**< \brief Error Counter Limit 61  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level62,         /**< \brief Error Counter Limit 62  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level63          /**< \brief Error Counter Limit 63  */
} IfxPmsEvr_SecondaryVoltageErrorCounter;

/** \brief ADC result for the generating Alarm declare in Ifx_PMS.EVR.MONFILT
 */
typedef enum
{
    IfxPmsEvr_SupplyFilter_eachConversionResult    = 0,    /**< \brief Each conversion result is compared with threshold to generate alarm */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult0 = 1,    /**< \brief A moving mean average of consecutive 0 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult1,        /**< \brief A moving mean average of consecutive 1 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult2,        /**< \brief A moving mean average of consecutive 2 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult3,        /**< \brief A moving mean average of consecutive 3 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult4,        /**< \brief A moving mean average of consecutive 4 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult5,        /**< \brief A moving mean average of consecutive 5 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult6,        /**< \brief A moving mean average of consecutive 6 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult7,        /**< \brief A moving mean average of consecutive 7 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult8,        /**< \brief A moving mean average of consecutive 8 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult9,        /**< \brief A moving mean average of consecutive 9 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult10,       /**< \brief A moving mean average of consecutive 10 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult11,       /**< \brief A moving mean average of consecutive 11 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult12,       /**< \brief A moving mean average of consecutive 12 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult13,       /**< \brief A moving mean average of consecutive 13 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult14        /**< \brief A moving mean average of consecutive 14 ADC results  */
} IfxPmsEvr_SupplyFilter;

/** \brief Controls the voltage supply Type
 */
typedef enum
{
    IfxPmsEvr_SupplyMode_evrc  = 0,  /**< \brief select EVRC regulator or VDD Supply */
    IfxPmsEvr_SupplyMode_evr33 = 1,  /**< \brief select EVR33 regulator or VDDP3 Supply */
    IfxPmsEvr_SupplyMode_swd   = 2,  /**< \brief select  external VEXT suppy watchdog */
    IfxPmsEvr_SupplyMode_evrpr = 3,  /**< \brief select EVRPR or VDDPD supply */
    IfxPmsEvr_SupplyMode_vddm  = 4,  /**< \brief VDDM ADC Supply */
    IfxPmsEvr_SupplyMode_sb    = 5   /**< \brief EVR Standby Supply or VEVRSB supply */
} IfxPmsEvr_SupplyMode;

/** \brief Monitoring underVoltage for all bitfields defined
 * in Ifx_PMS.EVR.MONCTRL register for undervoltage monitoring
 */
typedef enum
{
    IfxPmsEvr_UnderVoltageMonitoring_inactive                         = 0, /**< \brief Under-Voltage Monitoring inactive */
    IfxPmsEvr_UnderVoltageMonitoring_lowToHighVoltageTransition       = 1, /**< \brief under-Voltage event is generated when threshold is crossed in lower to higher voltage transition */
    IfxPmsEvr_UnderVoltageMonitoring_highToLowVoltageTransition       = 2, /**< \brief Under-Voltage event is generated when threshold is crossed in higher to lower voltage transition */
    IfxPmsEvr_UnderVoltageMonitoring_eitherDirectionVoltageTransition = 3  /**< \brief Under-Voltage event is generated when threshold is crossed in either direction */
} IfxPmsEvr_UnderVoltageMonitoring;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    volatile void *regAddr;       /**< \brief Register Address to be updated. */
    uint32         value;         /**< \brief Register value to be updated. */
    uint32         mask;          /**< \brief Mask to select the bit fields to be updated. */
} IfxPmsEvr_StepDownRegulatorRegConfig;

typedef struct
{
    uint8                                           numOfRegisters;
    IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;
    float32                                         waitInSecs;
} IfxPmsEvr_initSequencePhase;

typedef struct
{
    uint8                                           numOfRegisters;
    IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;
} IfxPmsEvr_checkRegConfig;

typedef struct
{
    uint8                                  numOfPhases;
    IFX_CONST IfxPmsEvr_initSequencePhase *phaseConfig;
} IfxPmsEvr_initSequence;

/** \addtogroup IfxLld_Pms_Std_Evr_Over-Voltage
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief set Over Voltage Monitoring Mode
 * \param pms pointer to the Module space
 * \param mode specifies the monitoring mode
 * \param supply select EVRC,EVR33,VDDM,SWD or SB supply
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setOverVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_OverVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief set Secondary Over Voltage Threshold level
 * \param pms Pointer to PMS Module
 * \param thresholdLevel over-voltage monitoring threshold level of the respective
 * regulator output or supply
 * \param supply select EVRC,EVR33,SWD,EVRPR,VDDM or SB supply mode
 * \return None
 */
IFX_EXTERN void IfxPmsEvr_setSecondaryOverVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configure a Blanking Filter Delay
 * \param pms Pointer To PMS Module
 * \param delay Blanking Filter Delay in ms
 * \return None
 */
IFX_INLINE void IfxPmsEvr_configureBlankingFilterDelay(Ifx_PMS *pms, uint8 delay);

/** \brief This function enables the synchronisation output to synchronize the external
 * SMPS regulator with respect to the internal EVRC regulator
 * \param pms Pointer to PMS Module
 * \param enabled enable/disable DC-DC synchronisation
 * \return None
 */
IFX_INLINE void IfxPmsEvr_enableDcdcSynchronisation(Ifx_PMS *pms, boolean enabled);

/** \brief Enable Interrupts
 * \param pms Pointer to PMS Module
 * \param interruptType Select The Interrupt Type
 * \return None
 */
IFX_INLINE void IfxPmsEvr_enableInterrupts(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType);

/** \brief enables wakeup on VEXT supply ramp-up after blanking filter
 * time has expired
 * \param pms Pointer To PMS Module
 * \param enabled Wake-up Enable on VEXT Supply ramp-up
 * \return None
 */
IFX_INLINE void IfxPmsEvr_enableWakeupOnVextSupplyRampUp(Ifx_PMS *pms, boolean enabled);

/** \brief OSC Fine Trim 100MHz Clock
 * \param pms pointer to PMS Module
 * \param trimValue OSC fine trim value
 * \return None
 */
IFX_INLINE void IfxPmsEvr_fineTrimEvrClock(Ifx_PMS *pms, uint8 trimValue);

/** \brief set frequency spread threshold
 * \param pms pointer to PMS module
 * \param thresholdLevel maximum frequency spreading value
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setFrequencySpreadThreshold(Ifx_PMS *pms, uint16 thresholdLevel);

/** \brief This configures the state of N ch. MOSFET driver during start-up and
 * shut-down phases
 * \param pms Pointer to PMS Module
 * \param nmosLevel TRISTATE/LOW
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setNmosLevel(Ifx_PMS *pms, boolean nmosLevel);

/** \brief This configures the state of P ch. MOSFET driver during start-up and
 * shut-down phases
 * \param pms Pointer to PMS Module
 * \param pmosLevel TRISTATE/LOW
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setPmosLevel(Ifx_PMS *pms, boolean pmosLevel);

/** \brief set regulator switching frequency in Hz....(100MHz/samplingFactor)
 * \param pms Pointer to PMS Module
 * \param samplingFactor Over-sampling Factor
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setRegulatorSwitchingFrequency(Ifx_PMS *pms, uint16 samplingFactor);

/** \brief set reset trim value for EVRC,EVR33 and external VEXT supply
 * \param pms Pointer to PMS Module Space
 * \param resetTrimValue Reset Trim Value
 * \param supply select EVRC,EVR33 regulator or external VEXT supply watchdog
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setResetTrimValueMv(Ifx_PMS *pms, float32 resetTrimValue, IfxPmsEvr_SupplyMode supply);

/** \brief SD Regulator Voltage Target selection
 * \param pms Pointer to PMS Module
 * \param outputLevel The VDD output level of the Step down regulator
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setSdRegulatorOutputLevel(Ifx_PMS *pms, uint8 outputLevel);

/** \brief SD Regulator Voltage Trim Value
 * \param pms Pointer to PMS Moule Space
 * \param trimValue offset added to the VDD output level
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setSdRegulatorPrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue);

/** \brief set DLMU RAM Block in Standby Mode
 * \param pms Pointer To PMS Module
 * \param ramBlock DLMU RAM block
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setStandbyRamSupply(Ifx_PMS *pms, uint8 ramBlock);

/** \brief Set Switching frequency division factor for external synchronisation.
 * \param pms Pointer To PMS Module
 * \param divider Switching frequency division factor for external synchronisation
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setSwitchingFreqDivFactorForExternalsync(Ifx_PMS *pms, IfxPmsEvr_ExtSyncSwitchingFreqDivFactor divider);

/** \brief OSC Fine Trim 100MHz Clock
 * \param pms Pointer to PMS Module
 * \param trimValue OSC Signed fine trim value
 * \return None
 */
IFX_INLINE void IfxPmsEvr_signedFineTrimEvrClock(Ifx_PMS *pms, sint8 trimValue);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief filter the  each conversion result or avarage of consecutive adc result to compare with threshold
 * \param pms Pointer to PMS Module
 * \param adcFilterValue specify average of consecutive ADC results
 * \param supply select EVRC,EVR33,SWD,EVRPR,VDDM or SB supply mode
 * \return None
 */
IFX_EXTERN void IfxPmsEvr_filterSecondaryConversionResult(Ifx_PMS *pms, IfxPmsEvr_SupplyFilter adcFilterValue, IfxPmsEvr_SupplyMode supply);

/** \brief get secondray ADC result for respective Voltage supply
 * \param pms Pointer To PMS Module
 * \param supply select EVRC,EVR33,SWD,EVRPR,VDDM or SB supply mode
 * \return last conversion result of the ADC measurement
 * of respective voltage by secondary monitor
 */
IFX_EXTERN uint8 IfxPmsEvr_getSecondaryAdcResult(Ifx_PMS *pms, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_Under-Voltage
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief set Under Voltage Monitoring mode
 * \param pms Pointer to the PMS Module space
 * \param mode specifies the monitoring mode
 * \param supply select EVRC,EVR33,VDDM,SWD or SB supply
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setUnderVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_UnderVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief set Secondary under Voltage Threshold level
 * \param pms Pointer to PMS Module space
 * \param thresholdLevel under-voltage monitoring threshold level of the respective
 * regulator output or supply
 * \param supply select EVRC,EVR33,SWD,EVRPR,VDDM or SB supply mode
 * \return None
 */
IFX_EXTERN void IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_EVRC
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enabled/Disable Reset Trigger signal for EVRC
 * \param pms pointer to PMS Module
 * \param enableReset Enable/Disable the reset trigger signal
 * \return None
 */
IFX_INLINE void IfxPmsEvr_evrcResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/**
 * \param averageADCC Average value of PMS_EVRADCSTAT.ADCCV.
 * \return ADC VDD Core Voltage Conversion Result
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVddResult(float32 averageADCC);

/** \brief get current operating mode of EVRC
 * \param pms Pointer to PMS Module Space
 * \return EVRC Mode
 */
IFX_INLINE IfxPmsEvr_EvrcMode IfxPmsEvr_getEvrcMode(Ifx_PMS *pms);

/** \brief get EVRC Regulator Voltage status
 * \param pms Pointer to PMS Module Space
 * \return EVRC Regulator Voltage OK status
 */
IFX_INLINE boolean IfxPmsEvr_getEvrcVoltageRegulator(Ifx_PMS *pms);

/** \brief get ADC 1.25 V Core Voltage Conversion Result
 * \param pms Pointer to PMS Module space
 * \return last conversion result of the ADC measurement of
 * the VDD / EVRC supply by the Primary Monitor
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvrcResult(Ifx_PMS *pms);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_EVR33
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enabled/Disable Reset Trigger signal for EVR33
 * \param pms pointer to PMS Module
 * \param enableReset Enable/Disable the reset trigger signal
 * \return None
 */
IFX_INLINE void IfxPmsEvr_evr33ResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/** \brief get ADC 3.3 V Voltage Conversion Result
 * \param pms Pointer to PMS Module Space
 * \return last conversion result of the ADC measurement of
 * the VDDP3 / EVR33 supply by the Primary Monitor
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvr33Result(Ifx_PMS *pms);

/** \brief set 3.3 V Regulator Voltage Primary ADC Trim Value
 * \param pms Pointer to PMS Module
 * \param trimValue Trimming value offeset added to Output level
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setEvr33PrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue);

/** \brief The VDDP3 output level of the EVR33 LDO regulator
 * \param pms Pointer to PMS Module
 * \param outputLevel define VDDP3 output level of the EVR33 LDO regulator.
 * \return None
 */
IFX_INLINE void IfxPmsEvr_setEvr33VoltageOutputlevel(Ifx_PMS *pms, uint8 outputLevel);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_SWD
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief get ADC External Supply Conversion Result
 * \param pms Pointer to PMS Module space
 * \return last conversion result of the ADC measurement of
 * the external VEXT (3.3V / 5V) supply by the Primary Monitor
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcSwdResult(Ifx_PMS *pms);

/** \brief Enabled/Disable Reset Trigger signal for SWD
 * \param pms Pointer to PMS Module
 * \param enableReset Enable/Disable the reset trigger signal
 * \return None
 */
IFX_INLINE void IfxPmsEvr_swdResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 */
IFX_INLINE boolean IfxPmsEvr_areInitValuesRight(const IfxPmsEvr_checkRegConfig *const checkConfig);

/** \brief Disable Interrupts
 * \return None
 */
IFX_INLINE void IfxPmsEvr_disableInterrupt(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType);

/**
 * \param averageADC33V Average of PMS_EVRSTAT.ADC33V values
 * \return ADC VDDP3 Voltage Conversion Result
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVddp3Result(float32 averageADC33V);

/**
 * \param averageADCSWDV Average of PMS_EVRADCSTAT.ADCSWDV values.
 * \return ADC VEXT Supply Conversion Result
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVextResult(float32 averageADCSWDV);

/**
 */
IFX_INLINE boolean IfxPmsEvr_runInitSequence(const IfxPmsEvr_initSequence *const sequence);

/**
 * \return None
 */
IFX_INLINE void IfxPmsEvr_wait(float32 waitInSec);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase1Default[];

IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase2Default[];

/** \brief
 */
IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase3Default[];

IFX_EXTERN IFX_CONST IfxPmsEvr_initSequencePhase          IfxPmsEvr_cfgPhasesDefault[];

IFX_EXTERN IFX_CONST IfxPmsEvr_initSequence               IfxPmsEvr_cfgSequenceDefault;

IFX_EXTERN IFX_CONST IfxPmsEvr_checkRegConfig             IfxPmsEvr_checkRegCfgDefault;

IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_checkRegValuesDefault[];

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxPmsEvr_areInitValuesRight(const IfxPmsEvr_checkRegConfig *const checkConfig)
{
    boolean allRight = TRUE;
    sint32  regCfgCount;

    if (PMS_EVRSTAT.B.EVRC == 1U)
    {
        for (regCfgCount = 0; regCfgCount < checkConfig->numOfRegisters; regCfgCount++)
        {
            uint32                                      regVal;
            const IfxPmsEvr_StepDownRegulatorRegConfig *regConfig = &checkConfig->regConfig[regCfgCount];
            regVal  = (*((volatile uint32 *)regConfig->regAddr));
            regVal &= regConfig->mask;

            if (regVal != regConfig->value)
            {
                allRight = FALSE;
            }
        }

        /*Check if EVRSTAT.SDVOK is set*/
        if (allRight == TRUE)
        {
            if (PMS_EVRSTAT.B.SDVOK != 1)
            {
                allRight = FALSE;
            }
        }
    }

    return allRight;
}


IFX_INLINE void IfxPmsEvr_configureBlankingFilterDelay(Ifx_PMS *pms, uint8 delay)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.BLNKFIL = delay;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_disableInterrupt(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    uint32 mask = (1U << interruptType);
    pms->PMSIEN.U &= (~mask);

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableDcdcSynchronisation(Ifx_PMS *pms, boolean enabled)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR5.B.DCDCSYNCO = enabled;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableInterrupts(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSIEN.U |= (1U << interruptType);

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableWakeupOnVextSupplyRampUp(Ifx_PMS *pms, boolean enabled)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.PWRWKEN = enabled;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_evr33ResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRRSTCON.B.BPRST33OFF = 1;
    pms->EVRRSTCON.B.RST33OFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_evrcResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRRSTCON.B.BPRSTCOFF = 1;
    pms->EVRRSTCON.B.RSTCOFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_fineTrimEvrClock(Ifx_PMS *pms, uint8 trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVROSCCTRL.B.OSCFTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE float32 IfxPmsEvr_getAdcVddResult(float32 averageADCC)
{
    float32 vddVoltage = 0;
    vddVoltage = (IFXPMSEVR_ADC_VDD_LSB * averageADCC + 0.7125);
    return vddVoltage;
}


IFX_INLINE float32 IfxPmsEvr_getAdcVddp3Result(float32 averageADC33V)
{
    float32 vddp3Voltage = 0;
    vddp3Voltage = (IFXPMSEVR_ADC_VDDP3_LSB * averageADC33V + 0.9375);
    return vddp3Voltage;
}


IFX_INLINE float32 IfxPmsEvr_getAdcVextResult(float32 averageADCSWDV)
{
    float32 vextVoltage = 0;
    vextVoltage = (IFXPMSEVR_ADC_VEXT_LSB * averageADCSWDV + 1.050);
    return vextVoltage;
}


IFX_INLINE IfxPmsEvr_EvrcMode IfxPmsEvr_getEvrcMode(Ifx_PMS *pms)
{
    return (IfxPmsEvr_EvrcMode)pms->EVRSTAT.B.EVRCMOD;
}


IFX_INLINE boolean IfxPmsEvr_getEvrcVoltageRegulator(Ifx_PMS *pms)
{
    return (boolean)pms->EVRSTAT.B.SDVOK;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvr33Result(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADC33V;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvrcResult(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADCCV;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcSwdResult(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADCSWDV;
}


#if defined(__TASKING__)
#pragma optimize L
#elif defined(__HIGHTEC__)
#pragma GCC optimize ("-O2")
#endif
IFX_INLINE boolean IfxPmsEvr_runInitSequence(const IfxPmsEvr_initSequence *const sequence)
{
    boolean                                     pmsInitDone    = TRUE;
    uint32                                      regVal;
    uint16                                      endinitSfty_pw = IfxScuWdt_getGlobalSafetyEndinitPasswordInline();
    const IfxPmsEvr_initSequencePhase          *phaseConfig;
    const IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;

    if (PMS_EVRSTAT.B.EVRC == 1U)
    {
        /*Loop through each configured phase*/
        for (phaseConfig = &sequence->phaseConfig[0];
             phaseConfig < &sequence->phaseConfig[sequence->numOfPhases];
             phaseConfig++)
        {
            IfxScuWdt_clearGlobalSafetyEndinitInline(endinitSfty_pw);

            /*Loop through each register which is configured in the phase configuration*/
            for (regConfig = &phaseConfig->regConfig[0];
                 regConfig < &phaseConfig->regConfig[phaseConfig->numOfRegisters];
                 regConfig++)
            {
                regVal  = (*((volatile uint32 *)regConfig->regAddr));
                regVal &= ~regConfig->mask;
                regVal |= regConfig->value;

                /** During normal running one must wait for the LCK bit.
                 * However, for this function, as this is used only with CPU0 startup no wait required
                 */
                (*((volatile uint32 *)regConfig->regAddr)) = regVal; /*Write to the physical register*/
            }

            PMS_EVRSDCTRL0.B.UP = 1;
            IfxScuWdt_setGlobalSafetyEndinitInline(endinitSfty_pw);

            /* wait for the UP bit*/
            sint32 timeoutCount = IFXPMSEVR_CTRL_UP_WAIT_TIMEOUTCOUNT;

            /*Now, wait for the UP bit at EVRSDCTRL0 is reset, which is to indicate the configurations are done*/
            do
            {
                if (--timeoutCount <= 0)
                {
                    pmsInitDone = FALSE;
                    break;
                }
            } while (PMS_EVRSDCTRL0.B.UP == 1);

            IfxPmsEvr_wait(phaseConfig->waitInSecs);        // wait for configured time
        }
    }

    /*return the status*/
    return pmsInitDone;
}
#if defined(__TASKING__)
#pragma endoptimize
#elif defined(__HIGHTEC__)
#pragma GCC reset_options
#endif


IFX_INLINE void IfxPmsEvr_setEvr33PrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRTRIM.B.EVR33VOUTTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setEvr33VoltageOutputlevel(Ifx_PMS *pms, uint8 outputLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRTRIM.B.EVR33VOUTSEL = outputLevel;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setFrequencySpreadThreshold(Ifx_PMS *pms, uint16 thresholdLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRSDCTRL0.B.SDFREQSPRD = thresholdLevel;
    pms->EVRSDCTRL0.B.UP         = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setNmosLevel(Ifx_PMS *pms, boolean nmosLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.NGOFF = nmosLevel;
    pms->EVRSDCTRL0.B.UP    = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setOverVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_OverVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply)
{
    uint16          passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_MONCTRL tempMONCTRL;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempMONCTRL.U = pms->MONCTRL.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempMONCTRL.B.EVRCOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempMONCTRL.B.EVR33OVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempMONCTRL.B.SWDOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempMONCTRL.B.PREOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempMONCTRL.B.VDDMOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempMONCTRL.B.SBOVMOD = mode;
        break;
    }

    pms->MONCTRL.U = tempMONCTRL.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setPmosLevel(Ifx_PMS *pms, boolean pmosLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.PGOFF = pmosLevel;
    pms->EVRSDCTRL0.B.UP    = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setRegulatorSwitchingFrequency(Ifx_PMS *pms, uint16 samplingFactor)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.SDFREQ = samplingFactor;
    pms->EVRSDCTRL0.B.UP     = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setResetTrimValueMv(Ifx_PMS *pms, float32 resetTrimValue, IfxPmsEvr_SupplyMode supply)
{
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_EVRRSTCON tempRSTCON;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempRSTCON.U = pms->EVRRSTCON.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempRSTCON.B.RSTCTRIM = ((resetTrimValue - 712.5) / 5);
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempRSTCON.B.RST33TRIM = ((resetTrimValue - 937.5) / 15);
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempRSTCON.B.RSTSWDTRIM = ((resetTrimValue - 1050) / 20);
        break;
    default:
        break;
    }

    pms->EVRRSTCON.U = tempRSTCON.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setSdRegulatorOutputLevel(Ifx_PMS *pms, uint8 outputLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRTRIM.B.SDVOUTSEL = outputLevel;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setSdRegulatorPrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRTRIM.B.SDVOUTTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setStandbyRamSupply(Ifx_PMS *pms, uint8 ramBlock)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.STBYRAMSEL = ramBlock;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setSwitchingFreqDivFactorForExternalsync(Ifx_PMS *pms, IfxPmsEvr_ExtSyncSwitchingFreqDivFactor divider)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRSDCTRL7.B.SYNCDIVFAC = divider;
    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setUnderVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_UnderVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply)
{
    uint16          passwd = IfxScuWdt_getSafetyWatchdogPassword();
    Ifx_PMS_MONCTRL tempMONCTRL;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempMONCTRL.U = pms->MONCTRL.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempMONCTRL.B.EVRCUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempMONCTRL.B.EVR33UVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempMONCTRL.B.SWDUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempMONCTRL.B.PREUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempMONCTRL.B.VDDMUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempMONCTRL.B.SBUVMOD = mode;
        break;
    }

    pms->MONCTRL.U = tempMONCTRL.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_signedFineTrimEvrClock(Ifx_PMS *pms, sint8 trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVROSCCTRL.B.OSCFPTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_swdResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRRSTCON.B.BPRSTSWDOFF = 1;
    pms->EVRRSTCON.B.RSTSWDOFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_wait(float32 waitInSec)
{
    uint32 stmCount      = (uint32)((float32)33000000UL * waitInSec);
    uint32 stmCountBegin = STM0_TIM0.U;     /* it is necessary to get this value to have minimum 100uS delay in subsequent CPU start */

    while ((uint32)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }
}


#endif /* IFXPMSEVR_H */

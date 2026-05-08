/*==================================================================================================
* Project :             RTD AUTOSAR 4.7
* Platform :            CORTEXM
* Peripheral :          Stm_Pit_Rtc_Emios
* Dependencies :        none
*
* Autosar Version :     4.7.0
* Autosar Revision :    ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version :          4.0.0
* Build Version :       S32K3_RTD_4_0_0_D2311_ASR_REL_4_7_REV_0000_20231128
*
* Copyright 2020 - 2023 NXP
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_GPT_IP_CFG_DEFINES_H
#define EMIOS_GPT_IP_CFG_DEFINES_H

/**
*   @file           Emios_Gpt_Ip_Cfg_Defines.h
*
*   @addtogroup     emios_ip Emios IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
/* Include platform header file. */
#include "S32K344_EMIOS.h"
    /*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_GPT_IP_CFG_DEFINES_VENDOR_ID                    43
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_GPT_IP_CFG_DEFINES_SW_MAJOR_VERSION             4
#define EMIOS_GPT_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define EMIOS_GPT_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_GPT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Emios_Gpt_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define EMIOS_GPT_IP_USED (STD_ON) 

/*================================================================================================*/
/**
* @brief    EMIOS_GPT_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define EMIOS_GPT_IP_SET_CLOCK_MODE           (STD_OFF)
/**
*
* @brief IRQ Defines for each channel used
*/
#ifndef EMIOS_0_CH_4_ISR_USED
    #define GPT_EMIOS_0_CH_4_ISR_USED
    #define EMIOS_0_CH_4_ISR_USED
#else
    #error "EMIOS_0_CH_4 interrupt cannot be used by Gpt driver. Channel locked by other driver!"
#endif
#ifndef EMIOS_0_CH_5_ISR_USED
    #define GPT_EMIOS_0_CH_5_ISR_USED
    #define EMIOS_0_CH_5_ISR_USED
#else
    #error "EMIOS_0_CH_5 interrupt cannot be used by Gpt driver. Channel locked by other driver!"
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* EMIOS_GPT_IP_CFG_DEFINE_H */


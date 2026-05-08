/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_D2311_ASR_REL_4_7_REV_0000_20231128
*
*   Copyright 2020 - 2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Siul2_Port_Ip_PBcfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Siul2_Port_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_PBCFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C                4
#define SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_PBCFG_C != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/* Check if Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are of the same software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_PBCFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"


const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[NUM_OF_CONFIGURED_PINS] = 
{
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 96,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   254
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT1,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 97,
        .mux                   = PORT_MUX_ALT3,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 138,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 113,
        .mux                   = PORT_MUX_ALT5,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 140,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 142,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 40,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 41,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 42,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_UP_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_ENABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 43,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   260
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT2,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 11,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 129,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 110,
        .mux                   = PORT_MUX_ALT4,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_UP_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   212
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT2,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 109,
        .mux                   = PORT_MUX_ALT4,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_UP_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   214
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT2,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 61,
        .mux                   = PORT_MUX_ALT5,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_ENABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   245
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT3,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 151,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 150,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 139,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 2,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 47,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 48,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 85,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 7,
        .mux                   = PORT_MUX_ALT4,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 6,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT2,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 88,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 9,
        .mux                   = PORT_MUX_ALT2,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 12,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_DISABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 154,
        .mux                   = PORT_MUX_AS_GPIO,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_DISABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   0
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 70,
        .mux                   = PORT_MUX_ALT1,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   219
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT2,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    },
    {
        .base                  = IP_SIUL2,
        .pinPortIdx            = 71,
        .mux                   = PORT_MUX_ALT3,
        .safeMode              = PORT_SAFE_MODE_DISABLED,
        .pullConfig            = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength         = PORT_DRIVE_STRENTGTH_DISABLED,
        .inputFilter           = PORT_INPUT_FILTER_DISABLED,
        .pullKeep              = PORT_PULL_KEEP_DISABLED,
        .invert                = PORT_INVERT_DISABLED,
        .slewRateCtrlSel       = PORT_SLEW_RATE_NOT_AVAILABLE,
        .inputBuffer           = PORT_INPUT_BUFFER_ENABLED,
        .outputBuffer          = PORT_OUTPUT_BUFFER_ENABLED,
        .adcInterleaves        = {
                                   MUX_MODE_NOT_AVAILABLE,
                                   MUX_MODE_NOT_AVAILABLE,
                                 },
        .initValue             = 0,
        .inputMuxReg           = {
                                   217
                                 },
        .inputMux              = {
                                   PORT_INPUT_MUX_ALT1,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT,
                                   PORT_INPUT_MUX_NO_INIT
                                 }
    }
};
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */


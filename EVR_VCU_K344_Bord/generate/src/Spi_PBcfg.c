/**
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 4.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_D2311_ASR_REL_4_7_REV_0000_20231128
*
*   Copyright 2020 - 2023 NXP NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw_PBcfg.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_MODULE_ID_PBCFG_C                        83
#define SPI_VENDOR_ID_PBCFG_C                        43
#define SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C         7

#define SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_SW_MAJOR_VERSION_PBCFG_C                 4
#define SPI_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_SW_PATCH_VERSION_PBCFG_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_IPW_VENDOR_ID_PBCFG_H)
    #error "Spi_PBCfg.c and Spi_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_H ))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_IPW_SW_MAJOR_VERSION_PBCFG_H) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_IPW_SW_MINOR_VERSION_PBCFG_H) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_IPW_SW_PATCH_VERSION_PBCFG_H))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
#endif
#endif
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/* List Of Notification Functions */
/* Job start/end Notifications */
/* Sequence End Notifications */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

/* Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels */
static Spi_BufferDescriptorType Spi_Buffer_SpiChannel_FS26;
static Spi_BufferDescriptorType Spi_Buffer_SpiChannel_Display;

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Buffers Descriptors for IB Channels */

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Channel Configuration */
/* Channel Configuration for SpiChannel_FS26 */
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_FS26 =
{
        EB,  /* BufferType IB or EB */
        8U,   /* Frame size */
        (boolean)FALSE, /* Bit order, 1:LSB, 0: MSB */
        (boolean)FALSE, /* Byte Swap */
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
            SPI_FULL_DUPLEX,
              #endif
#endif

        (uint32)1U,  /* DefaultTransmitValue (configured) */
        1000U, /* length of buffer */
        &Spi_Buffer_SpiChannel_FS26, /* BufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,  /* Core Id */
        &Spi_axSpiChannelState[0U] /* ChannelState pointer */
};
/* Channel Configuration for SpiChannel_Display */
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_Display =
{
        EB,  /* BufferType IB or EB */
        8U,   /* Frame size */
        (boolean)FALSE, /* Bit order, 1:LSB, 0: MSB */
        (boolean)FALSE, /* Byte Swap */
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
            SPI_FULL_DUPLEX,
              #endif
#endif

        (uint32)1U,  /* DefaultTransmitValue (configured) */
        3000U, /* length of buffer */
        &Spi_Buffer_SpiChannel_Display, /* BufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,  /* Core Id */
        &Spi_axSpiChannelState[1U] /* ChannelState pointer */
};
/* Spi_aChannelConfigList Channel Configuration */
static const Spi_ChannelsCfgType Spi_aChannelConfigList[2] =
{
    /* SpiChannel_FS26 */
    {
        &Spi_ChannelConfig_SpiChannel_FS26
    },
    /* SpiChannel_Display */
    {
        &Spi_ChannelConfig_SpiChannel_Display
    }
};

/* Channel Assignment of Jobs */
/* SpiJob_FS26 */
static const Spi_ChannelType Spi_SpiJob_FS26_ChannelAssignment[1] =
{
    SpiConf_SpiChannel_SpiChannel_FS26
};
/* SpiJob_Display */
static const Spi_ChannelType Spi_SpiJob_Display_ChannelAssignment[1] =
{
    SpiConf_SpiChannel_SpiChannel_Display
};

/* Configuration of Jobs */
/* Job Configuration for SpiJob_FS26 */
static const Spi_JobConfigType Spi_JobConfig_SpiJob_FS26 =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_SpiJob_FS26_ChannelAssignment, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        SPI_SpiExternalDevice_FS26, /* External Device */
        &Spi_aExternalDeviceConfigList[SPI_SpiExternalDevice_FS26] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Job Configuration for SpiJob_Display */
static const Spi_JobConfigType Spi_JobConfig_SpiJob_Display =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_SpiJob_Display_ChannelAssignment, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[1], /* JobState instance */
        CSIB1, /* HWUnit index */
        SPI_SpiExternalDevice_Display, /* External Device */
        &Spi_aExternalDeviceConfigList[SPI_SpiExternalDevice_Display] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Spi_aJobConfigList Job Configuration*/
static const Spi_JobsCfgType Spi_aJobConfigList[2] =
{
    /* SpiJob_FS26 */
    {
        &Spi_JobConfig_SpiJob_FS26
    },
    /* SpiJob_Display */
    {
        &Spi_JobConfig_SpiJob_Display
    }
};

/* Job Assignment of Sequences  */
/* SpiSequence_FS26 */
static const Spi_JobType Spi_SpiSequence_FS26_JobAssignment[1] =
{
    SpiConf_SpiJob_SpiJob_FS26 
};
/* SpiSequence_Display */
static const Spi_JobType Spi_SpiSequence_Display_JobAssignment[1] =
{
    SpiConf_SpiJob_SpiJob_Display 
};

/* Configuration of Sequences */
/* Sequence Configuration for SpiSequence_FS26 */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_FS26 =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_FS26_JobAssignment, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
        ,(boolean)FALSE /* Enable ContMemTransferSequence */
        ,NULL_PTR
        #endif
};
/* Sequence Configuration for SpiSequence_Display */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_Display =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_Display_JobAssignment, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMA_CONT_MEM_TRANSFER_SUPPORT == STD_ON))
        ,(boolean)FALSE /* Enable ContMemTransferSequence */
        ,NULL_PTR
        #endif
};
/* Spi_aSequenceConfigList Sequence Configuration */
static const Spi_SeqsConfigType Spi_aSequenceConfigList[2] =
{
    /* SpiSequence_FS26 */
    {
        &Spi_SequenceConfig_SpiSequence_FS26
    },
    /* SpiSequence_Display */
    {
        &Spi_SequenceConfig_SpiSequence_Display
    }
};
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* Spi Configuration */
static const Spi_ConfigType Spi_Config=
{
    2U,  /* MaxExternalDevice - number of external devices */
    1U, /* SpiMaxChannel - number of channels */
    1U, /* SpiMaxJob - number of jobs */
    1U, /* SpiMaxSequence - number of sequences */
    SPI_SPURIOUS_CORE_ID_U32,   /* SpiCoreUse - used core */
    Spi_aChannelConfigList, /* ChannelConfig */
    Spi_aJobConfigList, /* JobConfig */
    Spi_aSequenceConfigList, /* SequenceConfig */
    Spi_aExternalDeviceConfigList, /* ExternalDeviceConfig */
    Spi_aHwUnitConfigList /* HWUnitConfig */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    ,{ (uint32)STD_OFF, (uint32)0U} /* SPI_E_HARDWARE_ERROR parameters*/
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
};

const Spi_ConfigType * const Spi_PBCfgVariantPredefined[SPI_MAX_PARTITIONS]=
{
    &Spi_Config
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */



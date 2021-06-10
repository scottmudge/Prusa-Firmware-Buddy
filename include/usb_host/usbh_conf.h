/**
  ******************************************************************************
  * @file           : usbh_conf.h
  * @version        : v1.0_Cube
  * @brief          : Header for usbh_conf.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBH_CONF__H__
    #define __USBH_CONF__H__
    #ifdef __cplusplus
extern "C" {
    #endif
/* Includes ------------------------------------------------------------------*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "main.h"

    #include "stm32f4xx.h"
    #include "stm32f4xx_hal.h"

    /* USER CODE BEGIN INCLUDE */

    /* USER CODE END INCLUDE */

    // Utility
    #ifndef BIT
    #define BIT(nr)                 (1UL << (nr))
    #endif

    /** @addtogroup USBH_OTG_DRIVER
  * @brief Driver for Usb host.
  * @{
  */

    /** @defgroup USBH_CONF USBH_CONF
  * @brief Configuration file for Usb otg low level driver.
  * @{
  */

    /** @defgroup USBH_CONF_Exported_Variables USBH_CONF_Exported_Variables
  * @brief Public variables.
  * @{
  */

    /**
  * @}
  */

    /** @defgroup USBH_CONF_Exported_Defines USBH_CONF_Exported_Defines
  * @brief Defines for configuration of the Usb host.
  * @{
  */

    /*
    MiddleWare name : USB_HOST
    MiddleWare fileName : usbh_conf.h
    MiddleWare version :
*/
    /*----------   -----------*/
    #define USBH_MAX_NUM_ENDPOINTS 2

    /*----------   -----------*/
    #define USBH_MAX_NUM_INTERFACES 2

    /*----------   -----------*/
    #define USBH_MAX_NUM_CONFIGURATION 1

    /*----------   -----------*/
    #define USBH_KEEP_CFG_DESCRIPTOR 1

    /*----------   -----------*/
    #define USBH_MAX_NUM_SUPPORTED_CLASS 1

    /*----------   -----------*/
    #define USBH_MAX_SIZE_CONFIGURATION 256

    /*----------   -----------*/
    #define USBH_MAX_DATA_BUFFER 512

    /*----------   -----------*/
    #define USBH_DEBUG_LEVEL 0

    /*----------   -----------*/
    #define USBH_USE_OS                    1
    #define USE_HAL_HCD_REGISTER_CALLBACKS 1U

    /****************************************/
    /* #define for FS and HS identification */
    #define HOST_HS 0
    #define HOST_FS 1

    /****************************************/
    // Below are details and bit masks for USB Core Interrupts, 0 inactive, 1 active

    // (Mode) - Desc.
    // -------------------------------------------------------------
    // (Host/Device) Resume/wakeup event detected (LPM state change)
    #define GINTSTS_WKUPINT         BIT(31)
    // (Host/Device) Session request/new session interrupt
    #define GINTSTS_SESSREQINT      BIT(30)
    // (Host Only) Disconnect event detected
    #define GINTSTS_DISCONNINT      BIT(29)
    // (Host/Device) Change in connector ID
    #define GINTSTS_CONIDSTSCHNG    BIT(28)
    // Unsure, might be ACK from device when it receives LPM request
    #define GINTSTS_LPMTRANRCVD     BIT(27)
    // (Host Only) Periodic TxFIFO empty, asserted when periodic tx FIFO is half or completely empty
    #define GINTSTS_PTXFEMP         BIT(26)
    // (Host Only) Core sets bit indicating an interrupt is pending on a Host Channel (HCH)
    #define GINTSTS_HCHINT          BIT(25) 
    // (Host Only) Host port interrupt, indicates change in port status.
    #define GINTSTS_PRTINT          BIT(24)
    // (Device Only) Reset detected on device, unused by host.
    #define GINTSTS_RESETDET        BIT(23)
    // (Device Only) Data Fetch Suspended, only valid in DMA mode.
    #define GINTSTS_FET_SUSP        BIT(22)
    // (Host/Device) Incomplete periodic transfer
    #define GINTSTS_INCOMPL_IP      BIT(21)
    // Same as above
    #define GINTSTS_INCOMPL_SOOUT   BIT(21)
    // (Device Only) Incomplete Isoch. IN Transfer
    #define GINTSTS_INCOMPL_SOIN    BIT(20)
    // (Device Only) Out Endpoints Interrupt, indicating EP from Host (OUT) has pending interrupt
    #define GINTSTS_OEPINT          BIT(19)
    // (Device Only) IN Endpoint Interrupt, indicating EP to Host (IN) has pending interrupt
    #define GINTSTS_IEPINT          BIT(18)
    // (Device Only) Endpoint Mismatch Interrupt
    #define GINTSTS_EPMIS           BIT(17)
    // Unknown
    #define GINTSTS_RESTOREDONE     BIT(16)
    // (Device Only) End of Periodic Frame interrupt
    #define GINTSTS_EOPF            BIT(15)
    // (Device Only) Isochr. out packet dropped interrupt
    #define GINTSTS_ISOUTDROP       BIT(14)
    // (Device Only) Enuemeration Done interrupt
    #define GINTSTS_ENUMDONE        BIT(13)
    // (Device Only) USB reset interrupt
    #define GINTSTS_USBRST          BIT(12)
    // (Device Only) USB suspend interrupt
    #define GINTSTS_USBSUSP         BIT(11)
    // (Device Only) Early suspend interrupt
    #define GINTSTS_ERLYSUSP        BIT(10)
    // Prsumably I2C interrupt
    #define GINTSTS_I2CINT          BIT(9)
    // Unknown
    #define GINTSTS_ULPI_CK_INT     BIT(8)
    // (Device Only) Global OUT NAK Effective
    #define GINTSTS_GOUTNAKEFF      BIT(7)
    // (Device Only) Global IN Non-periodic NAK Effective
    #define GINTSTS_GINNAKEFF       BIT(6)
    // (Host/Device) Non-periodic TxFIFO Empty
    #define GINTSTS_NPTXFEMP        BIT(5
    // (Host/Device) RxFIFO Non-Empty
    #define GINTSTS_RXFLVL          BIT(4)
    // (Host/Device) Start of (micro)Frame
    #define GINTSTS_SOF             BIT(3)
    // (Host/Device) OTG Interrupt, set on OTG protocl events.
    #define GINTSTS_OTGINT          BIT(2)
    // (Host/Device) Mode Mismatch interrupt (when host mode register is in device mode, visa versa)
    #define GINTSTS_MODEMIS         BIT(1)
    // (Host/Device) Current mode of operation, 0 = device, 1 = host
    #define GINTSTS_CURMODE_HOST    BIT(0)


    #if (USBH_USE_OS == 1)
        #include "cmsis_os.h"
        #define USBH_PROCESS_PRIO       osPriorityNormal
        #define USBH_PROCESS_STACK_SIZE ((uint16_t)128)
    #endif /* (USBH_USE_OS == 1) */

    /**
  * @}
  */

    /** @defgroup USBH_CONF_Exported_Macros USBH_CONF_Exported_Macros
  * @brief Aliases.
  * @{
  */

    /* Memory management macros */

    /** Alias for memory allocation. */
    #define USBH_malloc malloc

    /** Alias for memory release. */
    #define USBH_free free

    /** Alias for memory set. */
    #define USBH_memset memset

    /** Alias for memory copy. */
    #define USBH_memcpy memcpy

/* DEBUG macros */

    #if (USBH_DEBUG_LEVEL > 0)
        #define USBH_UsrLog(...) \
            printf(__VA_ARGS__); \
            printf("\n");
    #else
        #define USBH_UsrLog(...)
    #endif

    #if (USBH_DEBUG_LEVEL > 1)

        #define USBH_ErrLog(...) \
            printf("ERROR: ");   \
            printf(__VA_ARGS__); \
            printf("\n");
    #else
        #define USBH_ErrLog(...)
    #endif

    #if (USBH_DEBUG_LEVEL > 2)
        #define USBH_DbgLog(...) \
            printf("DEBUG : ");  \
            printf(__VA_ARGS__); \
            printf("\n");
    #else
        #define USBH_DbgLog(...)
    #endif

/**
  * @}
  */

/** @defgroup USBH_CONF_Exported_Types USBH_CONF_Exported_Types
  * @brief Types.
  * @{
  */

/**
  * @}
  */

/** @defgroup USBH_CONF_Exported_FunctionsPrototype USBH_CONF_Exported_FunctionsPrototype
  * @brief Declaration of public functions for Usb host.
  * @{
  */

/* Exported functions -------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

    #ifdef __cplusplus
}
    #endif

#endif /* __USBH_CONF__H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

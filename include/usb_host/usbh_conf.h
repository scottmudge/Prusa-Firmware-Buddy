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


    // Below are details and bit masks for USB Core Interrupt
    #define BIT(nr)                 (1UL << (nr))

    #define GINTSTS_WKUPINT         BIT(31)
    #define GINTSTS_SESSREQINT      BIT(30)
    #define GINTSTS_DISCONNINT      BIT(29)
    #define GINTSTS_CONIDSTSCHNG    BIT(28)
    #define GINTSTS_LPMTRANRCVD     BIT(27)
    #define GINTSTS_PTXFEMP         BIT(26)
    #define GINTSTS_HCHINT          BIT(25) // Host controller
    #define GINTSTS_PRTINT          BIT(24)
    #define GINTSTS_RESETDET        BIT(23)
    #define GINTSTS_FET_SUSP        BIT(22)
    #define GINTSTS_INCOMPL_IP      BIT(21)
    #define GINTSTS_INCOMPL_SOOUT   BIT(21)
    #define GINTSTS_INCOMPL_SOIN    BIT(20)
    #define GINTSTS_OEPINT          BIT(19)
    #define GINTSTS_IEPINT          BIT(18)
    #define GINTSTS_EPMIS           BIT(17)
    #define GINTSTS_RESTOREDONE     BIT(16)
    #define GINTSTS_EOPF            BIT(15)
    #define GINTSTS_ISOUTDROP       BIT(14)
    #define GINTSTS_ENUMDONE        BIT(13)
    #define GINTSTS_USBRST          BIT(12)
    #define GINTSTS_USBSUSP         BIT(11)
    #define GINTSTS_ERLYSUSP        BIT(10)
    #define GINTSTS_I2CINT          BIT(9)
    #define GINTSTS_ULPI_CK_INT     BIT(8)
    #define GINTSTS_GOUTNAKEFF      BIT(7)
    #define GINTSTS_GINNAKEFF       BIT(6)
    #define GINTSTS_NPTXFEMP        BIT(5)
    #define GINTSTS_RXFLVL          BIT(4)
    #define GINTSTS_SOF             BIT(3)
    #define GINTSTS_OTGINT          BIT(2)
    #define GINTSTS_MODEMIS         BIT(1)
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

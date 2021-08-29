 /******************************************************************************
 *
 * Autosar name : Dio Driver
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * AUTOSAR Version 4.3.1
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION   (3U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION           (1U)
#define DIO_CFG_SW_MINOR_VERSION           (0U)
#define DIO_CFG_SW_PATCH_VERSION           (0U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Macros for Dio Status */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (2U)

/* Number of the configured Dio Port */
#define DIO_CONFIGURED_PORTS                (1U)
   
/* Number of the configured GroupChannels */
#define DIO_CONFIGURED_GroupChannels        (0U)        

/* Macros for GroupChannel validety */
#define DIO_CHANNEL_GROUP_MAX_OFFSET   (7U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x01

/* Port Index in the Port array in Dio_PBcfg.c */
#define DioConf_PORT_ID_INDEX                (uint8)0x00

/* DIO Configured Port ID's  */
#define DIO_CONFIGURED_PORTF                 (Dio_PortType)5 /* PORTF */

/* DIO Configured Port ID's relative to configured channels  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)5 /* PORTF */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)5 /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)4 /* Pin 4 in PORTF */



#endif /* DIO_CFG_H */

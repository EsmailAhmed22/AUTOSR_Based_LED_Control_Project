/******************************************************************************
 *
 * AUTOSAR name : Port Driver
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (25U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (3U)
#define PORT_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/* MACROS for random numbers*/
#define MASK                    0x0000000F
#define SHIFT_LEFT_OFFSET       (4U)
#define UNLOCK_VALUE            0x4C4F434B
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT initialization function */
#define PORT_INIT_SID                        (uint8)0x00

/* Service ID for PORT Set Direction function */
#define PORT_SET_PIN_DIRECTION_SID           (uint8)0x01

/* Service ID for PORT Refresh Direction function */
#define PORT_REFRESH_PORT_DIRECTION_SID      (uint8)0x02

/* Service ID for PORT Version Info function */
#define PORT_GET_VERSION_INFO_SID            (uint8)0x03

/* Service ID for PORT Set Mode function */
#define PORT_SET_PIN_MODE_SID                (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID requested. */
#define PORT_E_PARAM_PIN                0x0A

/* DET code to report Port Pin not configured as changeable.*/
#define PORT_E_DIRECTION_UNCHANGEABLE   0x0B

/*DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG             0x0C

/* DET code to report API Port_SetPinMode service called when mode is invalid.*/
#define PORT_E_PARAM_INVALID_MODE       0x0D

/* DET code to report API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE        0x0E

/* DET code to report API service called without module initialization */
#define PORT_E_UNINIT                   0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER            0x10


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type of the external data structure containing the initialization data for this module */
typedef struct {
  /* Store Pin Number in port */
  uint8 Pin_Num;
  
  /* Store Port Number from 0 to 5 */
  uint8 Port_Num;
  
  /* Set Pin Direction input or output */
  uint8 Pin_Direction;
  
  /* For input pins select Pull up or Pull down */
  uint8 Pull_Up_Down_Choice;
  
  /* Cover All Modes */
  uint8 Pin_Mode;  
  
  /* Choose initial value for ouput pins*/
  uint8 Iniit_Output_Value; 
  
  /* Decide if the mode can be changed or not */ 
  uint8 Pin_Mode_Changeable;
  
  /* Decide if the direction can be changed or not */
  uint8 Pin_Direction_Changeable;

}Port_Pins_ConfigType;
/* Type of the external data structure containing the initialization data for this module */
typedef struct {
  Port_Pins_ConfigType Pins[PORT_CONFIGURED_PORT_PINS ];
}Port_ConfigType;

/* Data type for the symbolic name of a port pin. */
typedef uint8 Port_PinType;

/*Possible directions of a port pin.*/
typedef uint8 Port_PinDirectionType;

/* Different port pin modes. */
typedef uint8 Port_PinModeType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Initializes the Port Driver module.*/
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Sets the port pin direction*/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );

/* Refreshes port direction.*/
void Port_RefreshPortDirection( void );

#if (PORT_VERSION_INFO_API == STD_ON)
/* Returns the version information of this module.*/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

/* Sets the port pin mode.*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
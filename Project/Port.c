 /******************************************************************************
 *
 * Autosar name : Port Driver
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif


STATIC const Port_Pins_ConfigType * Port_Pins = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr ){
  
   /* Pointer to point at the Base Address of the Port */ 
   volatile uint32 * Port_Ptr = NULL_PTR;
   /* Delay to give port time to be enabled */
   volatile unsigned long delay = 0;
    
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if input pointer is not Null pointer */ 
  if ( ConfigPtr == NULL_PTR){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
	                PORT_E_PARAM_CONFIG);
  }
  else
  {
    /* No Action Required */
  }
#endif
  Port_Status = PORT_INITIALIZED;
  Port_Pins = ConfigPtr->Pins;
  for(uint8 Pin= 0 ; Pin < PORT_CONFIGURED_PORT_PINS ; Pin++)
  {
  /* Switch case to select the required port */
  switch((Port_Pins+Pin)->Port_Num)
  {
     case 0:    Port_Ptr = &GPIO_PORTA_BASE_ADDRESS;
		break;
     case 1:    Port_Ptr = &GPIO_PORTB_BASE_ADDRESS;
		break;
     case 2:    Port_Ptr = &GPIO_PORTC_BASE_ADDRESS;
		break;
     case 3:    Port_Ptr = &GPIO_PORTD_BASE_ADDRESS;
		break;
     case 4:    Port_Ptr = &GPIO_PORTE_BASE_ADDRESS;
		break;
     case 5:    Port_Ptr = &GPIO_PORTF_BASE_ADDRESS;
		break;
  }
  
  /**********Enable clock for PORTx and allow time for clock to start**********/  
  SET_BIT(PORT_ClOCK_REGISTER,(Port_Pins+Pin)->Pin_Num);
  delay = PORT_ClOCK_REGISTER;
  
  /*********Check if it is locked Pin then Unlock it***************************/
  if(Pin == PORT_C_PIN_0  |Pin == PORT_C_PIN_1 |Pin == PORT_C_PIN_2 
    |Pin == PORT_C_PIN_3  |Pin == PORT_D_PIN_7 |Pin == PORT_F_PIN_0 )
  {
    *(Port_Ptr+PORT_LOCK_REG_OFFSET)= UNLOCK_VALUE;
    *(Port_Ptr+PORT_COMMIT_REG_OFFSET)|=(1<<(Port_Pins+Pin)->Pin_Num);
  }
  else
  {
    /*No Required Action */
  }
  /***************************Setting Pin Direction****************************/
  /* In case Input pin */
  if((Port_Pins+Pin)->Pin_Direction == PORT_PIN_IN)
  {
    /* Clear the pin in the direction register to make it input pin */
    CLEAR_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* In case Output pin */
  else
  {
    /* Set the pin in the direction register to make it output pin */
    SET_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }

  /***************** Setting Pin Pull-Up or Pull-Down or OFF ******************/
  /* In case PULL UP*/
  if((Port_Pins+Pin)->Pull_Up_Down_Choice == PORT_PIN_PULL_UP)
  {
    /* Set the pin in the PULL-UP register to make it PULL-UP pin */
    SET_BIT(*(Port_Ptr+PORT_PULL_UP_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* In case PULL DOWN*/
  else if((Port_Pins+Pin)->Pull_Up_Down_Choice == PORT_PIN_PULL_DOWN)
  {
    /* Set the pin in the PULL-DOWN register to make it PULL-DOWN pin */
    SET_BIT(*(Port_Ptr+PORT_PULL_DOWN_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* In case NO PULL*/
  else
  {
    /* Clear the pin in both Pull-up and Pull-down register */
    CLEAR_BIT(*(Port_Ptr+PORT_PULL_UP_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    CLEAR_BIT(*(Port_Ptr+PORT_PULL_DOWN_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  
  /*********************** Setting Pin Mode************************************/
  /* DIO Mode*/
  if((Port_Pins+Pin)->Pin_Mode == PORT_DIGITAL_IO)
  {    
    /* Clear alternative selection bit to make it GPIO pin */
    CLEAR_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Clear Analog bit to enable the analog isolation circuit */ 
    CLEAR_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Enable the GPIO pin to be Digital pin  */
    SET_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* ANALOG Mode */
  else if((Port_Pins+Pin)->Pin_Mode == PORT_ANALOG_IO )
  { 
    /* Set alternative selection bit to make it alternative function pin */
    SET_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Disable the GPIO pin to be Digital pin  */
    CLEAR_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Set Analog bit to enable the analog isolation circuit */ 
    SET_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  } 
  /* For any other Mode */
  else
  {    
    /* Clear Analog bit to enable the analog isolation circuit */ 
    CLEAR_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Enable the GPIO pin to be Digital pin  */
    SET_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Set alternative selection bit to make it alternative function pin */
    SET_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Clear the section of the required pin (clear 4-bits) */
    *(Port_Ptr+PORT_CTL_REG_OFFSET)&= ~( MASK << ((Port_Pins+Pin)->Pin_Num)*SHIFT_LEFT_OFFSET);
    
    /* Set the alternative function value to make it PWM  */
    *(Port_Ptr+PORT_CTL_REG_OFFSET)|= ( (Port_Pins+Pin)->Pin_Mode << ((Port_Pins+Pin)->Pin_Num)*SHIFT_LEFT_OFFSET);
  }
  
  /*********************** Setting Pin Initial Value***************************/
  /* In case Initiak value of the pin is ONE */
  if((Port_Pins+Pin)->Iniit_Output_Value == PORT_INITIAL_VALUE_ON)
  {
    /* Set the pin in the data register to make its output High */
    SET_BIT(*(Port_Ptr+PORT_DATA_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* In case Initiak value of the pin is ZERO */
  else
  {
    /* Clear the pin in the data register to make its output Low */
    CLEAR_BIT(*(Port_Ptr+PORT_DATA_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  
  }
}
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous.
* Reentrancy: Reentrant.
* Parameters (in): Pin - Port Pin ID number.
*                  Direction - Port Pin Direction.                   
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Sets the port pin direction.
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction ){
   
   /* Pointer to point at the Base Address of the Port */ 
   volatile uint32 * Port_Ptr = NULL_PTR;
   
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if Port Module has been initialized */ 
  if(Port_Status == PORT_NOT_INITIALIZED){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	                PORT_E_UNINIT);  
  }
  else
  {
    /* No Action Required */
  }
  
  /* Check if PinId is in the range */
  if( Pin >= PORT_CONFIGURED_PORT_PINS ){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	                PORT_E_PARAM_PIN);
  }
    else
  {
    /* No Action Required */
  }
  
  /* Check if the Pin is Direction Changeable */
  if((Port_Pins+Pin)->Pin_Direction_Changeable == PORT_PIN_NOT_CHANGEABLE){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,
	                PORT_E_DIRECTION_UNCHANGEABLE);  
  }
  else
  {
    /* No Action Required */
  }
#endif
  /* Switch case to select the required port */
  switch((Port_Pins+Pin)->Port_Num)
  {
     case 0:    Port_Ptr = &GPIO_PORTA_BASE_ADDRESS;
		break;
     case 1:    Port_Ptr = &GPIO_PORTB_BASE_ADDRESS;
		break;
     case 2:    Port_Ptr = &GPIO_PORTC_BASE_ADDRESS;
		break;
     case 3:    Port_Ptr = &GPIO_PORTD_BASE_ADDRESS;
		break;
     case 4:    Port_Ptr = &GPIO_PORTE_BASE_ADDRESS;
		break;
     case 5:    Port_Ptr = &GPIO_PORTF_BASE_ADDRESS;
		break;
  }
  
  /* If-else to change the direction of the pin based on the input(Direction) */
  if(Direction == PORT_PIN_IN)
  {
    /* Clear the required pin in the direction register to make it input pin */
    CLEAR_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  else
  {
    /* Set the required pin in the direction register to make it output pin */
    SET_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
}
#endif /* PORT_SET_PIN_DIRECTION_API  */

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous.
* Reentrancy: Non Reentrant.
* Parameters (in): None.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void ){
  /* Pointer to point at the Base Address of the Port */ 
  volatile uint32 * Port_Ptr = NULL_PTR;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if Port Module has been initialized */
  if(Port_Status == PORT_NOT_INITIALIZED){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_REFRESH_PORT_DIRECTION_SID,
	                PORT_E_UNINIT);  
  }
  else
  {
    /* No Action Required */
  }
#endif
  /* A loop to loop on all the initialized pins */
  for(int i = 0 ; i < PORT_CONFIGURED_PORT_PINS ; i++){
    /* If condition to exclude pins that are configured changeable */
    if((Port_Pins+i)->Pin_Direction_Changeable == PORT_PIN_NOT_CHANGEABLE ){
	/* Switch case to select the required port */
        switch((Port_Pins+i)->Port_Num)
	{
          case 0:    Port_Ptr = &GPIO_PORTA_BASE_ADDRESS;
		     break;
          case 1:    Port_Ptr = &GPIO_PORTB_BASE_ADDRESS;
		     break;
          case 2:    Port_Ptr = &GPIO_PORTC_BASE_ADDRESS;
		     break;
          case 3:    Port_Ptr = &GPIO_PORTD_BASE_ADDRESS;
		     break;
          case 4:    Port_Ptr = &GPIO_PORTE_BASE_ADDRESS;
		     break;
          case 5:    Port_Ptr = &GPIO_PORTF_BASE_ADDRESS;
		     break;
	}
        
        /* Refreshing the pin direction based on Pin_Direction member */
        if((Port_Pins+i)->Pin_Direction == PORT_PIN_IN )
        {
          CLEAR_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+i)->Pin_Num);
        }
        else
        {
          SET_BIT(*(Port_Ptr+PORT_DIR_REG_OFFSET),(Port_Pins+i)->Pin_Num);
        }
    }
  }
}
#if (PORT_VERSION_INFO_API == STD_ON)
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if Port Module has been initialized */
  if(Port_Status == PORT_NOT_INITIALIZED){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,
	                PORT_E_UNINIT);  
  }
  else
  {
    /* No Action Required */
  }
  
  /* Check if input pointer is not Null pointer */
  if(NULL_PTR == versioninfo)
  {
        /* Report to DET  */
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,
	                PORT_E_PARAM_POINTER);
  }
    else
  {
    /* No Action Required */
  }
  
#endif
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
  }  
}
#endif /* PORT_VERSION_INFO_API */

#if (PORT_SET_PIN_MODE_API == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous.
* Reentrancy: Reentrant.
* Parameters (in): Pin - Port Pin ID number.
*                  Mode - New Port Pin mode to be set on port pin.. 
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode ){
  /* Pointer to point at the Base Address of the Port */ 
  volatile uint32 * Port_Ptr = NULL_PTR;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /* Check if Port Module has been initialized */
  if(Port_Status == PORT_NOT_INITIALIZED){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID ,
	                PORT_E_UNINIT);  
  }
  else
  {
    /* No Action Required */
  }
  
  /* Check if PinId is in the range */
  if( Pin >= PORT_CONFIGURED_PORT_PINS ){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,
	                PORT_E_PARAM_PIN);
  }
    else
  {
    /* No Action Required */
  }
  
  /* Check if the Pin is Mode Changeable */
  if((Port_Pins+Pin)->Pin_Mode_Changeable == PORT_PIN_NOT_CHANGEABLE){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,
	                PORT_E_DIRECTION_UNCHANGEABLE);  
  }
  else
  {
    /* No Action Required */
  }
  
  /* Check if Mode is include */
  if( Mode >= MAX_MODE_NUMBER ){
    	Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,
	                PORT_E_PARAM_INVALID_MODE);
  }
    else
  {
    /* No Action Required */
  }
  
#endif
  /* Switch case to select the required port */
  switch((Port_Pins+Pin)->Port_Num)
  {
     case 0:    Port_Ptr = &GPIO_PORTA_BASE_ADDRESS;
		break;
     case 1:    Port_Ptr = &GPIO_PORTB_BASE_ADDRESS;
		break;
     case 2:    Port_Ptr = &GPIO_PORTC_BASE_ADDRESS;
		break;
     case 3:    Port_Ptr = &GPIO_PORTD_BASE_ADDRESS;
		break;
     case 4:    Port_Ptr = &GPIO_PORTE_BASE_ADDRESS;
		break;
     case 5:    Port_Ptr = &GPIO_PORTF_BASE_ADDRESS;
		break;
  } 
    
  /* GPIO Mode*/
  if(Mode == PORT_DIGITAL_IO)
  {    
    /* Clear alternative selection bit to make it GPIO pin */
    CLEAR_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Clear Analog bit to enable the analog isolation circuit */ 
    CLEAR_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Enable the GPIO pin to be Digital pin  */
    SET_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  }
  /* ANALOG Mode */
  else if(Mode == PORT_ANALOG_IO )
  { 
    /* Set alternative selection bit to make it alternative function pin */
    SET_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Disable the GPIO pin to be Digital pin  */
    CLEAR_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Set Analog bit to enable the analog isolation circuit */ 
    SET_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
  } 
  /* For any other Mode */
  else
  {    
    /* Clear Analog bit to enable the analog isolation circuit */ 
    CLEAR_BIT(*(Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Enable the GPIO pin to be Digital pin  */
    SET_BIT(*(Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Set alternative selection bit to make it alternative function pin */
    SET_BIT(*(Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),(Port_Pins+Pin)->Pin_Num);
    
    /* Clear the section of the required pin (clear 4-bits) */
    *(Port_Ptr+PORT_CTL_REG_OFFSET)&= ~( MASK << ((Port_Pins+Pin)->Pin_Num)*SHIFT_LEFT_OFFSET);
    
    /* Set the alternative function value to make it PWM  */
    *(Port_Ptr+PORT_CTL_REG_OFFSET)|= ( Mode << ((Port_Pins+Pin)->Pin_Num)*SHIFT_LEFT_OFFSET);
  }
}
#endif /* PORT_SET_PIN_MODE_API */
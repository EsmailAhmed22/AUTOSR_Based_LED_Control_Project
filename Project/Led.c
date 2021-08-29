/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Esmail Ahmed
 ******************************************************************************/
#include "Port.h"
#include "Dio.h"
#include "Led.h"


/********************************************************************************
 *[Function Name]:LED_setOn
 *[Description]  :Function used to Set the LED state to ON.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void LED_setOn(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_ON);  /* LED ON */
}

/********************************************************************************
 *[Function Name]:LED_setOff
 *[Description]  :Function used to Set the LED state to OFF.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void LED_setOff(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_OFF); /* LED OFF */
}

/********************************************************************************
 *[Function Name]:LED_refreshOutput
 *[Description]  :Function used to Refresh the LED state.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void LED_refreshOutput(void)
{
    Dio_LevelType state = Dio_ReadChannel(DioConf_LED1_CHANNEL_ID_INDEX);
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,state); /* re-write the same value */
}

/********************************************************************************
 *[Function Name]:LED_toggle
 *[Description]  :Function used to Toggle the LED state.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void LED_toggle(void)
{
    Dio_LevelType state = Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
}



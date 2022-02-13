 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: App.c
 *
 * Description: Source file for Application Tasks.
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Dio.h"
#include "Port.h"

/********************************************************************************
 *[Function Name]:Init_Task
 *[Description]  :Task executes once to initialize all the Modules.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Init_Task(void)
{

    /* Initialize Port Driver */
    Port_Init(&Port_Configuration);
    
    /* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);
    
}

/********************************************************************************
 *[Function Name]:Button_Task
 *[Description]  :Task executes every 20 Mili-seconds to check the button state.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Button_Task(void)
{
    BUTTON_refreshState();
}

/********************************************************************************
 *[Function Name]:Led_Task
 *[Description]  :Task executes every 40 Mili-seconds to refresh the LED.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Led_Task(void)
{
    LED_refreshOutput();
}

/********************************************************************************
 *[Function Name]:App_Task
 *[Description]  :Task executes every 60 Mili-seconds to get the button status and toggle the led.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void App_Task(void)
{
    static uint8 button_previous_state = BUTTON_RELEASED;
    static uint8 button_current_state  = BUTTON_RELEASED;
	
    button_current_state = BUTTON_getState(); /* Read the button state */
	
    /* Only Toggle the led in case the current state of the switch is pressed
     * and the previous state is released */ 
    if((button_current_state == BUTTON_PRESSED) && (button_previous_state == BUTTON_RELEASED))
    {
	LED_toggle();
    }
	
    button_previous_state = button_current_state;
}

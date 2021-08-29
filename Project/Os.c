 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#include "Os.h"
#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Gpt.h"

/* Global variable store the Os Time */
static uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static uint8 g_New_Time_Tick_Flag = 0;

/********************************************************************************
 *[Function Name]:Os_start
 *[Description]  :Function responsible for:
 *                      1. Enable Interrupts
 *                      2. Start the Os timer
 *                      3. Execute the Init Task
 *                      4. Start the Scheduler to run the tasks
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Os_start(void)
{
    /* Global Interrupts Enable */
    Enable_Interrupts();
    
    /* 
     * Set the Call Back function to call Os_NewTimerTick
     * this function will be called every SysTick Interrupt (20ms)
     */
    SysTick_SetCallBack(Os_NewTimerTick);

    /* Start SysTickTimer to generate interrupt every 20ms */
    SysTick_Start(OS_BASE_TIME);

    /* Execute the Init Task */
    Init_Task();

    /* Start the Os Scheduler */
    Os_Scheduler();
}

/********************************************************************************
 *[Function Name]:Os_NewTimerTick
 *[Description]  :Function called by the Timer Driver in the MCAL layer using the call back pointer.
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Os_NewTimerTick(void)
{
    /* Increment the Os time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/********************************************************************************
 *[Function Name]:Os_Scheduler
 *[Description]  :The Engine of the Os Scheduler used for switch between different tasks. 
 *[input]        :None.
 *[Returns]	 :None.
*********************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {
	/* Code is only executed in case there is a new timer tick */
	if(g_New_Time_Tick_Flag == 1)
	{
	    switch(g_Time_Tick_Count)
            {
		case 20:
		case 100:
			    Button_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 40:
		case 80:
			    Button_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 60:
			    Button_Task();
			    App_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 120:
			    Button_Task();
			    App_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    g_Time_Tick_Count = 0;
			    break;
            }
	}
    }

}

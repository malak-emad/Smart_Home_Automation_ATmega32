 /******************************************************************************
 * led.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include "led.h"
#include "gpio.h"

/*
 * Description :
 * Function responsible for initializing the LED driver :
 * 1. Set the port direction using GPIO driver.
 * 2. Initialize the LEDs as OFF using GPIO driver.
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_PORT_ID, RED_LED_ID,   PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, GREEN_LED_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, BLUE_LED_ID,  PIN_OUTPUT);

	GPIO_writePin(LED_PORT_ID, RED_LED_ID,   LED_OFF);
	GPIO_writePin(LED_PORT_ID, GREEN_LED_ID, LED_OFF);
	GPIO_writePin(LED_PORT_ID, BLUE_LED_ID,  LED_OFF);
}

/*
 * Description :
 * Function responsible for turning the LED On using GPIO driver.
 */
void LED_on(LED_ID id)
{
	GPIO_writePin(LED_PORT_ID, id, LED_ON);

}

/*
 * Description :
 * Function responsible for turning the LED Off using GPIO driver.
 */
void LED_off(LED_ID id)
{
	GPIO_writePin(LED_PORT_ID, id, LED_OFF);
}

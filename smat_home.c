 /******************************************************************************
 * smart_home.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Malak
 *******************************************************************************/

#include<stdio.h>
#include<util/delay.h>

#include "adc.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "LCD.h"
#include "ldr_sensor.h"
#include "led.h"
#include "lm35_temp_sensor.h"

extern uint8 g_dcMotorFanState;
uint8 FlameSensor_flag=0;

int main(void){
	uint8 temp = 0;
	uint16 light = 0;

	ADC_init();
	LEDS_init();
	BUZZER_init();
	DcMotor_init();
	FlameSensor_init();
	LCD_init();

	LCD_displayString("FAN is ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp=  C LDR=  ");
	LCD_displayCharacter('%');

	while(1){
		LCD_moveCursor(0,7);
		/* Motor state */
		if(g_dcMotorFanState){
			LCD_displayString("ON ");
		}
		else LCD_displayString("OFF");

		temp = LM35_getTemprature();				/* Get current temperature */
		light = LDR_getLightIntensity();			/* Get current Light Intensity */
		LCD_moveCursor(1,5);
		LCD_intgerToString(temp);					/* Display current Temperature */
		LCD_moveCursor(1,13);
		/* Adjust LCD to display the Light Intensity*/
		if(light<10){
			LCD_intgerToString(light);
			LCD_displayString("% ");
		}
		else if(light>=10 && light<100){
			LCD_intgerToString(light);
			LCD_displayString("%");
		}
		else{
			LCD_intgerToString(light);
		}


 /* Temperature code */
		if(temp>=40){
			DcMotor_Rotate(1, 100);
		}
		else if((temp>=35) && (temp<40)){
			DcMotor_Rotate(1, 75);
		}
		else if((temp>=30) && (temp<35)){
			DcMotor_Rotate(1, 50);
		}
		else if((temp>=25) && (temp<30)){
			DcMotor_Rotate(1, 25);
		}
		else{
			DcMotor_Rotate(0, 0);
		}

/* Flame sensor Code */
		if(FlameSensor_getValue()){					/* Flame sensor detected fire */
			FlameSensor_flag=1;
			LCD_clearScreen();
			LCD_moveCursor(0,0);
			LCD_displayString("Critical alert!");
			BUZZER_on();
			while(FlameSensor_getValue());
		}
		else if(FlameSensor_flag==1){				/* If the fire has stopped */
			FlameSensor_flag=0;
			BUZZER_off();

			LCD_clearScreen();
			LCD_displayString("FAN is ");
			LCD_moveCursor(1,0);
			LCD_displayString("Temp=  C LDR=   %");
			LCD_moveCursor(0,7);

			if(g_dcMotorFanState){					/* Motor state */
				LCD_displayString("ON ");
			}
			else LCD_displayString("OFF");

			temp = LM35_getTemprature();
			light = LDR_getLightIntensity();
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);
			LCD_moveCursor(1,13);
			LCD_intgerToString(light);
		}


/* Leds code */
		if(light<=15){
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_on(BLUE_LED_ID);
		}
		else if(light>=16 && light<50){
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}
		else if(light>=50 && light<70){
			LED_on(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}
		else{
			LED_off(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}
	}
}


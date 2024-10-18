/*********************************************************************
 * LCD.c
 *
 *  Created on: Sep 26, 2024
 *      Author: Malak
 *********************************************************************/
#include "LCD.h"
#include "gpio.h"
#include "common_macros.h"
#include<avr/io.h>
#include<util/delay.h>

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void){
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

	_delay_ms(20);				/* LCD Power ON delay always > 15ms */

#if (LCD_DATA_BIT_MODE == 4)
	/* configure 4 pins in data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DATA_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DATA_PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DATA_PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DATA_PIN4_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif (LCD_DATA_BIT_MODE == 8)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);
	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif

	LCD_sendCommand(LCD_CURSOR_OFF);	/* Cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND);	/* clear LCD at the beginning */

}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command){


	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW);  /* Instruction Mode RS=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	  /* Enable LCD E =1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if (LCD_DATA_BIT_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN1_ID, GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN2_ID, GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN3_ID, GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN4_ID, GET_BIT(command,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN1_ID, GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN2_ID, GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN3_ID, GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN4_ID, GET_BIT(command,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */

#elif (LCD_DATA_BIT_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID, command);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
#endif
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */

}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data){

	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* Data Mode RS=1 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if (LCD_DATA_BIT_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN1_ID, GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN2_ID, GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN3_ID, GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN4_ID, GET_BIT(data,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN1_ID, GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN2_ID, GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN3_ID, GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DATA_PIN4_ID, GET_BIT(data,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */


#elif (LCD_DATA_BIT_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID, data);
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
#endif
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1); /* delay for processing Th = 13ns */

}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str){

	while(*Str != '\0'){
		LCD_displayCharacter(*Str);
		Str++;
	}
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str){

	LCD_moveCursor(row, col);  /* go to to the required LCD position */
	LCD_displayString(Str);	   /* display the string */
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col){

	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address = 0x00 + col;
		break;

	case 1:
		lcd_memory_address = 0x40 + col;
		break;

	case 2:
		lcd_memory_address = 0x10 + col;
		break;

	case 3:
		lcd_memory_address = 0x50 + col;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_CURSOR_AT_BEGGINING_FIRST_LINE);
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data){
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/* Description :
 * Move to the beginning of second line
 */
void LCD_secondLine(void){
	LCD_sendCommand(LCD_CURSOR_AT_BEGGINING_SECOND_LINE); /* Send beggining of second line command */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}





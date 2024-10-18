/*****************************************************************************
 * LCD.h
 *
 *  Created on: Sep 26, 2024
 *      Author: Malak
 *****************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/*******************************************************************************
 *                      		Definitions                                   *
 *******************************************************************************/

#define LCD_DATA_BIT_MODE 8
#if ((LCD_DATA_BIT_MODE != 4) && (LCD_DATA_BIT_MODE != 8))
#error "Number of Data bits should be equal to 4 or 8"
#endif

#define LCD_RS_PORT_ID							PORTD_ID
#define LCD_RS_PIN_ID 							PIN0_ID

#define LCD_E_PORT_ID							PORTD_ID
#define LCD_E_PIN_ID							PIN1_ID

#define LCD_DATA_PORT_ID						PORTC_ID
#if (LCD_DATA_BIT_MODE == 4)
#define LCD_DATA_PIN1_ID						PIN3_ID
#define LCD_DATA_PIN2_ID						PIN4_ID
#define LCD_DATA_PIN3_ID						PIN5_ID
#define LCD_DATA_PIN4_ID						PIN6_ID
#endif

#define LCD_CLEAR_COMMAND						0x01
#define LCD_HOME								0x02
#define LCD_TWO_LINES_FOUR_BITS_MODE			0x28
#define LCD_TWO_LINES_EIGHT_BITS_MODE			0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   	0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   	0x32
#define LCD_CURSOR_OFF							0x0C
#define LCD_CURSOR_ON							0x0E
#define LCD_CURSOR_AT_BEGGINING_FIRST_LINE		0x80
#define LCD_CURSOR_AT_BEGGINING_SECOND_LINE		0xC0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

void LCD_moveCursor(uint8 row,uint8 col);

/* Description :
 * Move to the beginning of second line
 */
void LCD_secondLine(void);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */

/*	neopixel.h
 *	Created by:		John Sabino
 *	Date Created:		03/14/2015
 *	Last Date Modified:	03/14/2015
 * 	
 *	Revisions:
 *	0.0.1 (03/14/2015) - File created.
 *
 *
 ***********************************************/

//Libraries:
#include <avr/io.h>
#include <util/delay.h>

//Preprocessor Checks:
#ifndef F_CPU
	#error "F_CPU not defined, please define this before your libraries."
#endif

#if (F_CPU < 8000000)
	#warning "F_CPU is lower than required to properly utilize this library. Communications may not work properly."
#endif


//Structures:
volatile struct Color{
	volatile uint8_t green;
	volatile uint8_t red;
	volatile uint8_t blue;
};


//Function Prototypes:
void Send_Data(uint8_t reg, uint8_t pin, uint16_t number_of_leds, volatile struct Color color[]);
	// reg = register (i.e. PORTA, PORTB, PORTC, PORTD, PORTE, ...)
	// pin = pin (i.e. PORTA0, PORTA1, ...)
	// number_of_leds = The number of LEDs that you wish to communicate with.
	// Color = An array of structures that is the length of the number_of_leds variable.
	//	   The Color structure stores the corresponding color values for a single LED.



/*
 *
 *
 *
 *
 *
 *
 *
 *
 ******************************************************/

//Libraries:
#include "neopixel.h"

#define F_CPU 8000000

void Send_Data(uint8_t reg, uint8_t pin, uint16_t number_of_leds, volatile struct Color color[])
{
	
#ifdef INTERRUPTS_CHECK
	cli;		//Disable gLowbal interrupts.
#endif
	volatile uint8_t  High = reg | pin;
	volatile uint8_t  Low  = reg & ~pin;
	volatile uint8_t  n1   = Low;
	volatile uint8_t  n2   = Low;
		
#if (F_CPU == 8000000)		//125nS per cycle.


	volatile uint16_t i    = (number_of_leds * 3);
 	
	asm volatile(
	"head:" "\n\t" 		// Clk Pseudocode
	
	// Bit 7:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n2] , %[Low]" "\n\t" 	// 1 n2 = Low
	"out %[port] , %[n1]" "\n\t" 	// 1 PORT = n1
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 6" "\n\t" 	// 1-2 if(b & 0x40)
	"mov %[n2] , %[High]" "\n\t" 	// 0-1 n2 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t" 		// 2 nop nop
	
	// Bit 6:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n1] , %[Low]" "\n\t" 	// 1 n1 = Low
	"out %[port] , %[n2]" "\n\t" 	// 1 PORT = n2
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 5" "\n\t" 	// 1-2 if(b & 0x20)
	"mov %[n1] , %[High]" "\n\t" 	// 0-1 n1 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t" 		// 2 nop nop
	
	// Bit 5:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n2] , %[Low]" "\n\t" 	// 1 n2 = Low
	"out %[port] , %[n1]" "\n\t" 	// 1 PORT = n1
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 4" "\n\t" 	// 1-2 if(b & 0x10)
	"mov %[n2] , %[High]" "\n\t" 	// 0-1 n2 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t" 		// 2 nop nop
	
	// Bit 4:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n1] , %[Low]" "\n\t" 	// 1 n1 = Low
	"out %[port] , %[n2]" "\n\t" 	// 1 PORT = n2
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 3" "\n\t" 	// 1-2 if(b & 0x08)
	"mov %[n1] , %[High]" "\n\t" 	// 0-1 n1 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t" 		// 2 nop nop
	
	// Bit 3:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n2] , %[Low]" "\n\t" 	// 1 n2 = Low
	"out %[port] , %[n1]" "\n\t" 	// 1 PORT = n1
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 2" "\n\t" 	// 1-2 if(b & 0x04)
	"mov %[n2] , %[High]" "\n\t" 	// 0-1 n2 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t" 		// 2 nop nop
	
	// Bit 2:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n1] , %[Low]" "\n\t" 	// 1 n1 = Low
	"out %[port] , %[n2]" "\n\t" 	// 1 PORT = n2
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 1" "\n\t" 	// 1-2 if(b & 0x02)
	"mov %[n1] , %[High]" "\n\t" 	// 0-1 n1 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"rjmp .+0" "\n\t"	 	// 2 nop nop
	
	// Bit 1:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n2] , %[Low]" "\n\t" 	// 1 n2 = Low
	"out %[port] , %[n1]" "\n\t" 	// 1 PORT = n1
	"rjmp .+0" "\n\t" 		// 2 nop nop
	"sbrc %[byte] , 0" "\n\t" 	// 1-2 if(b & 0x01)
	"mov %[n2] , %[High]" "\n\t" 	// 0-1 n2 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"sbiw %[count], 1" "\n\t" 	// 2 i-- (don't act on Z flag yet)
	
	// Bit 0:
	"out %[port] , %[High]" "\n\t" 	// 1 PORT = High
	"mov %[n1] , %[Low]" "\n\t" 	// 1 n1 = Low
	"out %[port] , %[n2]" "\n\t" 	// 1 PORT = n2
	"ld %[byte] , %a[ptr]+" "\n\t" 	// 2 b = *ptr++
	"sbrc %[byte] , 7" "\n\t" 	// 1-2 if(b & 0x80)
	"mov %[n1] , %[High]" "\n\t" 	// 0-1 n1 = High
	"out %[port] , %[Low]" "\n\t" 	// 1 PORT = Low
	"brne head" "\n" 		// 2 wHighle(i) (Z flag set above)

	: [byte] 	"+r" (color),
	  [n1] 	 	"+r" (n1),
	  [n2] 	 	"+r" (n2),
	  [count] 	"+w" (i)
	
	: [port] 	"I" (reg),
	  [ptr] 	"e" (ptr),
	  [High]	"r" (High),
	  [Low] 	"r" (Low)
	);



//-------------------------------------------------

#elif (F_CPU == 16000000)		//62nS per cycle.



#else
	#error "No code exists for anything slower than 8MHz."
#endif

#ifdef INTERRUPTS_CHECK
	sei;		//Enable gLowbal interrupts.
#endif
}//End Send_Data


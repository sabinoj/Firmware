micro = atmega32
flags = -g -O3
library_path = ../../../lib/NewHaven_Displays/NHD-160128WG/

makeCompile: main.c
	avr-gcc $(flags) -mmcu=$(micro) -c main.c $(library_path)/NHD-160128WG.c
	avr-gcc $(flags) -mmcu=$(micro) -o main.elf main.o NHD-160128WG.o
	rm NHD-160128WG.o main.o
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	rm main.elf

program: main.hex 
	sudo avrdude -c USBasp -p $(micro) -U flash:w:main.hex:i

main: main.c
	avr-gcc -g -O3 -mmcu=$(micro) -c main.c $(library_path)/NHD-160128WG.c
	avr-gcc -g -O3 -mmcu=$(micro) -o main.elf main.o NHD-160128WG.o
	rm NHD-160128WG.o main.o
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	sudo avrdude -c USBasp -p $(micro) -U flash:w:main.hex:i
	rm main.elf

test: test.c
	avr-gcc $(flags) -mmcu=$(micro) -c test.c $(library_path)/NHD-160128WG.c
	avr-gcc $(flags) -mmcu=$(micro) -o test.elf test.o NHD-160128WG.o
	rm test.o NHD-160128WG.o
	avr-objcopy -j .text -j .data -O ihex test.elf test.hex
	sudo avrdude -c USBasp -p $(micro) -U flash:w:test.hex:i
	rm test.elf	

setfuseExt:
	avrdude -c USBasp -p $(micro) -U lfuse:w:0xce:m -U hfuse:w:0xd9:m 

setfuseInt:
	avrdude -c USBasp -p $(micro) -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m 

setfuseDefault:
	avrdude -c USBasp -p $(micro) -U lfuse:w:0xe1:m -U hfuse:w:0x99:m 


flags = -Os

makeCompile: Sigmux.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/security.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/wlan.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/socket.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/hci.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/cc3000_common.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/evnt_handler.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/netapp.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/nvmem.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c ./CC3000HostDriver/spi.c
	avr-gcc -g $(flags) -mmcu=atmega32u4 -c Sigmux.c 
	avr-gcc -g $(flags) -mmcu=atmega32u4 -o Sigmux.elf ./Sigmux.o ./spi.o ./socket.o ./wlan.o ./nvmem.o ./cc3000_common.o ./evnt_handler.o ./hci.o ./netapp.o ./security.o
	rm *.o
	avr-objcopy -j .text -j .data -O ihex Sigmux.elf Sigmux.hex

upload: Sigmux.hex
	sudo avrdude -c USBasp -p atmega32u4 -U flash:w:Sigmux.hex:i

build_lib:
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/security.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/wlan.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/socket.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/hci.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/cc3000_common.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/evnt_handler.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/netapp.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/nvmem.c
	avr-gcc -g -O3 -mmcu=atmega32u4 -c ./CC3000HostDriver/spi.c
	rm *.o		



led_on_c.bin : start.s main.c
	arm-linux-gcc -o start.o start.s
	arm-linux-gcc -o mian.o	mian.c
	arm-linux-dl -Ttext 0x00000000 start.o main.o -o led_on_c_elf
	arm-linux-objcopy -O binary -S led_on_c_elf led_on_c.bin
	arm-linux-objdump -D -m arm led_on_c_elf > led_on_c.dis
clean:
	rm -f led_on_c.dis led_on_c.bin led_on_c_elf *.o
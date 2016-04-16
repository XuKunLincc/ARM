mmu_test.bin: start.S init.c main.c
	arm-linux-gcc -c -nostdlib -o start.o start.S
	arm-linux-gcc -c -nostdlib -o init.o init.c
	arm-linux-gcc -c -nostdlib -o main.o main.c
	
	arm-linux-ld -Tmmu.lds -o mmu_elf start.o init.o main.o
	arm-linux-objcopy -O binary -S mmu_elf mnu_test.bin
	arm-linux-objdump -D -m arm mmu_elf > mmu_test.dis
	
clean:
	rm -f *.bin *.o *.dis mmu_elf
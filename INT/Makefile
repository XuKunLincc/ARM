objs :=  start.o init.o int.o main.o

int.bin: $(objs)
	arm-linux-ld -Ttext 0x00000000 -o int_elf $^
	arm-linux-objcopy -O binary  -S int_elf $@
	arm-linux-objdump -D -m arm int_elf > int.dis

%.o:%.c
	arm-linux-gcc -nostdlib -c -o $@ $<

%.o:%.s
	arm-linux-gcc -nostdlib -c -o $@ $<

clean:
	rm -f *.bin *.o *.dis int_elf
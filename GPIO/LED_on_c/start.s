@*********************************
@ File start.s
@ 功能:初始化堆栈
@*********************************

.text
.global _start
_start:
			ldr		r0,=0x53000000		@ WATCHDOG寄存器地址
			mov		r1,#0
			str 	r1,[r0]
			
			ldr 	sp,=1024*24			@设置堆栈 由于未初始化SDRAM 所以可用的内存只有4K
			
			bl		main
halt_loop:
			b  		halt_loop
			
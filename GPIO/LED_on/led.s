@*******************************
@	first ARMS led_on
@	by ckl.cc
@*******************************

.text
.global _start
_start:
			LDR		R0,=0x56000010		@R0设置为GPBCON寄存器
			
			MOV 	R1,#0x00000400	
			STR		R1,[R0]
			
			LDR		R0,=0x56000014
			MOV		R1,#0
			
			STR		R1,[R0]
MAIN_LOOP:								@无限循环
			B MAIN_LOOP

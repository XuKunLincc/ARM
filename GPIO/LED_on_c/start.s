@*********************************
@ File start.s
@ ����:��ʼ����ջ
@*********************************

.text
.global _start
_start:
			ldr		r0,=0x53000000		@ WATCHDOG�Ĵ�����ַ
			mov		r1,#0
			str 	r1,[r0]
			
			ldr 	sp,=1024*24			@���ö�ջ ����δ��ʼ��SDRAM ���Կ��õ��ڴ�ֻ��4K
			
			bl		main
halt_loop:
			b  		halt_loop
			
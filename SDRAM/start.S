@*****************************************
@ File�� start.s
@ ���ߣ�Ckl.cc
@ ���ܣ�����SDRAM���������Ƶ�SDRAM�У�Ȼ����SDRAM������
@******************************************

.equ		MEM_CTL_BASE,		0X48000000
.equ		SDRAM_BASE,			0x30000000

.text
.global _start
_start:
	bl	stop_watch_dog
	bl	mem_setup
	bl	copy_code_to_sdram
	ldr pc,=on_sdram

on_sdram:
	ldr sp,=0x34000000
	bl main
halt_loop:
	b halt_loop
	
stop_watch_dog:
	mov r1,		#0x53000000
	mov r2,		#0x0
	str r2,		[r1]
	mov pc,		lr			@lr�����ų���ķ��ص�ַ

mem_setup:
	ldr 	r1, =MEM_CTL_BASE
	adrl	r2, mem_con_reg_addr
	add 	r3, r1, #52
1:
	ldr r4, [r2], #4
	str r4, [r1], #4
	cmp r1, r3
	bne 1b
	mov pc, lr
	
copy_code_to_sdram:
	@ ��Steppingstone��4K����ȫ�����Ƶ�SDRAM��ȥ
    @ Steppingstone��ʼ��ַΪ0x00000000��SDRAM����ʼ��ַΪ0x30000000
    
    mov r1, #0
    ldr r2, =SDRAM_BASE
    mov r3, #4*1024
1:  
    ldr r4, [r1],#4     @ ��Steppingstone��ȡ4�ֽڵ����ݣ�����Դ��ַ��4
    str r4, [r2],#4     @ ����4�ֽڵ����ݸ��Ƶ�SDRAM�У�����Ŀ�ص�ַ��4
    cmp r1, r3          @ �ж��Ƿ���ɣ�Դ��ַ����Steppingstone��δ��ַ��
    bne 1b              @ ��û�и����꣬����
    mov pc,     lr      @ ����
	
	
	
.align 4
mem_con_reg_addr:
	.long   0x22011110      @ BWSCON
    .long   0x00000700      @ BANKCON0
    .long   0x00000700      @ BANKCON1
    .long   0x00000700      @ BANKCON2
    .long   0x00000700      @ BANKCON3  
    .long   0x00000700      @ BANKCON4
    .long   0x00000700      @ BANKCON5
    .long   0x00018005      @ BANKCON6
    .long   0x00018005      @ BANKCON7
    .long   0x008C07A3      @ REFRESH
    .long   0x000000B1      @ BANKSIZE
    .long   0x00000030      @ MRSRB6
    .long   0x00000030      @ MRSRB7
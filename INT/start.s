@***********************************
@ By ckl
@***********************************

.text
.global _start
_start:
	b ResetInit

HandleUndef:
	b HandleUndef

HandleSWI:
	b HandleSWI

HandlePrefetchAbort:
	b HandlePrefetchAbort

HandleDataAbort:
	b HandleDataAbort

HandleNotUsed:
	b HandleNotUsed

	b HandleIRQ

HandleFIQ:
	b HandleFIQ

ResetInit:
	
	ldr sp, =1024*4
	bl disable_watch_dog

	@进入IRQ模式
	msr cpsr_c, #0xd2
	ldr sp, = 1024*3

	@返回管理模式
	msr cpsr_c, #0xd3

	bl init

	msr cpsr_c, #0x53		@开中断
	bl main

halt_loop:
	b halt_loop

HandleIRQ:

	sub lr, lr, #4					@设置返回地址
	stmdb	sp!,	{r0-r12, lr}	

	bl ini_service					@跳转中至中断处理程序

inT_return:
	ldmia	sp!,	{r0-r12, pc}^

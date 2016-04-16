@*************************************
@ File: start.s
@ By: ckl.cc
@ 功能： MMU初始化，建立页表
@*************************************

.text
.global _start
_start:
	ldr sp,=1024*4			@设置堆栈
	bl	stop_watch_dog		@关闭看门狗
	bl	memsetup			@设置控制寄存器
	bl	copy_code_to_sdram	@复制代码至SDRAM
	bl	create_page_table	@创建页表
	bl	mmu_init			@初始化MMU
	ldr	sp,=0xB4000000		@设置堆栈
	ldr pc,=main			@跳向main函数

halt_loop:
	b halt_loop
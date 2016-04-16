@*************************************
@ File: start.s
@ By: ckl.cc
@ ���ܣ� MMU��ʼ��������ҳ��
@*************************************

.text
.global _start
_start:
	ldr sp,=1024*4			@���ö�ջ
	bl	stop_watch_dog		@�رտ��Ź�
	bl	memsetup			@���ÿ��ƼĴ���
	bl	copy_code_to_sdram	@���ƴ�����SDRAM
	bl	create_page_table	@����ҳ��
	bl	mmu_init			@��ʼ��MMU
	ldr	sp,=0xB4000000		@���ö�ջ
	ldr pc,=main			@����main����

halt_loop:
	b halt_loop
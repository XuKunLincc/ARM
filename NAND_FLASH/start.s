@by ckl

.text
.global _start
_start:
	ldr 	sp,=1024*4
	bl 		disable_watch_dog
	bl 		sdram_init
	bl 		nand_init

	ldr 	r0, =0x30000000
	mov		r1, #4096
	mov 	r2, #2048
	bl		nand_read

	ldr     sp, =0x34000000
    ldr     lr, =halt_loop
    ldr     pc, =main 

halt_loop:
	b 		halt_loop

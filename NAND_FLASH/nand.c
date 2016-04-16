#include "nand.h"

static S3C2440_NAND *s3c2440_nand =  (S3C2440_NAND *)0x4e000000;

static void nand_reset(){
	nand_select_chip();
	nand_write_commd(COMMD_RESET);
	nand_wait_idle();
	nand_unselect_chip();
}

static void nand_write_commd(unsigned int cmd){
	// 由于是大端模式  所以我们必须要使用以下的代码进行获取 NFCMD的低八位
	// 否则会寻址到 NFCMD的高八位
	volatile unsigned char *p = (volatile unsigned char *) &s3c2440_nand->NFCMD;
	*p = cmd;
}

static void nand_write_addr(unsigned int addr){

	unsigned int col, page;
	int i;
	PHY_ADDR_8 *p = (PHY_ADDR_8 *) &s3c2440_nand->NFADDR;


	col = addr & 2047;
	page =  addr / 2048;

	// 发送页内寻址
	*p = col & 0xff;
	for(i = 0; i < 10; i++);
	*p = (col >> 8) & 0x0f;
	for(i = 0; i < 10; i++);

	// 发送页号
	*p = page & 0xff;
	for(i = 0; i < 10; i++);
	*p = (page >> 8) & 0xff;
	for(i = 0; i < 10; i++);
	*p = (page >> 16) & 0x03;	// 这里的0X03只是兼容了 512M的 Nand Flash
	for(i = 0; i < 10; i++);
}

// 我们使用的是8位Nand Flash 字节访问模式 所以返回的是 unsigned char
static unsigned char nand_read_data(){
	PHY_ADDR_8 *p = (PHY_ADDR_8 *) &s3c2440_nand->NFDATA;
	return *p;
}

static void nand_select_chip(){
	int i;
	s3c2440_nand->NFCONT &= ~(1<<1);
	for(i = 0; i<10;i++);
}

static void nand_unselect_chip(){
	int i;
	s3c2440_nand->NFCONT |= (1<<1);
	for(i = 0; i<10;i++);
}	

static void nand_wait_idle(){
	int i;
	while(!(s3c2440_nand->NFSTAT & 1))
		for(i = 0; i < 10; i++);
}

void nand_init(){
	// 设置时序
	s3c2440_nand->NFCONF = (TACLS << 12) | (TWRPH0 << 8) | (TWRPH1 << 4);
	s3c2440_nand->NFCONT = (1 << 4) | (1 << 1) | (1 << 0);
	nand_reset();
}

void nand_read(unsigned char *buf, unsigned int start_addr, unsigned int size){

	int i, j;
	// 检测是否页对齐 没有对齐便退出
	if((start_addr & 2047) || (size & 2047))
		return;

	nand_select_chip();

	for(i = start_addr; i < (start_addr + size); ){

		nand_write_commd(COMMD_READ_START);
		nand_write_addr(i);
		nand_write_commd(COMMD_READ_GO);
		nand_wait_idle();

		for(j = 0; j < 2048; j++){
			*buf = nand_read_data();
			buf++;
			i++;
		}
	}
	nand_unselect_chip();
}

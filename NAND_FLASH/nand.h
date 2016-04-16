#ifndef _NAND_H
#define _NAND_H

#define PHY_ADDR_32                volatile unsigned int
#define PHY_ADDR_8                 volatile unsigned char
#define COMMD_RESET 			0XFF
#define COMMD_READ_START 		0X00
#define COMMD_READ_GO	 		0x30
#define COMMD_WRITE_PAGE_START 	0X80
#define COMMD_WRITE_PAGE_GO 	0X10
#define COMMD_READ_STATUS		0x70

#define TACLS 0
#define TWRPH0 3
#define TWRPH1 0

typedef unsigned int S3C24X0_REG32;

// 定义S3C2440 Nand Flash 相关寄存器
typedef struct {
    S3C24X0_REG32   NFCONF;
    S3C24X0_REG32   NFCONT;
    S3C24X0_REG32   NFCMD;
    S3C24X0_REG32   NFADDR;
    S3C24X0_REG32   NFDATA;
    S3C24X0_REG32   NFMECCD0;
    S3C24X0_REG32   NFMECCD1;
    S3C24X0_REG32   NFSECCD;
    S3C24X0_REG32   NFSTAT;
    S3C24X0_REG32   NFESTAT0;
    S3C24X0_REG32   NFESTAT1;
    S3C24X0_REG32   NFMECC0;
    S3C24X0_REG32   NFMECC1;
    S3C24X0_REG32   NFSECC;
    S3C24X0_REG32   NFSBLK;
    S3C24X0_REG32   NFEBLK;
} S3C2440_NAND;

static void nand_reset();
static void nand_write_commd(unsigned int);
static void nand_write_addr(unsigned int);
static void nand_select_chip();
static void nand_unselect_chip();
static void nand_wait_idle();
static unsigned char nand_read_data();

void nand_init();
void nand_read(unsigned char *buf, S3C24X0_REG32 start, S3C24X0_REG32 length);	

#endif
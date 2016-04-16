#ifndef	_S3C2440_H
#define _S3C2440_H

#define WTCON              (*(volatile unsigned long *)0x53000000)
#define GPBCON             (*(volatile unsigned long *)0x56000010)
#define GPBDAT            (*(volatile unsigned long *)0x56000014)
#define GPGCON             (*(volatile unsigned long *)0x56000060)

#define INTMSK             (*(volatile unsigned long *)0X4A000008)
#define INTSUBMSK          (*(volatile unsigned long *)0X4A00001C)
#define INTOFFSET          (*(volatile unsigned long *)0x4A000014)
#define INTPND             (*(volatile unsigned long *)0X4A000010)
#define EINTPND            (*(volatile unsigned long *)0x560000A8)
#define EINTMASK	 	   (*(volatile unsigned long *)0x560000A4)
#define SRCPND  		   (*(volatile unsigned long *)0X4A000000)



#endif
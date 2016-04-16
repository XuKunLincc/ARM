#include "s3c2440.h"

void disable_watch_dog();
static void led_init();
static void int_init();
static void key_init();
void init();

void disable_watch_dog(){
	WTCON = 0X00;
}

/**
*   初始化函数 初始化LED 初始化 int
**/
void init(){

    led_init();         // 初始化LED
    key_init();         // 初始化按键
    int_init();         // 初始化中断相关寄存器

}

static void led_init(){

    GPBCON = 0x00000400;
    GPBDAT = 0xffffffff;

}

static void key_init(){

    GPGCON = 2;        // key1 为中断8 

}

static void int_init(){

    INTMSK &= ~(1 << 5);        // 开中断
    EINTMASK &= ~(1 << 8);      // 开中断

}


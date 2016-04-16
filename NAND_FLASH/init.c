#define WTCON (*(volatile unsigned long *)0x53000000)
#define MEM_CTL_BASE 0x48000000

void disable_watch_dog(){
	WTCON = 0X00;
}

void sdram_init(){
	int i = 0;
	volatile unsigned long* p = (volatile unsigned long*) MEM_CTL_BASE;
	
	unsigned long  const  mem_cfg_val[]={   0x22011110,     //BWSCON
                                            0x00000700,     //BANKCON0
                                            0x00000700,     //BANKCON1
                                            0x00000700,     //BANKCON2
                                            0x00000700,     //BANKCON3  
                                            0x00000700,     //BANKCON4
                                            0x00000700,     //BANKCON5
                                            0x00018005,     //BANKCON6
                                            0x00018005,     //BANKCON7
                                            0x008C07A3,     //REFRESH
                                            0x000000B1,     //BANKSIZE
                                            0x00000030,     //MRSRB6
                                            0x00000030,     //MRSRB7
                                    };
	for(; i < 13; i++)
		p[i] = mem_cfg_val[i];
}
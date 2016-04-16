#define GPBCON (*(volatile unsigned long*) 0xA0000010)
#define GPBDAT (*(volatile unsigned long*) 0xA0000014)

int main(){

	GPBCON &= ~(3 << 12);
	GPBCON |= (1 << 12);
	GPBDAT &= ~(1 << 6);
	
	//GPBCON = 0x00000400;
	//GPBDAT = 0;
	return 0;
}
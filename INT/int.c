#include "s3c2440.h"
void ini_service();

void ini_service(){

	if(INTOFFSET == 5){
		if(EINTPND & (1 << 8))
			GPBDAT = 0;
	}else{
		return;
	}

	// 清除中断标志
	EINTPND |= (1 << 8);
	SRCPND 	|= (1 << 5);
	INTPND  |= (1 << 5);
	return;
}


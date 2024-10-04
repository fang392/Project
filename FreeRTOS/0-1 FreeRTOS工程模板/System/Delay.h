#ifndef __DELAY_H_
#define __DELAY_H_ 			   
#include "sys.h"  

	 
void Delay_init(void);
void Delay_ms(uint32_t nms);
void Delay_us(uint32_t nus);
void Delay_xms(uint32_t nms);
void delay_ms(uint32_t xms);	



#endif

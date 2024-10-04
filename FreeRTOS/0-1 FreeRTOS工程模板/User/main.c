#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Serial.h"
#include "Delay.h"
#include "FreeRTOS_Demo.h"
#include "Key.h"

 
int main(void)
{

	
	//LED、Key、Serial初始化
	LED_Init();
	Key_Init();
	Serial_Init();
	
	
	freertos_demo();
	
		
}
 
 
 
 
 

 

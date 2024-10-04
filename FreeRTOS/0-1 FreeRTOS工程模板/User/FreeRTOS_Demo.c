#include "stm32f10x.h"                  // Device header
#include "freertos.h"
#include "task.h"
#include "LED.h"
#include "Serial.h"
#include "Delay.h"
#include "Key.h"


/******************************************************************************************************/
/*FreeRTOS配置*/
 
/* START_TASK 任务配置
 * 包括：任务优先级、任务堆栈大小、任务句柄、创建任务
 */
 
#define START_TASK_PRIO			1		//任务优先级
#define START_TASK_STACK_SIZE	128		//任务堆栈大小
TaskHandle_t Start_Task_Handle;			//任务句柄
void start_task(void *pvParameters);	//创建任务
 
// TASK1 任务配置
#define TASK1_PRIO			2		
#define TASK1_STACK_SIZE	128		
TaskHandle_t Task1_Handle;			
void task1(void *pvParameters);		


	
/******************************************************************************************************/



void freertos_demo(void)
{

	
	//创建开始任务Start_Task
	xTaskCreate((TaskFunction_t		)	start_task,					//任务函数
				(const char*        )	"start_task",				//任务函数名称
				(uint16_t			)	START_TASK_STACK_SIZE,		//任务堆栈大小
				(void*				)	NULL,						//传递给任务函数的参数	
				(UBaseType_t		)	START_TASK_PRIO,			//任务优先级
				(TaskHandle_t*		)	&Start_Task_Handle);		//任务句柄
	
	
	//开启任务调度
	vTaskStartScheduler();	
}



//开始任务：用来创建其他的任务
void start_task(void *pvParameters)
{
	//进入临界区
	taskENTER_CRITICAL();
	
	//创建task1、task2、task3任务
	xTaskCreate((TaskFunction_t		)	task1,					//任务函数
				(const char*        )	"task1",				//任务函数名称
				(uint16_t			)	TASK1_STACK_SIZE,		//任务堆栈大小
				(void*				)	NULL,					//传递给任务函数的参数	
				(UBaseType_t		)	TASK1_PRIO,				//任务优先级
				(TaskHandle_t*		)	&Task1_Handle);			//任务句柄
				
			
				
	//任务删除
	vTaskDelete(NULL);	//参数填StartTask_Handler 或 NULL 代表删除Start_Task任务本身；等价于vTaskDelete(NULL);			
	//退出临界区
	taskEXIT_CRITICAL();
}

//任务1：
void task1(void *pvParameters)
{

	while(1)
	{
		LED1_Turn();
		
		vTaskDelay(100);
	}		
}


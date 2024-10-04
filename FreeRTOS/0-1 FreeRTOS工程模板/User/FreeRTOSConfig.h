/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "sys.h"
#include "Serial.h"
//针对不同的编译器调用不同的stdint.h文件
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

//断言
#define vAssertCalled(char,int) Serial_Printf("Error:%s,%d\r\n",char,int)
#define configASSERT(x) if((x)==0) vAssertCalled(__FILE__,__LINE__)

/***************************************************************************************************************/
/*                                        FreeRTOS基础配置配置选项                                              */
/***************************************************************************************************************/
#define configUSE_PREEMPTION					1                       //1使用抢占式内核，0使用协程
#define configUSE_TIME_SLICING					1						//1使能时间片调度(默认式使能的)
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1                       //1启用特殊方法来选择下一个要运行的任务
                                                                        //一般是硬件计算前导零指令，如果所使用的
                                                                        //MCU没有这些硬件指令的话此宏应该设置为0！
#define configUSE_TICKLESS_IDLE					0                       //1启用低功耗tickless模式
#define configUSE_QUEUE_SETS					1                       //为1时启用队列
#define configCPU_CLOCK_HZ						(SystemCoreClock)       //CPU频率
#define configTICK_RATE_HZ						(1000)                  //时钟节拍频率，这里设置为1000，周期就是1ms
#define configMAX_PRIORITIES					(32)                    //可使用的最大优先级
#define configMINIMAL_STACK_SIZE				((unsigned short)128)   //空闲任务使用的堆栈大小
#define configMAX_TASK_NAME_LEN					(16)                    //任务名字字符串长度

#define configUSE_16_BIT_TICKS					0                       //系统节拍计数器变量数据类型，
                                                                        //1表示为16位无符号整形，0表示为32位无符号整形
#define configIDLE_SHOULD_YIELD					1                       //为1时空闲任务放弃CPU使用权给其他同优先级的用户任务
#define configUSE_TASK_NOTIFICATIONS            1                       //为1时开启任务通知功能，默认开启
#define configUSE_MUTEXES						1                       //为1时使用互斥信号量
#define configQUEUE_REGISTRY_SIZE				8                       //不为0时表示启用队列记录，具体的值是可以
                                                                        //记录的队列和信号量最大数目。
#define configCHECK_FOR_STACK_OVERFLOW			0                       //大于0时启用堆栈溢出检测功能，如果使用此功能
                                                                        //用户必须提供一个栈溢出钩子函数，如果使用的话
                                                                        //此值可以为1或者2，因为有两种栈溢出检测方法。
#define configUSE_RECURSIVE_MUTEXES				1                       //为1时使用递归互斥信号量
#define configUSE_MALLOC_FAILED_HOOK			0                       //1使用内存申请失败钩子函数
#define configUSE_APPLICATION_TASK_TAG			0                       
#define configUSE_COUNTING_SEMAPHORES			1                       //为1时使用计数信号量

/***************************************************************************************************************/
/*                                FreeRTOS与内存申请有关配置选项                                                */
/***************************************************************************************************************/
#define configSUPPORT_STATIC_ALLOCATION			0						//支持静态内存申请
#define configSUPPORT_DYNAMIC_ALLOCATION        1                       //支持动态内存申请
#define configTOTAL_HEAP_SIZE					((size_t)(17*1024))     //系统所有总的堆大小

/***************************************************************************************************************/
/*                                FreeRTOS与钩子函数有关的配置选项                                              */
/***************************************************************************************************************/
#define configUSE_IDLE_HOOK						0                       //1，使用空闲钩子；0，不使用
#define configUSE_TICK_HOOK						0                       //1，使用时间片钩子；0，不使用

/***************************************************************************************************************/
/*                                FreeRTOS与运行时间和任务状态收集有关的配置选项                                 */
/***************************************************************************************************************/
#define configGENERATE_RUN_TIME_STATS	        0                       //为1时启用运行时间统计功能
#define configUSE_TRACE_FACILITY				1                       //为1启用可视化跟踪调试
#define configUSE_STATS_FORMATTING_FUNCTIONS	1                       //与宏configUSE_TRACE_FACILITY同时为1时会编译下面3个函数
                                                                        //prvWriteNameToBuffer(),vTaskList(),
                                                                        //vTaskGetRunTimeStats()
                                                                        
/***************************************************************************************************************/
/*                                FreeRTOS与协程有关的配置选项                                                  */
/***************************************************************************************************************/
#define configUSE_CO_ROUTINES 			        0                       //为1时启用协程，启用协程以后必须添加文件croutine.c
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )                   //协程的有效优先级数目

/***************************************************************************************************************/
/*                                FreeRTOS与软件定时器有关的配置选项                                            */
/***************************************************************************************************************/
#define configUSE_TIMERS				        1                               //为1时启用软件定时器
#define configTIMER_TASK_PRIORITY		        (configMAX_PRIORITIES-1)        //软件定时器优先级
#define configTIMER_QUEUE_LENGTH		        5                               //软件定时器队列长度
#define configTIMER_TASK_STACK_DEPTH	        (configMINIMAL_STACK_SIZE*2)    //软件定时器任务堆栈大小

/***************************************************************************************************************/
/*                                FreeRTOS可选函数配置选项                                                      */
/***************************************************************************************************************/
#define INCLUDE_vTaskPrioritySet                        1                       /* 设置任务优先级 */
#define INCLUDE_uxTaskPriorityGet                       1                       /* 获取任务优先级 */
#define INCLUDE_vTaskDelete                             1                       /* 删除任务 */
#define INCLUDE_vTaskSuspend                            1                       /* 挂起任务 */
#define INCLUDE_xResumeFromISR                          1                       /* 恢复在中断中挂起的任务 */
#define INCLUDE_vTaskDelayUntil                         1                       /* 任务绝对延时 */
#define INCLUDE_vTaskDelay                              1                       /* 任务延时 */
#define INCLUDE_xTaskGetSchedulerState                  1                       /* 获取任务调度器状态 */
#define INCLUDE_xTaskGetCurrentTaskHandle               1                       /* 获取当前任务的任务句柄 */
#define INCLUDE_uxTaskGetStackHighWaterMark             1                       /* 获取任务堆栈历史剩余最小值 */
#define INCLUDE_xTaskGetIdleTaskHandle                  1                       /* 获取空闲任务的任务句柄 */
#define INCLUDE_eTaskGetState                           1                       /* 获取任务状态 */
#define INCLUDE_xEventGroupSetBitFromISR                1                       /* 在中断中设置事件标志位 */
#define INCLUDE_xTimerPendFunctionCall                  1                       /* 将函数的执行挂到定时器服务任务 */
#define INCLUDE_xTaskAbortDelay                         1                       /* 中断任务延时 */
#define INCLUDE_xTaskGetHandle                          1                       /* 通过任务名获取任务句柄 */
#define INCLUDE_xTaskResumeFromISR                      1                       /* 恢复在中断中挂起的任务 */

/***************************************************************************************************************/
/*                                FreeRTOS与中断有关的配置选项                                                  */
/***************************************************************************************************************/
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4                  
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15                      //中断最低优先级
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5                       //系统可管理的最高中断优先级
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/***************************************************************************************************************/
/*                                FreeRTOS与中断服务函数有关的配置选项                                          */
/***************************************************************************************************************/
#define xPortPendSVHandler 	PendSV_Handler
#define vPortSVCHandler 	SVC_Handler


#endif /* FREERTOS_CONFIG_H */







/* 以下是最新的RTOS源码 */
///*
// * FreeRTOS V202212.01
// * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
// *
// * Permission is hereby granted, free of charge, to any person obtaining a copy of
// * this software and associated documentation files (the "Software"), to deal in
// * the Software without restriction, including without limitation the rights to
// * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// * the Software, and to permit persons to whom the Software is furnished to do so,
// * subject to the following conditions:
// *
// * The above copyright notice and this permission notice shall be included in all
// * copies or substantial portions of the Software.
// *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// *
// * https://www.FreeRTOS.org
// * https://github.com/FreeRTOS
// *
// */

//#ifndef FREERTOS_CONFIG_H
//#define FREERTOS_CONFIG_H

///*-----------------------------------------------------------
// * Application specific definitions.
// *
// * These definitions should be adjusted for your particular hardware and
// * application requirements.
// *
// * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
// * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
// *
// * See http://www.freertos.org/a00110.html
// *----------------------------------------------------------*/
// 


//#define configUSE_PREEMPTION		1				//如果希望使用抢占式 RTOS 调度器，请将其设置为 1；如果希望使用协同式 RTOS 调度器，请将其设置为 0。
//#define configUSE_IDLE_HOOK			0				//如果希望使用空闲钩子，请将其设置为 1；如果希望忽略空闲钩子，请将其设置为 0。
//#define configUSE_TICK_HOOK			0				//如果希望使用滴答钩子，请将其设置为 1；如果希望忽略滴答钩子，请将其设置为 0。

///* 默认情况下，ARM Cortex-M 移植使用 Cortex-M SysTick 定时器生成 RTOS 滴答中断。
//大多数 Cortex-M MCU 以与其本身相同的频率运行 SysTick 定时器。在这种情况下， 无需 configSYSTICK_CLOCK_HZ，应让其保持未定义状态。
//如果 SysTick 定时器的时钟频率与 MCU 核心的频率不同，则应将 configCPU_CLOCK_HZ设置为 MCU 时钟频率（正常情况下），
//并将configSYSTICK_CLOCK_HZ设置为 SysTick 时钟频率。 */
//#define configCPU_CLOCK_HZ			( ( unsigned long ) 72000000 )		

///*RTOS 滴答中断的频率。
//滴答中断用于测量时间。因此，滴答频率越高，测量的时间越精确 。但是，滴答频率高也意味着 RTOS 内核将占用更多的 CPU 时间，因此效率会降低。
//RTOS 演示应用程序使用的滴答频率均为 1000Hz。
//这是为了测试 RTOS 内核， 比通常所需的频率要高。多项任务可以具有相同的优先级。
//RTOS 调度器 可在每个 RTOS 滴答期间在具有相同优先级的任务之间切换，以共享处理器时间。因此，滴答频率高也会 减少分配给每项任务的“时间切片”。*/
//#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )

///*应用程序任务可用的优先级数量。多项任务（数量不限） 可以具有相同的优先级。协程的优先级是独立设置的，请参阅 configMAX_CO_ROUTINE_PRIORITIES。
//每个可用优先级都会占用 RTOS 内核中的一些 RAM，因此不应将此值设置得高于应用程序 实际需要的数量。
//如果 configUSE_PORT_OPTIMISED_TASK_SELECTION 设置为 1，则最大允许值将受到限制。*/
//#define configMAX_PRIORITIES		( 5 )

///*空闲任务使用的堆栈大小。通常，此值不应小于 FreeRTOSConfig.h 文件中设置的值， 该文件随所用移植的演示应用程序一起提供。
//与 xTaskCreate() 和 xTaskCreateStatic() 函数的堆栈大小参数一样， 此堆栈大小以字为单位，而不是字节。
//如果堆栈上的每个元素都是 32 位， 则堆栈大小为 100 意味着 400 字节（每个 32 位堆栈元素占用 4 个字节）*/
//#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 128 )

///*FreeRTOS 堆中可用的 RAM 总量。
//仅当 configSUPPORT_DYNAMIC_ALLOCATION 设置为 1， 并且应用程序使用 FreeRTOS 源代码下载内容中提供的一种示例内存分配方案时，才会使用此值。 
//请参阅内存配置部分，了解更多详情。
//configAPPLICATION_ALLOCATED_HEAP
//默认情况下，FreeRTOS 堆由 FreeRTOS 声明， 并由链接器放置在内存中。如果将 configAPPLICATION_ALLOCATED_HEAP设置为 1， 应用程序编写者可声明堆，
//这意味着应用程序编写者可以将堆放置在内存中的任意位置。
//如果使用 heap_1.c、heap_2.c 或 heap_4.c，并且 configAPPLICATION_ALLOCATED_HEAP设置为 1，则应用程序编写者必须提供一个 uint8_t数组，
//其名称和维度必须与下面所示完全一致。该数组将用作 FreeRTOS 堆。 如何将数组放置在特定内存位置取决于所使用的编译器， 请参阅编译器文档。*/
//#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 17 * 1024 ) )
//#define configMAX_TASK_NAME_LEN		( 16 )		//创建任务时，赋予该任务的描述性名称的最大允许长度。 长度以字符数指定，包括 NULL 终止字节。
//#define configUSE_TRACE_FACILITY	0			//如果希望包含其他结构体成员和函数以协助执行可视化和跟踪，请将其设置为 1。

///*所测量时间的单位为“滴答”，此值是指自 RTOS 内核启动以来滴答中断执行的次数。 
//滴答计数保存在类型为 TickType_t的变量中。
//将 configUSE_16_BIT_TICKS定义为 1 会将 TickType_t定义 (typedef) 为无符号的 16 位类型。 
//将 configUSE_16_BIT_TICKS定义为 0 会将 TickType_t定义 (typedef) 为无符号的 32 位类型。
//在 8 位和 16 位架构上使用 16 位类型可显著提高性能，但会将最大可指定的 时间周期限制为 65535 个“滴答”。
//因此，假设滴答频率 为 250Hz，使用 16 位计数器时，任务可以延迟或阻塞的最长时间为 262 秒， 而使用 32 位计数器时为 17179869 秒。*/
//#define configUSE_16_BIT_TICKS		0
//#define configIDLE_SHOULD_YIELD		1		//用于控制处于空闲优先级的任务的行为，仅在以下情况下有效：1.使用抢占式调度器 2.应用程序创建的任务以空闲优先级运行。


///* 将以下定义设置为1以包含API函数，或将定义设置为0以排除API函数。*/

//#define INCLUDE_vTaskPrioritySet		1
//#define INCLUDE_uxTaskPriorityGet		1
//#define INCLUDE_vTaskDelete				1
//#define INCLUDE_vTaskCleanUpResources	0
//#define INCLUDE_vTaskSuspend			1
//#define INCLUDE_vTaskDelayUntil			1
//#define INCLUDE_vTaskDelay				1

///* 这是根据Cortex-M3 NVIC的原始值。取值范围为255(最低)到0(最高)。*/
//#define configKERNEL_INTERRUPT_PRIORITY 		255

///* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY不能设置为0 !!!!
//见http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html。 */
//#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	191 /* equivalent to 0xb0, or priority 11.  相当于0xb0，或者优先级为11。*/


///* 这是根据ST库使用的值，它允许16个优先级值，从0到15。这必须对应于configKERNEL_INTERRUPT_PRIORITY设置。这里15对应于最低的NVIC值255。*/
//#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY	15

///* 添加必须的三个宏 */
//#define vPortSVCHandler 						SVC_Handler
//#define xPortPendSVHandler 					PendSV_Handler
//#define INCLUDE_xTaskGetSchedulerState		1					/* 获取任务调度器状态 */

//#endif /* FREERTOS_CONFIG_H */


#ifndef __FREERTOS_DEMO_H_
#define __FREERTOS_DEMO_H_
#include "stdint.h"

void freertos_demo(void);
void start_task(void *pvParameters);
void task1(void *pvParameters);
void task2(void *pvParameters);
void task3(void *pvParameters);
void ConfigureTimeForRunTimeStats(void);

#endif


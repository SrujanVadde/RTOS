#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>

TimerHandle_t timer_handler;
int count=0;

void Task_1(TimerHandle_t xTimer)
{
    count++;
    printf("Timer off Tasks\n");
    if(count==5)
    {
        xTimerStop(xTimer,0);
    }
}
void app_main()
{
    timer_handler=xTimerCreate("OFF",pdMS_TO_TICKS(2000),pdTRUE,NULL,Task_1);
    xTimerStart(timer_handler,0);
    while(1)
    {
        printf("main task\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

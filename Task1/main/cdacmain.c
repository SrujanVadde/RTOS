#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog;

void Task1(void *pvParameteres)
{
    while(1)
    {
    printf("Task1\n");
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    vTaskDelete(xHandleTaskLog);
}

void app_main()
{
    BaseType_t r;

    r=  xTaskCreate(Task1,"TaskLog",2048,NULL,5,&xHandleTaskLog);

    if(r==pdPASS)
    {
        printf("Hello_world\n");
    }

}

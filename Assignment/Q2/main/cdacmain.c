#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;

void Task1(void *pvParameteres)
{
    int a=0;
    while(1)
    {
    a++;
    printf("Task 1 Value of a is %d\n",a);
    vTaskDelay(500/ portTICK_PERIOD_MS);

    }
}

void app_main()
{
    BaseType_t r;

    r=  xTaskCreate(Task1,"Task1",2048,NULL,5,&xHandleTaskLog1);
        if(r==pdPASS)
    {
        printf("Task 1 created\n");
    }
}

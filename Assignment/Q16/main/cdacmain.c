#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;

void Task1(void *pvParameteres)
{
vTaskDelay(1000/portTICK_PERIOD_MS);
    while(1)
    {
    printf("Task1\n");
    
    }
    vTaskDelete(xHandleTaskLog1);
}
void Task2(void *pv)
{
vTaskDelay(1000/portTICK_PERIOD_MS);
    while(1)
    {
        printf("Task2\n");
        
    }
    vTaskDelete(xHandleTaskLog2);
    

}

void app_main()
{
    BaseType_t r1,r2;

    r1=  xTaskCreate(Task1,"Task1",2048,NULL,3,&xHandleTaskLog1);
    r2=  xTaskCreate(Task2,"Task2",2048,NULL,5,&xHandleTaskLog2);

    if(r1==pdPASS)
    {
        printf("Hello_world\n");
    }

}

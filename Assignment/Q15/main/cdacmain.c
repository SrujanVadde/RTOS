#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;

void Task1(void *pvParameteres)
{
    int a=0;
    while(1)
    {
    printf("Task1\n");
    a++;
    if(a==6)
    {
    printf("Task 1 Suspended\n");
        vTaskSuspend(NULL); 
    }
    vTaskDelay(200/ portTICK_PERIOD_MS);
    }
}
void Task2(void *pv)
{
    int a=0;
    while(1)
    {
        printf("Task 2\n");
        a++;
        if(a==7)
        {
        printf("Task 1 Resumed\n");
           vTaskResume(xHandleTaskLog1);
        }
        vTaskDelay(200/ portTICK_PERIOD_MS);
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

    r=  xTaskCreate(Task2,"Task2",2048,NULL,5,&xHandleTaskLog2);
    if(r==pdPASS)
    {
        printf("Task 2 created\n");
    }




}

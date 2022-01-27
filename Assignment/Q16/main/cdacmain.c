#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;

void Task1(void *pvParameteres)
{
vTaskDelay(1000/portTICK_PERIOD_MS);
int a=0;
    while(1)
    {
    printf("Task1\n");
    a++;
    if(a==5)
    {
     printf("Task 1 Priority has been changed\n");
    vTaskPrioritySet(NULL,4);
    vTaskDelay(1000/portTICK_PERIOD_MS);
   
    }
    
    }
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

    r1=  xTaskCreate(Task1,"Task1",2048,NULL,6,&xHandleTaskLog1);
    r2=  xTaskCreate(Task2,"Task2",2048,NULL,5,&xHandleTaskLog2);

    if(r1==pdPASS)
    {
        printf("Task 1 created\n");
    }
        if(r2==pdPASS)
    {
        printf("Task 2 created\n");
    }

}

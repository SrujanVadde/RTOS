#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;
static portMUX_TYPE mux;
uint32_t resource=0;

void Task1(void *pvParameteres)
{
    while(1)
    {
    taskENTER_CRITICAL(&mux);
    resource++;
    taskEXIT_CRITICAL(&mux);
    printf("Value of resource %d\n",resource);
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}
void Task2(void *pv)
{
    int b=0;
    while(1)
    {
        b++;
        printf("Task 2 Value of b is %d \n",b);
        
        vTaskDelay(2000/ portTICK_PERIOD_MS);

        
    }
    

}

void app_main()
{
    vPortCPUInitializeMutex(&mux);
    BaseType_t r;
    

    r=  xTaskCreate(Task1,"Task1",2048,NULL,5,&xHandleTaskLog1);
        if(r==pdPASS)
    {
        printf("Task 1 created\n");
    }

    r=  xTaskCreate(Task2,"Task2",2048,NULL,6,&xHandleTaskLog2);
    if(r==pdPASS)
    {
        printf("Task 2 created\n");
    }
    




}

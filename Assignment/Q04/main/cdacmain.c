#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

TaskHandle_t xHandleTaskLog1,xHandleTaskLog2;

void Task1(void *pvParameteres)
{
    int a=0;
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    while(1)
    {
    a++;
    printf("Task 1 Value of a is %d\n",a);
        

    }
}
void Task2(void *pv)
{
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    int b=0;
    while(1)
    {
        b++;
        printf("Task 2 Value of b is %d \n",b);
        

        
    }
    

}

void app_main()
{
    BaseType_t r;

    r=  xTaskCreate(Task1,"Task1",2048,NULL,10,&xHandleTaskLog1);
        if(r==pdPASS)
    {
        printf("Task 1 created\n");
    }

    r=  xTaskCreate(Task2,"Task2",2048,NULL,20,&xHandleTaskLog2);
    if(r==pdPASS)
    {
        printf("Task 2 created\n");
    }




}

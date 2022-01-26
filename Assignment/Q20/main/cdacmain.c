
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/semphr.h>


SemaphoreHandle_t sem;
TaskHandle_t xHandle_1,xHandle_2;


void task_1(void *pvparameters)
{
    int a=0;
    while(1)
    {
        a++;
        printf("Task 1 value of a is %d\n",a);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        if(a==10)
        {
            xSemaphoreGive(sem);
            vTaskDelay(1000/ portTICK_PERIOD_MS);
            a=0;
        }
        
    }
}
void task_2(void *pvparameters)
{
    while(1)
    {
        xSemaphoreTake(sem,portMAX_DELAY);
        printf("Task 2 \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    sem=xSemaphoreCreateBinary();
    BaseType_t result;
    
    result=xTaskCreate(task_1,"task_1",2048,NULL,5,&xHandle_1);

    if(result==pdPASS)
    {
        printf("Task 1 created\n");
    }
    result=xTaskCreate(task_2,"task_2",2048,NULL,5,&xHandle_2);

    if(result==pdPASS)
    {
        printf("Task 2 created\n");
    }
    xSemaphoreTake(sem,portMAX_DELAY);
}

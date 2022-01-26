
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/semphr.h>


SemaphoreHandle_t sem;
TaskHandle_t xHandle_1,xHandle_2;
int a=0;

void task_1(void *pvparameters)
{

    while(1)
    {
    	xSemaphoreTake(sem,portMAX_DELAY);
        a++;
        printf("Task 1 value of a is %d\n",a);
        xSemaphoreGive(sem);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        
    }
}
void task_2(void *pvparameters)
{
    while(1)
    {
    	xSemaphoreTake(sem,portMAX_DELAY);
        a++;
        printf("Task 2 value of a is %d\n",a);
        xSemaphoreGive(sem);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    sem=xSemaphoreCreateMutex();
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
}

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/queue.h>

QueueHandle_t queue;
TaskHandle_t xHandle_1,xHandle_2;


void Task_1(void *pvparameters)
{
    int send_val=0,a=0;
    while(1)
    {
        send_val++;
        a++;
        printf("The value sent is %d\n",a);
        xQueueSendFromISR(queue,&send_val,portMAX_DELAY);

            vTaskDelay(1000/ portTICK_PERIOD_MS);

        
    }
}
void Task_2(void *pvparameters)
{
    int rece_val=0,a=0;
    while(1)
    {
    
    a++;
        xQueueReceiveFromISR(queue,&rece_val,portMAX_DELAY);
        printf("RECEIVED DATA %d\n",rece_val);
        vTaskDelay(5000/ portTICK_PERIOD_MS);
       
    }
}
void app_main()
{
    queue=xQueueCreate(3,sizeof(int));
    BaseType_t result;
    
    result=xTaskCreate(Task_1,"Task_1",2048,NULL,5,&xHandle_1);

    if(result==pdPASS)
    {
        printf("Task 1 created\n");
    }
    result=xTaskCreate(Task_2,"Task_2",2048,NULL,5,&xHandle_2);

    if(result==pdPASS)
    {
        printf("Task 2 created\n");
    }
}

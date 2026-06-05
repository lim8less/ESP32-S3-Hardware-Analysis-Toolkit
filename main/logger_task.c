#include "logger.h"
#include "ring_buffer.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void logger_task(void *arg)
{
    capture_event_t event;

    while(1)
    {
        if(ring_buffer_pop(&event) == 0)
        {
            logger_print_event(&event);
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
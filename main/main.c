#include "uart_sniffer.h"
#include "uart_framer.h"
#include "ring_buffer.h"
#include "logger_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("\n=== APP_MAIN STARTED ===\n");
    ring_buffer_init();

    uart_framer_init();

    uart_sniffer_init();

    xTaskCreate(
        logger_task,
        "logger_task",
        4096,
        NULL,
        5,
        NULL
    );

    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
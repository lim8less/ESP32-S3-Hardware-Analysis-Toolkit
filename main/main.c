#include "uart_sniffer.h"
#include "uart_framer.h"
#include "ring_buffer.h"

#include "stats.h"
#include "stats_task.h"

#include "logger_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    ring_buffer_init();

    stats_init();

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

    xTaskCreate(
        stats_task,
        "stats_task",
        4096,
        NULL,
        4,
        NULL
    );

    while(1)
    {
        vTaskDelay(
            pdMS_TO_TICKS(1000)
        );
    }
}
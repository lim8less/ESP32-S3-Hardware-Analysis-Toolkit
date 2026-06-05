#include "uart_sniffer.h"

#include "config.h"
#include "capture_types.h"
#include "timestamp.h"
#include "ring_buffer.h"
#include "uart_framer.h"
#include "driver/uart.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include <string.h>

static void uart_capture_task(void *arg)
{   
    printf("UART TASK CREATED\n");
    uint8_t buffer[TOOLKIT_BUFFER_SIZE];

    while(1)
    {
        int len = uart_read_bytes(
            TOOLKIT_UART_PORT,
            buffer,
            TOOLKIT_BUFFER_SIZE,
            pdMS_TO_TICKS(TOOLKIT_TIMEOUT_MS)
        );

        if(len > 0)
        {
            uart_framer_feed(
                buffer,
                len
            );
        }
    }
}

void uart_sniffer_init(void)
{   
    printf("UART SNIFFER INIT\n");
    uart_config_t uart_config = {
        .baud_rate = TOOLKIT_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    uart_driver_install(
        TOOLKIT_UART_PORT,
        TOOLKIT_BUFFER_SIZE * 2,
        0,
        0,
        NULL,
        0
    );

    uart_param_config(
        TOOLKIT_UART_PORT,
        &uart_config
    );

    uart_set_pin(
        TOOLKIT_UART_PORT,
        TOOLKIT_TX_PIN,
        TOOLKIT_RX_PIN,
        UART_PIN_NO_CHANGE,
        UART_PIN_NO_CHANGE
    );

    gpio_set_pull_mode(
        TOOLKIT_RX_PIN,
        GPIO_PULLUP_ONLY
    );
    xTaskCreate(
        uart_capture_task,
        "uart_capture",
        4096,
        NULL,
        5,
        NULL
    );
}

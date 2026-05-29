#pragma once

#include "driver/uart.h"

#define TOOLKIT_UART_PORT      UART_NUM_1

#define TOOLKIT_RX_PIN         18
#define TOOLKIT_TX_PIN         UART_PIN_NO_CHANGE

#define TOOLKIT_BAUD_RATE      9600

#define TOOLKIT_BUFFER_SIZE    128

#define TOOLKIT_TIMEOUT_MS     100
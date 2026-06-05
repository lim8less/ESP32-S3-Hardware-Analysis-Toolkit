#pragma once

#include <stdint.h>

typedef enum
{
    EVENT_UART = 0,
    EVENT_I2C,
    EVENT_SPI

} event_type_t;

typedef struct
{
    uint64_t timestamp_us;

    event_type_t type;

    uint16_t length;

    uint8_t data[256];

} capture_event_t;
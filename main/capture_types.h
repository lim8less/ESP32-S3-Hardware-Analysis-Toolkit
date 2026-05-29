#pragma once

#include <stdint.h>

typedef struct
{
    uint64_t timestamp_us;

    uint16_t length;

    uint8_t data[256];

} capture_event_t;
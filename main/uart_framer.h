#pragma once

#include <stdint.h>

void uart_framer_init(void);

void uart_framer_feed(
    uint8_t *data,
    int len
);
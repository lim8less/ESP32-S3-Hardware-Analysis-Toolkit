#pragma once

#include "capture_types.h"

typedef enum
{
    TRIGGER_NONE = 0,

    TRIGGER_BYTE,

    TRIGGER_STRING,

    TRIGGER_LENGTH

} trigger_type_t;

void trigger_init(void);

void trigger_set_none(void);

void trigger_set_byte(uint8_t value);

void trigger_set_string(
    const char *str
);

void trigger_set_length(
    uint16_t min_length
);

int trigger_match(
    const capture_event_t *event
);
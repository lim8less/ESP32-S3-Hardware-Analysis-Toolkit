#include "trigger.h"

#include <string.h>

static trigger_type_t current_trigger =
    TRIGGER_NONE;

static uint8_t trigger_byte = 0;

static char trigger_string[64];

static uint16_t trigger_length = 0;

void trigger_init(void)
{
    current_trigger =
        TRIGGER_NONE;

    memset(
        trigger_string,
        0,
        sizeof(trigger_string)
    );
}

void trigger_set_none(void)
{
    current_trigger =
        TRIGGER_NONE;
}

void trigger_set_byte(
    uint8_t value
)
{
    current_trigger =
        TRIGGER_BYTE;

    trigger_byte =
        value;
}

void trigger_set_string(
    const char *str
)
{
    current_trigger =
        TRIGGER_STRING;

    strncpy(
        trigger_string,
        str,
        sizeof(trigger_string) - 1
    );
}

void trigger_set_length(
    uint16_t min_length
)
{
    current_trigger =
        TRIGGER_LENGTH;

    trigger_length =
        min_length;
}

int trigger_match(
    const capture_event_t *event
)
{
    switch(current_trigger)
    {
        case TRIGGER_NONE:
            return 1;

        case TRIGGER_BYTE:

            for(
                int i = 0;
                i < event->length;
                i++
            )
            {
                if(
                    event->data[i]
                    ==
                    trigger_byte
                )
                {
                    return 1;
                }
            }

            return 0;

        case TRIGGER_STRING:

            if(
                strstr(
                    (char *)event->data,
                    trigger_string
                )
            )
            {
                return 1;
            }

            return 0;

        case TRIGGER_LENGTH:

            return (
                event->length
                >=
                trigger_length
            );

        default:
            return 1;
    }
}
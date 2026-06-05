#include "uart_framer.h"

#include "capture_types.h"
#include "ring_buffer.h"
#include "timestamp.h"

#include <string.h>

#define FRAME_BUFFER_SIZE 256

static uint8_t frame_buffer[
    FRAME_BUFFER_SIZE
];

static uint16_t frame_length = 0;

void uart_framer_init(void)
{
    frame_length = 0;

    memset(
        frame_buffer,
        0,
        sizeof(frame_buffer)
    );
}

static void push_frame(void)
{
    if(frame_length == 0)
    {
        return;
    }

    capture_event_t event;

    memset(
        &event,
        0,
        sizeof(event)
    );

    event.timestamp_us =
        timestamp_now_us();

    event.type = EVENT_UART;

    event.length = frame_length;

    memcpy(
        event.data,
        frame_buffer,
        frame_length
    );

    ring_buffer_push(&event);

    frame_length = 0;
}

void uart_framer_feed(
    uint8_t *data,
    int len
)
{
    for(int i = 0; i < len; i++)
    {
        uint8_t byte = data[i];

        if(frame_length <
           FRAME_BUFFER_SIZE)
        {
            frame_buffer[
                frame_length++
            ] = byte;
        }

        if(byte == '\n')
        {
            push_frame();
        }
    }
}
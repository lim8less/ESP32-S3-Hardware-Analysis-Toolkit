#include "ring_buffer.h"

#include <string.h>

static capture_event_t buffer[RING_BUFFER_SIZE];

static volatile int head = 0;
static volatile int tail = 0;
static volatile int count = 0;

void ring_buffer_init(void)
{
    head = 0;
    tail = 0;
    count = 0;

    memset(buffer, 0, sizeof(buffer));
}

int ring_buffer_is_empty(void)
{
    return (count == 0);
}

int ring_buffer_is_full(void)
{
    return (count == RING_BUFFER_SIZE);
}

int ring_buffer_count(void)
{
    return count;
}

int ring_buffer_push(capture_event_t *event)
{
    if(ring_buffer_is_full())
    {
        return -1;
    }

    buffer[head] = *event;

    head++;

    if(head >= RING_BUFFER_SIZE)
    {
        head = 0;
    }

    count++;

    return 0;
}

int ring_buffer_pop(capture_event_t *event)
{
    if(ring_buffer_is_empty())
    {
        return -1;
    }

    *event = buffer[tail];

    tail++;

    if(tail >= RING_BUFFER_SIZE)
    {
        tail = 0;
    }

    count--;

    return 0;
}
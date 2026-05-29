#include "ring_buffer.h"
#include "logger.h"

void ring_buffer_push(capture_event_t *event)
{
    logger_print_event(event);
}
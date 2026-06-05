#pragma once

#include "capture_types.h"

#define RING_BUFFER_SIZE 32

void ring_buffer_init(void);

int ring_buffer_push(capture_event_t *event);

int ring_buffer_pop(capture_event_t *event);

int ring_buffer_is_empty(void);

int ring_buffer_is_full(void);

int ring_buffer_count(void);
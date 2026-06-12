#pragma once

#include <stdint.h>

typedef struct
{
    uint32_t frames_captured;
    uint32_t bytes_captured;
    uint32_t dropped_frames;
} toolkit_stats_t;

void stats_init(void);

void stats_frame_received(uint16_t bytes);

void stats_frame_dropped(void);

toolkit_stats_t stats_get(void);
#include "stats.h"

static toolkit_stats_t stats;

void stats_init(void)
{
    stats.frames_captured = 0;
    stats.bytes_captured = 0;
    stats.dropped_frames = 0;
}

void stats_frame_received(uint16_t bytes)
{
    stats.frames_captured++;
    stats.bytes_captured += bytes;
}

void stats_frame_dropped(void)
{
    stats.dropped_frames++;
}

toolkit_stats_t stats_get(void)
{
    return stats;
}
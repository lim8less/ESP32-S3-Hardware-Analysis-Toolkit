#include "stats_task.h"

#include "stats.h"
#include "ring_buffer.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdio.h>

void stats_task(void *arg)
{
    while(1)
    {
        toolkit_stats_t stats =
            stats_get();

        printf(
            "\n----- TOOLKIT STATS -----\n"
        );

        printf(
            "Frames Captured : %lu\n",
            (unsigned long)
            stats.frames_captured
        );

        printf(
            "Bytes Captured  : %lu\n",
            (unsigned long)
            stats.bytes_captured
        );

        printf(
            "Dropped Frames  : %lu\n",
            (unsigned long)
            stats.dropped_frames
        );

        printf(
            "Ring Usage      : %d / %d\n",
            ring_buffer_count(),
            RING_BUFFER_SIZE
        );

        printf(
            "-------------------------\n"
        );

        vTaskDelay(
            pdMS_TO_TICKS(5000)
        );
    }
}
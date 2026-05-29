#include "timestamp.h"
#include "esp_timer.h"

uint64_t timestamp_now_us(void)
{
    return esp_timer_get_time();
}
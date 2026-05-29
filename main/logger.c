#include "logger.h"

#include <stdio.h>
#include <ctype.h>

void logger_print_event(capture_event_t *event)
{
    printf("\n[%llu us]\n",
           (unsigned long long)event->timestamp_us);

    printf("HEX   : ");

    for(int i = 0; i < event->length; i++)
    {
        printf("%02X ", event->data[i]);
    }

    printf("\n");

    printf("ASCII : ");

    for(int i = 0; i < event->length; i++)
    {
        if(isprint(event->data[i]))
            printf("%c", event->data[i]);
        else
            printf(".");
    }

    printf("\n");
}
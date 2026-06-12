idf_component_register(
    SRCS
        "main.c"
        "uart_sniffer.c"
        "uart_framer.c"
        "logger.c"
        "logger_task.c"
        "timestamp.c"
        "ring_buffer.c"
        "stats.c"
        "stats_task.c"
    INCLUDE_DIRS "."
)
#pragma once
#include <stdio.h>

enum log_level {
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO,
    LOG_DEBUG,
    LOG_TRACE1
};

extern int log_level;

#define log(level, msg, ...) do { if (log_level >= LOG_ ## level) fprintf(stderr, __FILE__, ":%d " msg "\n", __LINE__, ##__VA_ARGS__);} while(0)

void log_init(void);
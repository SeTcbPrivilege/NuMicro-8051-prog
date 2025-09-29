#include "logging.h"
#include <stdlib.h>
#include <string.h>

int log_level = 0;

void log_init(void) {
    char* log_level_str = getenv("LOG_LEVEL");
    if ((log_level = atoi(log_level_str)) > 0) {
        return;
    }

    #define TEST_LEVEL(macro) if (!strcmp(log_level_str, #macro)) { log_level = macro; return; }

    TEST_LEVEL(LOG_FATAL)
    TEST_LEVEL(LOG_ERROR)
    TEST_LEVEL(LOG_WARNING)
    TEST_LEVEL(LOG_INFO)
    TEST_LEVEL(LOG_DEBUG)
    TEST_LEVEL(LOG_TRACE1)

    #undef TEST_LEVEL
}

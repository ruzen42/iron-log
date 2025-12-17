#include <stdio.h>
#include <stdlib.h>

#include "../include/util.h"

static void
log_internal(FILE *out, const char *level, const char *message)
{
    char *msg = concat(level, message);
    if (!msg) return;

    char *line = concat(get_time(), msg);
    if (!line) {
        free(msg);
        return;
    }

    fprintf(out, "%s\n", line);

    free(msg);
    free(line);
}

void
log_error(const char *message)
{
    log_internal(stderr, RED "ERROR " RESET, message);
}

void
log_info(const char *message)
{
    log_internal(stdout, GREEN "INFO " RESET, message);
}

void
log_warn(const char *message)
{
    log_internal(stdout, YELLOW "WARN " RESET, message);
}

void
log_fatal(const char *message)
{
    log_internal(stderr, RED "FATAL " RESET, message);
}

void
log_debug(const char *message)
{
    log_internal(stdout, CYAN "DEBUG " RESET, message);
}

void
log_error_to_file(const char *message, const FILE* file)
{
    log_internal(file, RED "ERROR " RESET, message);
}

void
log_info_to_file(const char *message, const FILE* file)
{
    log_internal(file, GREEN "INFO " RESET, message);
}

void
log_warn_to_file(const char *message, const FILE* file)
{
    log_internal(file, YELLOW "WARN " RESET, message);
}

void
log_fatal_to_file(const char *message, const FILE* file)
{
    log_internal(file, RED "FATAL " RESET, message);
}

void
log_debug_to_file(const char *message, const FILE* file)
{
    log_internal(file, CYAN "DEBUG " RESET, message);
}



#include <stdio.h>

#include "../include/util.h"

void
log(char* s2, char* s3)
{
    fprintf(concat(s2, s3));
}

void
log_error(char* message)
{
    log(RED "ERROR" RESET, message);
}

void
log_info(char* message)
{
    log(GREEN "INFO" RESET, message)
}

void
log_warn(char* message)
{
    log(YELLOW "WARN" RESET, message);
}

void
log_fatal(char* message)
{
    log(RED "FATAL" RESET, message);
}

void
log_fatal(char* message)
{
    log(CYAN "DEBUG" RESET, message);
}


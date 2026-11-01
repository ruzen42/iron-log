#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "../include/util.h"

static void
LogInternal(FILE *out, const char *color, const char *level, const char *message)
{
    char timebuf[TIME_BUF_SIZE];
    if (!GetTimeR(timebuf, sizeof timebuf)) return;
    
    if (color) {
        fprintf(out, "%s%s%s%s%s", timebuf, color, level, RESET, message);
    } else {
        fprintf(out, "%s%s%s", timebuf, level, message); 
    }
}

#define DEFINE_LOG(name, out, color, level)              \
    void                                                 \
    Log##name(const char *message)                       \
    {                                                    \
        LogInternal(out, color, level, message);         \
    }                                                    \
    void                                                 \
    Log##name##Tofile(const char *m, FILE *f)            \
    {                                                    \
        LogInternal(f, NULL, level, m);                  \
    }

DEFINE_LOG(Info,  stdout, GREEN,  "INFO " )
DEFINE_LOG(Error, stderr, RED,    "ERROR ")
DEFINE_LOG(Warn,  stdout, YELLOW, "WARN " )
DEFINE_LOG(Fatal, stderr, RED,    "FATAL ")
DEFINE_LOG(Debug, stdout, CYAN,   "DEBUG ")

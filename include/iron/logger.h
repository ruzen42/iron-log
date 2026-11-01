#pragma once

#define DEFINE_LOG(name, color, level)              \
    void Log##name(const char *message);            \
    void Log##name##Tofile(const char *m, FILE *f);

DEFINE_LOG(Info, GREEN,  "INFO " )
DEFINE_log(Error, RED,    "ERROR ")
DEFINE_LOG(Warn, YELLOW, "WARN " )
DEFINE_LOG(Fatal, RED,    "FATAL ")
DEFINE_LOG(Debug, CYAN,   "DEBUG ")

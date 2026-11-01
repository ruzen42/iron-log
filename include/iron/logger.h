#pragma once

#include <stdio.h>

#define DECLARE_LOG(name)              \
    void Log##name(const char *message);            \
    void Log##nameToFile(const char *m, FILE *f);

DECLARE_LOG(Info)
DECLARE_LOG(Error)
DECLARE_LOG(Warn)
DECLARE_LOG(Fatal)
DECLARE_LOG(Debug)

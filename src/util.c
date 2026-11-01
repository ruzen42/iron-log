#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *
Concat(const char *s1, const char *s2)
{
    if (!s1 || !s2) return NULL;
    size_t l1 = strlen(s1), l2 = strlen(s2);
    char *r = malloc(l1 + l2 + 1);
    if (!r) return NULL;
    memcpy(r, s1, l1);
    memcpy(r + l1, s2, l2 + 1);   
    return r;
}

#define MAGIC_NUMBER_TIME 12

char *
GetTimeR(char *buf, size_t n)
{
    time_t t = time(NULL);
    struct tm tm;
    if (!localtime_r(&t, &tm)) return NULL;
    if (!strftime(buf, n, "[%H:%M:%S] ", &tm)) return NULL;
    return buf;
}

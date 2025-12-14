#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char*
concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#define MAGIC_NUMBER_TIME 12

char*
get_time(void)
{
    char tmp[MAGIC_NUMBER_TIME];
    time_t t = time(NULL);

    if (!localtime(&t))
        return NULL;

    strftime(tmp, sizeof(tmp), "[%H:%M:%S] ", localtime(&t));

    char *out = malloc(strlen(tmp) + 1);
    if (!out)
        return NULL;

    strcpy(out, tmp);
    return out;
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char*
concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#define MAGIC_NUMBER_TIME 9

const char*
get_time()
{
    char* buffer = malloc(MAGIC_NUMBER_TIME * sizeof(char));
    time_t t = time(NULL);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", localtime(&t));
    return buffer;
}

#pragma once

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define TIME_BUF_SIZE 16

char *Concat(const char* s1, const char* s2);
char *GetTimeR(char *buf, size_t n);


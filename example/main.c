#include <iron/logger.h>
#include <iron/logger_file.h>
#include <stdio.h>

int
main()
{
    const FILE* file = fopen("file", "w");
    log_info("info");
    log_info_to_file("info", file);
}

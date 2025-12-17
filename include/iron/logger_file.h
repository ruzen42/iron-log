#ifndef LOGGER_FILE_H
#define LOGGER_FILE_H

void
log_info_to_file(const char* message, const FILE* file);

void
log_error_to_file(const char* message, const FILE* file);

void
log_fatal_to_file(const char* message, const FILE* file);

void
log_warn_to_file(const char* message, const FILE* file);

void
log_debug_to_file(const char* message, const FILE* file);

#endif

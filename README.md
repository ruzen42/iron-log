iron - simple logging library for C
=================================

iron is a small, minimal logging library written in C.
It does one thing: print log messages with time and level.

No dependencies (except std).
No configuration files.
No dynamic features.
Just C.

Features
--------
- Simple API
- Colored log levels (ERROR, WARN, INFO, DEBUG, FATAL)
- POSIX-friendly
- Small codebase
- Easy to embed into projects

Non-features
------------
- No async logging
- No file rotation
- No formatting DSL
- No heap magic (unless you want it)
- No global state

Usage
-----

Include the header:

    #include "iron/logger.h"

Log messages:

    log_info("server started");
    log_warn("low memory");
    log_error("failed to open file");
    log_debug("value = 42");
    log_fatal("unrecoverable error");

Output format:

    [HH:MM:SS] INFO message

Building
--------

Static library:

    cc -c src/*.o
    ar rcs libiron.a logger.o

Shared library:

    cc -fPIC -c src/* 
    cc -shared -o libiron.so logger.o

Install
-------

    cp include/iron/logger.h /usr/local/include/iron
    cp libiron.a /usr/local/lib

Or just copy logger.c and logger.h into your project.

Design
------

clog follows the Unix philosophy:

- simple
- explicit
- readable
- hackable

The code is meant to be read and modified.
If you need more features, add them yourself.

License
-------

MIT

Author
------

Written by Jaroslav Mihajlenko
Inspired by suckless software.

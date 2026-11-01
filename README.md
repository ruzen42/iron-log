iron - simple logging library for C
=================================

iron is a small, minimal logging library written in C.
It does one thing: print log messages with time and level.

No dependencies (except std).
No configuration files.
No dynamic features.

Features
--------
- Simple API
- Colored log levels (ERROR, WARN, INFO, DEBUG, FATAL)
- POSIX-friendly (without Windows support)
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

    LogInfo("server started");
    LogWarn("low memory");
    LogError("failed to open file");
    LogDebug("value = 42");
    LogFatal("unrecoverable error");

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

libiron follows the SUCK philosophy:

- simple
- explicit
- readable
- hackable
- unix 

The code is meant to be read and modified.
If you need more features, add them yourself.

License
-------

MIT

Author
------

Written by Jaroslav Mihajlenko
Inspired by suckless software.

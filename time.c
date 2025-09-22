#pragma once
#include <stdlib.h>
#include <stdio.h>

// Returns time in YYYY-MM-DD HH:MM:SS format
static char* GetTimeString(time_t t) {
    struct tm* tm_info;
    static char buffer[26];

    tm_info = localtime(&t);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    if (EXTRA_DEBUG) printf("Time: %s\n", buffer);
    return buffer;
}

// Returns time in HH:MM:SS format
static char* GetShortTimeString(time_t t) {
    struct tm* tm_info;
    static char buffer[10];

    tm_info = localtime(&t);

    strftime(buffer, 10, "%H:%M:%S", tm_info);
    if (EXTRA_DEBUG) printf("Time: %s\n", buffer);
    return buffer;
}
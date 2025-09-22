#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

static bool DEBUG = true; // Set to true to enable debug console
static bool EXTRA_DEBUG = false; // Set to true for extra verbose logging

static bool g_consoleAllocated = false;
static void InitDebugConsole()
{
    AllocConsole();

    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    freopen("CONIN$", "r", stdin);

    // Disable buffering so logs appear instantly
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    g_consoleAllocated = true;
}

void CloseConsole() {
    if (g_consoleAllocated) {
        FreeConsole(); // Free the console
        g_consoleAllocated = false;
    }
}


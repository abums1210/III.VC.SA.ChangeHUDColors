#pragma once
#include "plugin.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#endif

struct ColorPatch {
    unsigned int addrR, addrG, addrB;
    int addrA;
    CRGBA const *color;
};

#ifdef GTASA
struct SaColorEntry {
    unsigned char colorIndex;
    CRGBA const *color;
};
#endif

class Hooks {
public:
    static void ApplyColorHooks();
    static void ConfigRefresher();
};
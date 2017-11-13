#ifdef DEBUG
// This condition to debug avoid linking with useless functions if debugging is not used.

#include "cansat_debug.h"

int freeRam () {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

#endif // DEBUG

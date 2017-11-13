//ifdef DEBUG ** THIS DOES NOT WORK: Arduino IDE does not allow for defining
// 	      ** custom preprocessor symbols during compilation of libraries.
// Keep this file minimal to avoid memory usage when debugging is off. 

#include "cansat_debug.h"

// This function has a ZERO memory foot-print. 

int freeRam () {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}


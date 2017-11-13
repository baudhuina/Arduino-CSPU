//ifdef DEBUG ** THIS DOES NOT WORK: Arduino IDE does not allow for defining
// 	      ** preprocessor symbols during compilation of libraries.

// This condition to debug avoid linking with useless functions if debugging is not used.

#include "cansat_debug.h"
#include <HardwareSerial.h>

void initDebug(int baudRate)
{
	if(!Serial.available()) 
	{
		Serial.begin(9600);
  		// while the serial stream is not open, do nothing:
  		while (!Serial) ;
	}
}

int freeRam () {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
//endif // DEBUG

/********************************************************
 *
 * common debugging macros and utilities
 *
 * Usage: include library.
 *        define symbol DEBUG
 * 	  initialize Serial object conditional to DEBUG in setup.
 *	     *** IMPROVE THIS TO MACRO DINIT(baudRate) 
 *	  define a specific symbol for each module (hereafter called moduleTag), e.g.
 *	     DBG_XXXX for debugging module XXXX. Value 1 activates module debug, 
 *	     value 0 deactivates module debug.
 *	  make use of the DPRINT, DPRINTLN etc. macros wherever needed.
 *	  In order to deactivate the whole debugging (and reduce overhead to 0, undefined
 *	  symbol DEBUG.
 *
 * v1.0  13/11/2017.
 *********************************************************/
#ifndef CANSAT_DEBUG_H
#define CANSAT_DEBUG_H

#ifdef DEBUG
  #include <Arduino.h>
  // -------- Define Debugging macros ----- Do not change.
  #define DPRINT(moduleTag, msg)    if(moduleTag!=0) Serial.print(F(msg));     //DPRINT is a macro, debug print
  #define DPRINTLN(moduleTag, msg)  if(moduleTag!=0) Serial.println(F(msg));   //DPRINTLN is a macro, debug print with new line
  #define DDELAY(...)    delay(__VA_ARGS__) 
  
  #define DFREE_RAM(moduleTag) if(moduleTag!=0)  { Serial.print(F("Free RAM: ")); Serial.print(freeRam()); Serial.println(" bytes.");}

  // -------- Function prototypes
  int freeRam ();  // Return free dynamic memory in bytes. 
#else
  #define DPRINT(moduleTag, msg)     //now defines a blank line
  #define DPRINTLN(moduleTag, msg)   //now defines a blank line
  #define DDELAY(...)        //now defines a blank line
  #define DFREE_RAM(moduleTag)      //now defines a blank line
#endif

#endif // CANSAT_DEBUG_H

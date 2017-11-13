/********************************************************
 *
 * Common debugging macros and utilities
 *
 * Usage: define symbol DEBUG
 *	  include library (AFTER the definition of DEBUG symbol)
 * 	  initialize module by calling DINIT(baudRate) (usually DINIT(9600)
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
  // -------- Define debugging macros ----- 
  // Call DINIT once in setup().
  #define DINIT(baudRate)	initDebug(baudRate);

  // Print a debugging msg, if the moduleTag != 0 (non final carriage return)
  #define DPRINT(moduleTag, msg)    if(moduleTag!=0) Serial.print(F(msg)); AA  

  // Print a debugging msg, if the moduleTag != 0 (with final carriage return)
  #define DPRINTLN(moduleTag, msg)  if(moduleTag!=0) Serial.println(F(msg)); 

  // Wait for x msec if the moduleTag != 0  is active.
  #define DDELAY(moduleTag,durationInMsec)    if(moduleTag!=0) delay(durationInMsec);
  
  // Print free ram if the moduleTag != 0 
  #define DFREE_RAM(moduleTag) if(moduleTag!=0)  { Serial.print(F("Free RAM: ")); Serial.print(freeRam()); Serial.println(" bytes.");}

  // -------- Function prototypes
  int freeRam ();  // Return free dynamic memory in bytes. 
  void initDebug(int baudRate);
#else
  // Define all macros as blank lines.
  #define DINIT(baudRate)
  #define DPRINT(moduleTag, msg)   
  #define DPRINTLN(moduleTag, msg)  
  #define DDELAY(moduleTag,durationInMsec)        
  #define DFREE_RAM(moduleTag)     
#endif

#endif // CANSAT_DEBUG_H

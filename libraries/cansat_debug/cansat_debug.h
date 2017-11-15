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
  // This macro does not call a function to reduce memory usage. 
  #define DINIT(baudRate) if(!Serial.available()) { Serial.begin(9600);while (!Serial);}

  // Print a debugging STRING msg, if the moduleTag != 0 (non final carriage return)
  // The string is not stored in dynamic memory 
  #define DPRINTS(moduleTag, msg)    if(moduleTag!=0) Serial.print(F(msg)); 

  // Print a debugging STRING msg, if the moduleTag != 0 (with final carriage return)
  // The string is not stored in dynamic memory 
  #define DPRINTSLN(moduleTag, msg)  if(moduleTag!=0) Serial.println(F(msg)); 

  // Print a debugging NUMERIC value, if the moduleTag != 0 (non final carriage return)
  #define DPRINT(moduleTag, numValue)    if(moduleTag!=0) Serial.print(numValue);  

  // Print a debugging NUMERIC value, if the moduleTag != 0 (with final carriage return)
  #define DPRINTLN(moduleTag, numValue)  if(moduleTag!=0) Serial.println(numValue); 

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
  #define DPRINTS(moduleTag, msg)   
  #define DPRINTSLN(moduleTag, msg) 
  #define DPRINT(moduleTag, numValue)   
  #define DPRINTLN(moduleTag, numValue)  
  #define DDELAY(moduleTag,durationInMsec)        
  #define DFREE_RAM(moduleTag)     
#endif

#endif // CANSAT_DEBUG_H

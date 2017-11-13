#ifdef DEBUG
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

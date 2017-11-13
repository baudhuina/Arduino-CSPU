

#define DEBUG  // This is the main switch for the debugging code. 
               // Comment out to remove debugging code. 
#include <cansat_debug.h> // Always include, even if DEBUG is not defined!
                          // Always include AFTER definition of DEBUG
  // -------- Select which part to debug. 0=off, 1=on. 
  // -------- Add new modules as needed. 
#define DBG_LOOP 1
#define DBG_SETUP 1
#define DBG_MODULE_xxx 0

//-------------------------- GLOBAL CONSTANTS & VARIABLES -------------------
const int ledPin =  13;      // the number of the LED pin

// ------------------------- MAIN FUNCTIONS ---------------------------------
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  DINIT(9600); // Init debugging
  DFREE_RAM(DBG_SETUP);
  DPRINTLN(DBG_SETUP, "setup OK");
}

void loop() {
  DPRINTLN(DBG_LOOP, "**loop in **");

  toggleLED();
  delay(1000);  // wait for 1 sec
  DDELAY(DBG_LOOP, 1000); // wait for 1 additional sec if debugging
  DPRINTLN(DBG_LOOP, "**loop out **");
}

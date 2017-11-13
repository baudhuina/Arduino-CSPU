
#define DEBUG  // This is the main switch for the debugging code. 
#include "cansat_debug.h" // Always include, even if DEBUG is not defined!
#ifdef DEBUG
  // -------- Select which part to debug. 0=off, 1=on. 
  // -------- Add new modules as needed. 
  #define DBG_LOOP 1
  #define DBG_SETUP 1
  #define DEBUG_MODULE_xxx 0
#endif

//-------------------------- GLOBAL CONSTANTS & VARIABLES -------------------
const int ledPin =  13;      // the number of the LED pin
int state = 0;

// ------------------------- MAIN FUNCTIONS ---------------------------------
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
#ifdef DEBUG
  Serial.begin(9600);
  // while the serial stream is not open, do nothing:
  while (!Serial) ;
#endif
  DFREE_RAM(DBG_SETUP);
  DPRINTLN(DBG_SETUP, "setup OK");
}

void loop() {
  DPRINTLN(DBG_LOOP, "**loop in **");

  if (state == 0)
  {
    digitalWrite(ledPin, HIGH);
    state = 1;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    state = 0;
  }
  delay(1000);  // wait for 1 sec
  DDELAY(1000); // wait for 1 additional sec if debugging
  DPRINTLN(DBG_LOOP, "**loop out **");
}

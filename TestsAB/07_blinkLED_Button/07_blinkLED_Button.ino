/*  
 *   The circuit:
 * - LED attached from pin 13 to ground
 * - pushbutton attached to pin 12 from +5V
 * - 10K resistor attached to pin 12 from ground
 *
 * - Note: on most Arduinos there is already an LED on the board
 *   attached to pin 13.
 */ 

//define DEBUG  // This is the main switch for the debugging code. 
               // Comment out to remove debugging code. 
#include <cansat_debug.h> // Always include, even if DEBUG is not defined!
                          // Always include AFTER definition of DEBUG
  // -------- Select which part to debug. 0=off, 1=on. 
  // -------- Add new modules as needed. 
#define DBG_LOOP 0
#define DBG_SETUP 1
#define DBG_BUTTON 1

//-------------------------- GLOBAL CONSTANTS & VARIABLES -------------------
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// ------------------------- MAIN FUNCTIONS ---------------------------------
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  DINIT(9600); // Init debugging
  DFREE_RAM(DBG_SETUP);
  DPRINTSLN(DBG_SETUP, "setup OK");
}

void loop() {
  DPRINTSLN(DBG_LOOP, "**loop in **");

  if (buttonPushed(buttonPin)) toggleBlinking();

  blinkLED(); // This cause the led to change state only if blincking is active.
  delay(50);  // No reason to run too fast.
  
  DDELAY(DBG_LOOP, 1000); // wait for 1 additional sec if debugging
  DPRINTSLN(DBG_LOOP, "**loop out **");
}

#define DEBUG  // This is the main switch for the debugging code. 
#ifdef DEBUG
  // -------- Select which part to debug. 0=off, 1=on. 
  // -------- Add new modules as needed. 
  #define DBG_LOOP 1
  #define DBG_SETUP 1
  #define DEBUG_MODULE_xxx 0

  // -------- Define Debugging macros and functions ----- Do not change.
  #define DPRINT(moduleTag, msg)    if(moduleTag!=0) Serial.print(F(msg));     //DPRINT is a macro, debug print
  #define DPRINTLN(moduleTag, msg)  if(moduleTag!=0) Serial.println(F(msg));   //DPRINTLN is a macro, debug print with new line
  #define DDELAY(...)    delay(__VA_ARGS__) 
  
  #define DFREE_RAM(moduleTag) if(moduleTag!=0)  { Serial.print(F("Free RAM: ")); Serial.print(freeRam()); Serial.println(" bytes.");}
   int freeRam () {
    extern int __heap_start, *__brkval;
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
  } 

#else
  #define DPRINT(moduleTag, msg)     //now defines a blank line
  #define DPRINTLN(moduleTag, msg)   //now defines a blank line
  #define DDELAY(...)        //now defines a blank line
  #define DFREE_RAM(moduleTag)      //now defines a blank line
#endif




const int ledPin =  13;      // the number of the LED pin
int state = 0;

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

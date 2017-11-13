#define DEBUG 
const int ledPin =  13;      // the number of the LED pin
int state = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
#ifdef DEBUG
  Serial.begin(9600);
  // while the serial stream is not open, do nothing:
  while (!Serial) ;
  Serial.println(F("setup OK"));
#endif
}

void loop() {
#ifdef DEBUG
  Serial.println(F("**loop in **"));
#endif

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
  delay(2000);  // wait for 2 sec
#ifdef DEBUG
  Serial.println("**loop out **");
#endif
}

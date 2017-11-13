const int ledPin =  13;      // the number of the LED pin
int state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
   // while the serial stream is not open, do nothing:
   while (!Serial) ;
  Serial.println("setup OK");
}

void loop() {
  Serial.println("**loop in **");
  // put your main code here, to run repeatedly:
  if (state == 0)
  {
    digitalWrite(ledPin, HIGH);
    state=1;
  }
  else
  {
    digitalWrite(ledPin, LOW);
    state=0;
  }
  delay(2000);  // wait for 2 sec
  Serial.println("**loop out **");
}

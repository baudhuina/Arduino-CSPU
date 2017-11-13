const int ledPin =  13;      // the number of the LED pin
int state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
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
  delay(1000);  // wait for 1 sec
}

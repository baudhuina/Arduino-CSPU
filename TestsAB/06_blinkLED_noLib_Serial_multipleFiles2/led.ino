
int state = 0; // Current state of the LED, 0=off, 1=on.

void toggleLED(){
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
}


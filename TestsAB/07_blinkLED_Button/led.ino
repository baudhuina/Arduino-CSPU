
int state = 0; // Current state of the LED, 0=off, 1=on.
int blinking=0; // Current state of blinking. If on, blinkLED causes 
                // LED state to change. 
void toggleBlinking()
{
  if (blinking) digitalWrite(ledPin, LOW); // turn off.
  blinking=!blinking;
}

void blinkLED()
{
  if (blinking) toggleLED();
}

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


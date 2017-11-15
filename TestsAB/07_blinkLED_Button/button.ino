/* Devrait devenir une classe pour supporter plusieurs boutons. 
   Ou memoriser le num du bouton ici. */ 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int was0=1;

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

bool buttonPushed(int buttonPin) 
{
  bool result=false;
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  DPRINT(DBG_BUTTON,"read ");
  DPRINTLN(DBG_BUTTON,buttonState);
  if (buttonState && was0 &&(millis() - time > debounce))
  {
    DPRINTLN(DBG_BUTTON,"closed");
    // We moved from 0 to 1.
    result=true;
    was0=0;
    time = millis(); 
  }
  if (!buttonState) was0=1;

  return result;
}


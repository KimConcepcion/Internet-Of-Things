
//  Includes:
#include "Camera.h"
#include "Speaker.h"
#include "Mail.h"

//  Pins:
int pushPin = D0;

void setup()
{
  pinMode(pushPin, INPUT_PULLUP);
}

void loop()
{
  //  Read the button state:
  int buttonState = digitalRead(pushPin);

  //  Test input from button:
  if(buttonState == LOW)
  {

  }

  else
  {

  }
}

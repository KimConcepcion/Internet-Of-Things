
//  Pins:
int pushPin = D0;

void playSound()
{

}

void setReceiver()
{

}

void send(char *msg)
{

}

void takePhoto()
{

}

//	Google Calendar functions:
void getEvent()
{
  
}

void setup()
{
  pinMode(pushPin, INPUT_PULLUP);
  Particle.subscribe("Upcomming_Event")
}

void loop()
{
  //  Read the button state:
  int buttonState = digitalRead(pushPin);

  //  Test input from button:
  if(buttonState == LOW)
  {
    //  Publish the event:
    Particle.publish("buttonState", "Pressed", 60, PRIVATE);

    //  Update the buttonstate:
    buttonState = HIGH;
  }

  else
  {
    //  Publish the event:
    Particle.publish("buttonState", "unPressed", 60, PRIVATE);
  }
}

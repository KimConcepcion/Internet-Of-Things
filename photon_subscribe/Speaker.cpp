
#include "Speaker.h"

void setupSpeaker()
{
  pinMode(SPEAKER, OUTPUT);
}

void playSound()
{
  digitalWrite(SPEAKER, HIGH);
}

void stopSound()
{
  digitalWrite(SPEAKER, LOW);
}

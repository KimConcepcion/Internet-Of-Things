#include "speaker.h"
#include "sound.h"

const int audioFrequency = 22050; // Hz
Speaker speaker((uint16_t*)sound, sizeof(sound) / sizeof(sound[0]));

void setup() {
  String data = String(10);
  // Here we are going to subscribe to your buddy's event using Particle.subscribe
  Particle.subscribe("DoorBell", myHandler);
  // Subscribe will listen for the event buddy_unique_event_name and, when it finds it, will run the function myHandler()
  // (Remember to replace buddy_unique_event_name with your buddy's actual unique event name that they have in their firmware.)
  // myHandler() is declared later in this app.
}


void loop() {
  
}


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data)
{
  if (strcmp(event,"DoorBell")==0) {
      
    //play audio
    speaker.begin(audioFrequency);
    // send mail to user
    Particle.publish("SendMail");
    //stop users spotify music
    Particle.publish("musicStop",data,PRIVATE);
    // wait for 2 seconds for tune to finish
    delay(2000);
    // stop music
    speaker.end();
  }
  else{
    // do nothing
  }
}


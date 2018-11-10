
#include "Adafruit_VC0706.h"
#include "ParticleSoftSerial.h"

#define chipselect 10
#define SS D5
#define RX D3
#define TX D2

//  Setup camera:
ParticleSoftSerial cameraconnection = ParticleSoftSerial(TX, RX);
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

void setup()
{
  //  Setup serial connection baud rate:
  Serial.begin(9600);
  Serial.println("System is online!");

  //  Setup SPI for SD card reader:
  if(chipselect != SS) pinMode(SS, OUTPUT);

  //  Locate camera:
  if(cam.begin()){
    Serial.println("Camera found!");
  }
  else{
    Serial.println("No camera was found!");
    return;
  }

  char *reply = cam.getVersion();
  if(reply == 0){
    Serial.println("Failed to get version!");
  }
  else{
    Serial.println("----------------------------------");
    Serial.println(reply);
    Serial.println("----------------------------------");
  }

  //  Set resolution:
  cam.setImageSize(VC0706_160x120);

  Serial.println("Snap in 3 seconds...");
  delay(3000);

  if( !cam.takePicture()){
    Serial.println("Failed to snap!");
  }

  else{
    Serial.println("Picture taken");
  }
}

void loop(){}

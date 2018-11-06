/*
 * Project camera
 * Authors: Lasse A. Frederiksen, Kim C. Nielsen and Mads H. Villadsen
 * Date: 2018
 */

//  Includes:
#include "Adafruit_VC0706.h"
#include "ParticleSoftSerial.h"
#include <SPI.h>

#define SPI_CONFIGURATION 0
const uint8_t chipSelect = SS;

ParticleSoftSerial camera_connection = ParticleSoftSerial(D2, D3);
Adafruit_VC0706 cam = Adafruit_VC0706(&camera_connection);

void setup()
{
  pinMode(chipSelect, OUTPUT);
  Serial.begin(9600);
  SPI.begin();

  cam.begin();

  //  Location of camera:
  if(cam.begin()){
    Serial.println("Camera Found!");
  }

  else{
    Serial.println("No camera was found!");
  }

  //  Test snapshot:
  if(!cam.takePicture()){
    Serial.println("Could not take picture...");
  }

  else{
    Serial.println("Picture taken!");
  }

}

void loop()
{}

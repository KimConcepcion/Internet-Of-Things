
//	Pins:
int SPEAKER = D1;

//	buttonHandler
void buttonHandler(const char *event, const char *data)
{
	if(strcmp(data, "Pressed") == 0)
	{
		//playSound();
	}

	else if (strcmp(data, "unPressed") == 0)
	{
		//stopSound();
	}
}

//	Speaker functions:
void playSound()
{
	digitalWrite(D1, HIGH);
}

void stopSound()
{
	digitalWrite(D1, LOW);
}

//	Spotify functions:
void stopMusic()
{

}

//	Google Calendar functions:
void getEvent()
{

}

void setup()
{
	Serial.begin(9600);

	//	Setup HW
	pinMode(D1, OUTPUT);

	//	Setup subscription:
	Particle.subscribe("buttonState", buttonHandler);
}

void loop()
{

}


//	Pins:
int SPEAKER = D1;

//	buttonHandler
void buttonHandler(const char *event, const char *data)
{
	if(strcmp(data, "Pressed") == 0)
	{
		playSound();
	}

	else if (strcmp(data, "unPressed") == 0)
	{
		stopSound();
	}
}

//	Speaker functions:
void playSound()
{
	//	Turn the Speaker on:
	digitalWrite(D1, HIGH);
}

void stopSound()
{
	//	Turn the speaker off:
	digitalWrite(D1, LOW);
}

//	Spotify functions:
void stopMusic()
{

}

void setup()
{
	//	Setup the serial data transmission and baud rate:
	Serial.begin(9600);

	//	Setup HW
	pinMode(D1, OUTPUT);

	//	Setup subscription:
	Particle.subscribe("buttonState", buttonHandler);
}

void loop(){}

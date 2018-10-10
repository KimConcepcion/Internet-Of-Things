
void setup()
{
	Serial.begin(9600);

	//	Setup HW:
	setupSpeaker();

	Particle.subscribe("buttonState", buttonHandler);
}

void loop()
{

}

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

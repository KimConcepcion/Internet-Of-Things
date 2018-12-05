
//  Pins
int led = D7;

void setup() 
{
    //  Subscribe to IFTTT events:
    Particle.subscribe("Start_Event", startEvent);
    Particle.subscribe("End_Event", endEvent);
    
    Serial.begin(9600);
    Serial.println("Connection established!");

    //  Setup IO:
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

//  Event handler for started events:
void startEvent(const char *event, const char *data)
{
    if( strcmp(event, "Start_Event") == 0 )
    {
        Serial.println("Event started!");
        digitalWrite(led, HIGH);
    }
}

//  Event handler for ended events:
void endEvent(const char *event, const char *data)
{
    if( strcmp(event, "End_Event") == 0 )
    {
        Serial.println("Event ended!");
        digitalWrite(led, LOW);
    }
}
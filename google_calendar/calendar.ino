bool homeState = true;

void setup() 
{
    //  Subscribe to IFTTT events:
    Particle.subscribe("Start_Event", startEvent);
    Particle.subscribe("End_Event", endEvent);
    
    Serial.begin(9600);
    Serial.println("Connection established!");

}

//  Event handler for started events:
void startEvent(const char *event, const char *data)
{
    if( strcmp(event, "Start_Event") == 0 )
    {
        Serial.println("Event started!");
        homeState = false;
    }
}

//  Event handler for ended events:
void endEvent(const char *event, const char *data)
{
    if( strcmp(event, "End_Event") == 0 )
    {
        Serial.println("Event ended!");
        homeState = true;
    }
}

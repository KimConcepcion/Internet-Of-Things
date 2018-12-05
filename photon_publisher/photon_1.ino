
//  Pins:
int button = D3;

void setup() {
    pinMode(button, INPUT);
}

void loop() {
    if(digitalRead(button) == HIGH){
        Particle.publish("DoorBell");
        delay(500);
    }
}

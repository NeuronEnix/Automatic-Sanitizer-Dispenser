#include <NewPing.h>
#include<ultrasonic.h>
#include<relay.h>

Ultrasonic *sensor;
Relay *relay;

void setup() {

    Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.

    sensor = new Ultrasonic();
    relay = new Relay();

}
int dist;
void loop() {
    delay(175);   
       
    if( (dist = sensor->objectDetected()) ) {
        relay->activate();
    } else relay->deActivate();

  
}
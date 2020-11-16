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
    const uint32_t t = millis();
    if( (dist = sensor->objectDetected()) ) {
        relay->enable();
    } else relay->disable();
    Serial.print( "RunTime: ");
    Serial.println( millis() - t);
  
}
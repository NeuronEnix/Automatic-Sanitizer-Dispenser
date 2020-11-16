#include <NewPing.h>
#include<ultrasonic.h>
#include<relay.h>
#include<motor.h>

Ultrasonic *sensor;
Relay<Motor> *relay;

void setup() {

    Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.

    sensor = new Ultrasonic();
    relay = new Relay<Motor>( new Motor() );

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
#include <NewPing.h>
#include<ultrasonic.h>
Ultrasonic *sensor;

void setup() {
    Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
    sensor = new Ultrasonic();
}
int dist;
void loop() {
    delay(250);   
       
    if( (dist = sensor->objectDetectedAt()) ) {
        Serial.print( "Object at: ");
        Serial.println( dist );
    }        

  
}
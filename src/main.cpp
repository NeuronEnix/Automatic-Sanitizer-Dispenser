#include<Arduino.h>
#include<master.h>

Master *master;

void setup() {

    Serial.begin(9600);
    master = new Master();

}

void loop() {
    delay(175);   
    master->run();  
}
#include<Arduino.h>
#include<config.h>
#include<ultrasonic.h>
#include<relay.h>
#include<motor.h>

class Master{
private:
    /* data */

    Ultrasonic *sensor;
    Relay<Motor> *relay;

    bool objectWasDetected = false;
    
public:
    Master(/* args */);
    ~Master();

    void run();
};

Master::Master(/* args */) {
    this->sensor = new Ultrasonic();
    this->relay = new Relay<Motor>( new Motor() );
}

Master::~Master(){}

void Master::run(){
    const uint32_t curTime = millis(); // deb
    const uint32_t dist = sensor->objectDetected();
    if( dist ) {
        if( sensor->confirmedObjectDetectionAt() + MOTOR_MAX_RUN_TIME_IN_MS < curTime ) relay->disable();
        else relay->enable();  
    } 
    else{ relay->disable(); }

    // Serial.print( "; RunTime: "); // deb
    // Serial.println( millis() - curTime); // deb
}
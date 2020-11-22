#include<NewPing.h>
#include<config.h>

class Ultrasonic {

private:
    const int trigPin;
    const int echoPin;
    const uint32_t minTrigDist, maxTrigDist ;
    const uint32_t objectDetectionDelay;

    uint32_t potentialObjectDetectedAt;
    uint32_t objectDetectionConfirmedAt;
    NewPing *sonar;

    unsigned long objectDetectedAt() {
        unsigned long dist = this->sonar->ping_cm();
            Serial.print( "Object At: "); // deb
            Serial.println( dist ); // deb
        if( minTrigDist <= dist and dist <= maxTrigDist ){


            return dist;
        }
        return 0;
    }

public:
    Ultrasonic(): 
        trigPin( ULTRASONIC_TRIG_PIN ), 
        echoPin( ULTRASONIC_ECHO_PIN ), 
        minTrigDist( ULTRASONIC_MIN_TRIGGER_DIST_IN_CM ),
        maxTrigDist( ULTRASONIC_MAX_TRIGGER_DIST_IN_CM ),
        objectDetectionDelay( ULTRASONIC_OBJECT_DETECTION_DELAY_IN_MS )
    {
        this->potentialObjectDetectedAt = 0 ;
        this->sonar = new NewPing( trigPin, echoPin );
    }

    uint32_t confirmedObjectDetectionAt(){
        return this->objectDetectionConfirmedAt;
    }
    bool objectDetected() {
        unsigned long dist = this->objectDetectedAt();
        
        if( dist ) {
            const uint32_t curTime = millis();

            if( potentialObjectDetectedAt == 0 )
                potentialObjectDetectedAt = curTime;
            else if( potentialObjectDetectedAt + objectDetectionDelay < curTime ){
                if( objectDetectionConfirmedAt == 0 ) objectDetectionConfirmedAt = curTime;
                return true;
            }
                
        } else { potentialObjectDetectedAt = 0; objectDetectionConfirmedAt = 0; }

        return false;
    }
};


#include<NewPing.h>
#include<config.h>

class Ultrasonic {

private:
    const int trigPin;
    const int echoPin;
    const unsigned long trigDist;
    const unsigned long objectDetectionDelay;

    unsigned long potentialObjectDetectedAt;
    NewPing *sonar;

    unsigned long objectDetectedAt() {
        unsigned long dist = this->sonar->ping_cm();
        if( 0 < dist and dist < trigDist ){

            Serial.print( "Object At: "); // deb
            Serial.println( dist ); // deb

            return dist;
        }
        return 0;
    }

public:
    Ultrasonic(): 
        trigPin( ULTRASONIC_TRIG_PIN ), 
        echoPin( ULTRASONIC_ECHO_PIN ), 
        trigDist( ULTRASONIC_TRIGGER_DIST_IN_CM ),
        objectDetectionDelay( ULTRASONIC_OBJECT_DETECTION_DELAY_IN_MS )
    {
        this->potentialObjectDetectedAt = 0 ;
        this->sonar = new NewPing( trigPin, echoPin );
    }

   
    bool objectDetected() {
        unsigned long dist = this->objectDetectedAt();
        
        if( dist ) {

            if( potentialObjectDetectedAt == 0 )
                potentialObjectDetectedAt = millis();
            else if( potentialObjectDetectedAt + objectDetectionDelay <= millis() )
                return true;
                
        } else potentialObjectDetectedAt = 0;

        return false;
    }
};


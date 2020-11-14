#include<NewPing.h>
#include<config.h>

class Ultrasonic {

private:
    const int trigPin;
    const int echoPin;
    const unsigned long trigDist;

    NewPing sonar;

public:
    Ultrasonic(): 
        trigPin( ULTRASONIC_TRIG_PIN ), 
        echoPin( ULTRASONIC_ECHO_PIN ), 
        trigDist( ULTRASONIC_TRIGGER_DIST_IN_CM ),
        sonar( NewPing( trigPin, echoPin ) )
    {

    }

    unsigned long objectDetectedAt() {
        unsigned long dist = this->sonar.ping_cm();
        if( 0 < dist and dist < trigDist )
            return dist;
        return 0;
    }
};


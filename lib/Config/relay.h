#include<Arduino.h>
#include<config.h>
#include<motor.h>

class Relay {

private: 
    const int pin;
    bool isActive;

public:

    Relay (): pin( RELAY_MODULE_PIN ), isActive( false )
    {
        this->deActivate();
    }

    void activate() {
        if( this->isActive ) return;
        digitalWrite( this->pin, HIGH );
        this->isActive = true;
    }

    void deActivate() {
        if( !this->isActive ) return;
        digitalWrite( this->pin, LOW );
        this->isActive = false;
    }
    
};
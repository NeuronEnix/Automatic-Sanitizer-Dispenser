#include<Arduino.h>
#include<config.h>
#include<motor.h>

class Relay {

private: 
    const int pin;
    bool isEnabled;
    Motor *motor;

public:

    Relay (): pin( RELAY_MODULE_PIN ), isEnabled( false )
    {
        this->motor = new Motor();
        this->disable();
    }

    bool enable() {

        if( !motor->enable() ) return !this->disable();

        if( !this->isEnabled ){
            digitalWrite( this->pin, HIGH );
            this->isEnabled = true;
        }
        return true;

    }

    bool disable() {

        if( this->isEnabled ){
            motor->disable();
            digitalWrite( this->pin, LOW );
            this->isEnabled = false;
        }
        return true;
    }
    
};
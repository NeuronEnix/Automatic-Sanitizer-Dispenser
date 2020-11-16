#include<Arduino.h>
#include<config.h>

template<class T>
class Relay {

private: 
    const int pin;
    bool isEnabled;
    T *device;

public:

    Relay ( T *device ): pin( RELAY_MODULE_PIN ), isEnabled( false )
    {
        this->device = device;
        this->disable();
    }

    bool enable() {

        if( !device->enable() ) return !this->disable();

        if( !this->isEnabled ){
            digitalWrite( this->pin, HIGH );
            this->isEnabled = true;
        }
        return true;

    }

    bool disable() {

        if( this->isEnabled ){
            device->disable();
            digitalWrite( this->pin, LOW );
            this->isEnabled = false;
        }
        return true;
    }
    
};
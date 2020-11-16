#include<Arduino.h>
#include<config.h>

class Motor {

private:
    const unsigned long maxRunTime;
    const unsigned long relaxTime;
    
    bool isEnabled;
    unsigned long forcefullyDisableAt;
    unsigned long safeToEnableAt;

    bool canEnable(){
        return this->safeToEnableAt < millis();
    }

public:
    Motor() : 
        maxRunTime( MOTOR_MAX_RUN_TIME_IN_MS ),
        relaxTime( MOTOR_RELAX_TIME_IN_MS )
    {
        this->isEnabled = false;
        this->forcefullyDisableAt = this->safeToEnableAt = 0;
    }   

    bool enable() {

        if( !this->isEnabled ){
            
            if( this->canEnable() ) {
                this->isEnabled = true;
                this->forcefullyDisableAt = millis() + this->maxRunTime;
            } else return false;

        }

        if( this->forcefullyDisableAt < millis() ){
            this->disable();
            return false;
        }
        
        return true;
    } 

    bool disable(){ 

        if( this->isEnabled ){
            this->safeToEnableAt = millis() + this->relaxTime ;
            this->isEnabled = false;
        }
        
        return true;
    }
    
};
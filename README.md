# Automatic Sanitizer Dispenser
### A Fully Automated Hand Sanitizer Dispenser Using `Arduino` and `Ultrasonic Sensor` in  `C++`

```C++
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
```

### Note: The program needs `NewPing` Library, download it before running the code.

### Code Structure
#### Main Program is in `./src` directory 
#### Rest of the configuration and classes are in `./lib` directory


#### Configuration File: `./lib/Config/config.h`

## Classes

#### Master class :  `./lib/Master/master.h`

#### Relay class :  `./lib/Config/relay.h`
#### Motor class :  `./lib/Config/motor.h`
#### Ultrasonic Sensor class :  `./lib/Config/ultrasonic.h`

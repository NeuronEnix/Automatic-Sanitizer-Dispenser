#include <NewPing.h>
#include<config.h>

NewPing sonar( ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN ); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(250);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping_cm(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.print("cm");
  if( uS > 20 ) Serial.println();
  else Serial.println(" aaaaaaaa");
}
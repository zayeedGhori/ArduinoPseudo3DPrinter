// Include the Servo library 
#include <Servo.h>

int servoPin = 3;
Servo servo1;

void setup() {
  servo1.attach(servoPin);

  servo1.write(180); // run at full speed
}

void loop() {
}

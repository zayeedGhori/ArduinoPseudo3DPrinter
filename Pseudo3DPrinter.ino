// Include the Servo library 
#include <Servo.h>

int servoPin = 3;
Servo servo1;

void setup() {
  servo1.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(180);
  delay(3000);

  servo.write(90);
  delay(1000);
}

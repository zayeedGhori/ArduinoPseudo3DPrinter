// Include the Servo library
#include <Servo.h>

// servo variables
int servo1Pin = 3;
int servo2Pin = 5;
int servo3Pin = 6;
Servo servo1, servo2, servo3;

// variables for switch
int switchPinIn = 13;
int reading;
int prevState = HIGH;

void setup() {
  // assign servos to pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  
  pinMode(switchPinIn, INPUT); // make this pin receive voltage
}

void loop() {
  reading = digitalRead(switchInPin); // check current state of button

  // if the button is not pressed, make motors run at full speed
  if (reading == LOW && prevState == HIGH){
    servo1.write(180);
    servo2.write(180);
    servo3.write(180)
  }

  // if the button is pressed, stop the motors
  else if (reading == HIGH && prevState == LOW){
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
  }
  
  prevState = reading; // make prevState the current state
}

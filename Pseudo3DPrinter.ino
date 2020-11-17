// Include the Servo library
#include <Servo.h>

// servo variables
int servoZPin = 3;
int servo2Pin = 5;
int servo3Pin = 6;
Servo servoZ, servo2, servo3;
bool delayRunning = false;
bool goBackUp = false;
int delayStart;
int delayLength = 5000;

// variables for switch
int switchPinIn = 13;
int reading;
int prevState = HIGH;

void setup() {
  // assign servos to pins
  servoZ.attach(servoZPin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);

  pinMode(switchPinIn, INPUT); // make this pin receive voltage
}

void loop() {
  reading = digitalRead(switchPinIn); // check current state of button

  // if the button is pressed, stop the motors
  if (reading == HIGH && prevState == LOW) {
    servoZ.write(90); //stops the motor
    
    goBackUp = !goBackUp; // toggles back and forth between true and false
    delayStart = millis();
  }

  // if the button is not pressed, make motors run at full speed
  else if (reading == LOW && prevState == HIGH) {
    if (goBackUp && (millis() - delayStart) <= 1000)
      servoZ.write(180);
    
      
    else
      servoZ.write(0);
  }

  prevState = reading; // make prevState the current state
}

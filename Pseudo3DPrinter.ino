// Include the Servo library
#include <Servo.h>

// servo variables
int servoZPin = 3;
int servo2Pin = 5;
int servo3Pin = 6;
Servo servoZ, servo2, servo3;

// variables for servo logic
bool goDown = true;
bool goUp = true;
bool firstTimeGoingUp = true;

// variables for switch
int switchPinIn = 13;
bool atLimit;

// run this once
void setup() {
  // assign servos to pins
  servoZ.attach(servoZPin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);

  pinMode(switchPinIn, INPUT); // make this pin receive voltage
  Serial.begin(9600); // Prepare serial port to debug if needed
}

// run this repeatedly
void loop() {
  atLimit = digitalRead(switchPinIn) == LOW; // check current state of button

  // if bot should go up
  if (goUp){
    // if it is the first time going up, go up for 2s
    // else, go up for 25s
    servoZ.write(180);
    
    if (firstTimeGoingUp)
      delay(2000);
    else
      delay(25000);

    firstTimeGoingUp = !firstTimeGoingUp; // change firstTimeGoingUp to the opposite of the curent value
    goUp = false; // do not go up any more
    atLimit = true; // force button press to jumpstart going down
  }

  // if button is pressed/limit is reached, 
  // toggle between going down and going up
  if (atLimit){
    if (goDown)
      servoZ.write(0);

    else{
      // stop and wait for 2s
      servoZ.write(90);
      delay(2000);

      // go up for 2s to unpress the switch
      servoZ.write(180);
      delay(2000);

      goUp = true; // z-axis should go up now
    }
    
    goDown = !goDown; // change to opposite of current value
    delay(200); // delay to make sure a single press is not counted as hold
  }
}

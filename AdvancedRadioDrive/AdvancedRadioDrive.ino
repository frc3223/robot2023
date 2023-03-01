#include <MINDSi.h>
#include <Servo.h>

/***************************************************
/ Example provided by MINDS-i
/ Try checking out our arduino resource guide at
/ http://mindsieducation.com/programming-resources
/ Questions? Concerns? Bugs? email code@mymindsi.com
/
/ This example expects an ESC plugged into pin 4
/ A servo plugged into pin 5
/ and a radio plugged into pins 2 and 3
/***************************************************/

Servo steer, drive;
float driveOut, steerOut;
float driveIn, steerIn;

const int threshold = 1500;

int pin = 7;
unsigned long duration;

void setup() {
  drive.attach(4);
  steer.attach(5);

  //set the initial throttle/direction for the ESC/servo
  drive.write(90);
  steer.write(90);

  //delay 2 seconds for arming
  delay(2000);
}

void loop() {
  duration = pulseIn(pin, HIGH);
  if (duration < 1500) {
    radioControl();
  } else if (duration > 1500){
    drive.write(100);
    lineFollow();
  }
}

void pulse() {
  duration = pulseIn(pin, HIGH);
  Serial.println(duration);
  delay(500);
}


void radioControl() {
  //exponential running average of radio signals to reduce noise
  driveIn = (driveIn * .6) + (getRadio(2) * .4);
  steerIn = (steerIn * .6) + (getRadio(3) * .4);

  driveOut = driveIn - 90;
  steerOut = steerIn - 90;
  driveOut = driveOut * driveOut * driveOut / 8100; //cubic motor curve
  steerOut = steerOut * steerOut * steerOut / 8100; //8100 = 90^2
  driveOut += 90;
  steerOut += 90;

  //deadbands to hold steady at center
  if ((driveOut > 95 || driveOut < 85)) {
    drive.write(driveOut);
  } else {
    drive.write(90);
  }

  if (steerOut > 95 || steerOut < 85) {
    steer.write(steerOut);
  } else {
    steer.write(90);
  }
}

void lineFollow() {

 if (QTI(A0) > threshold) {
    steer.write(45);
  } else if (QTI(A1) > threshold) {
    steer.write(90);
  } else if (QTI(A2) > threshold) {
    steer.write(135);
  }
}

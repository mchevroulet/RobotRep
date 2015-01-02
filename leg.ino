/*
 Leg control sketch
 
 Created Dec 21st 2014
 by Michel Chevroulet
  
 Expect a leg to be controlled by two servos (knee and hip)
*/

//servo library call (sets counters)
#include <Servo.h>

Servo myServo1; //Left Hip
Servo myServo2; //Right Knee
Servo myServo3; //Right Hip

void mountRightLeg(int servoKnee, int servoHip){
  //attach two servos to create right leg
  myServo2.attach(servoKnee);
  myServo2.write(90);
  myServo3.attach(servoHip);
  myServo3.write(90);
}

void mountLeftLeg(int servoKnee, int servoHip){
  //attach two servos to create left leg (knee not yet available)
  //myServo0.attach(servoKnee);
  //myServo0.write(90);
  myServo1.attach(servoHip);
  myServo1.write(90);
}

void setRightLeg(int knee, int hip){
  //directly set leg position
  myServo2.write(knee);
  myServo3.write(hip);  
}

void setLeftLeg(int knee, int hip){
  //directly set leg position
  //myServo0.write(knee);
  myServo1.write(hip);  
}

void rollRightLeg(){
  //move right leg to make a step
  setRightLeg(90, 90);
  delay(200);
  setRightLeg(45, 90);
  delay(100);
  setRightLeg(10, 170);
  delay(250);
  setRightLeg(45, 90);
  delay(100);
  setRightLeg(90, 90);
}

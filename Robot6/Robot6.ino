//
// Robot1A
//
// RobotTestFirmware
//
// Author 		michel
// 				MCh_Home
//
// Date			02.01.15 13:11
// Version		0v0
//
// Copyright	© michel, 2015 
// Licence		"All Rights Reserved"
//
// See         ReadMe.txt for references
//


// Include application, user and local libraries
#include <Servo.h>
#include "MChButton.h"
#include "MChLeg.h"
#include "MChSM.h"


// pin connections
const int buttonIndex = 2; //pin for button
const int greenLed = 3;//pin for green Led
const int yellowLed = 4;//pin for yellow Led
const int redLed = 5;//pin for red Led
const int servoPin1 = 9;//pin for servo
const int servoPin2 = 10;//pin for servo
const int servoPin3 = 11;//pin for servo
const int servoPin4 = 6;//pin for servo

//Input stuff
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete



//define persitent objects
MChButton theButton(buttonIndex); // declare the switch pin as an input
MChLeg rightLeg; // declare right leg 
MChLeg leftLeg;  // declare left leg

//build state machine
MChStateMachine myStateMachine;

//list states
#define END_MIN 0
#define END_MAX 180
#define MID_MIN 00
#define MID_MAX 90
#define M180(a) (180 - a)

void State0(){
    digitalWrite(greenLed, HIGH); // turn the green LED on pin 3 on
    digitalWrite(yellowLed, LOW);  // turn the red LED on pin 4 off
    digitalWrite(redLed, LOW);  // turn the red LED on pin 5 off
    leftLeg.setLeg(END_MIN, MID_MIN); // set leg to 0°
    rightLeg.setLeg(M180(END_MAX), M180(MID_MAX)); //set leg to 0°
}
void State1(){
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    leftLeg.setLeg(END_MAX, MID_MIN);
    rightLeg.setLeg(M180(END_MIN), M180(MID_MAX));
}
void State2(){
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    leftLeg.setLeg(END_MAX, MID_MAX);
    rightLeg.setLeg(M180(END_MIN), M180(MID_MIN));
}
void State3(){
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, HIGH);
    leftLeg.setLeg(END_MIN, MID_MAX);
    rightLeg.setLeg(M180(END_MAX), M180(MID_MIN));
}
void State4(){
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    rightLeg.setLeg(END_MIN, MID_MIN);
    leftLeg.setLeg(M180(END_MAX), M180(MID_MIN));
}


// Setup phase
//
// Brief assign functions to pins and create objects
// Details tbd
//
void setup(){
    // say hello
    Serial.begin(9600);
    Serial.println("Robot6 started");
  
    // declare the LED pins as outputs
    pinMode(greenLed,OUTPUT);
    pinMode(yellowLed,OUTPUT);
    pinMode(redLed,OUTPUT);
    
    leftLeg.assignLeg(servoPin2, servoPin1); //right end-center
    rightLeg.assignLeg(servoPin3, servoPin4); //left end-center 
    
    MChSMState myState;
    myState.stateId = 0;
    myState.stateAction = &State0;
    myStateMachine.addState(myState);
    myState.stateId = 1;
    myState.stateAction = &State1;
    myStateMachine.addState(myState);
    myState.stateId = 2;
    myState.stateAction = &State2;
    myStateMachine.addState(myState);
    myState.stateId = 3;
    myState.stateAction = &State3;
    myStateMachine.addState(myState);
    myState.stateId = 4;
    myState.stateAction = &State4;
    myStateMachine.addState(myState);
    myStateMachine.setState(0);

}

// Loop phase
//
// Brief call functions on infinite loop
// Details tbd
//
void loop(){
    
    //check if there is an event, if there is one increment state machine counter and mark event done
    if (theButton.buttonEventGet()==true) {
        myStateMachine.incrementState();
    }
    
    delay(10);
    if (stringComplete) {
        if (inputString == "next\n"){
          myStateMachine.incrementState();
        }
        Serial.println(inputString); 
        // clear the string:
        inputString = "";
        stringComplete = false;
    }

}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}



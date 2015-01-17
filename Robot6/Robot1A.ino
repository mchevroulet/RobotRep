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


// pin connections
const int buttonIndex = 2; //pin for button
const int greenLed = 3;//pin for green Led
const int yellowLed = 4;//pin for yellow Led
const int redLed = 5;//pin for red Led
const int servoPin1 = 9;//pin for servo
const int servoPin2 = 10;//pin for servo
const int servoPin3 = 11;//pin for servo


//define persitent objects
MChButton theButton(buttonIndex); // declare the switch pin as an input
MChLeg rightLeg; // declare right leg 
MChLeg leftLeg;  // declare left leg


// Setup phase
//
// Brief assign functions to pins and create objects
// Details tbd
//
void setup(){
    // say hello
    Serial.begin(9600);
    Serial.println("Robot1A started");
  
    // declare the LED pins as outputs
    pinMode(greenLed,OUTPUT);
    pinMode(yellowLed,OUTPUT);
    pinMode(redLed,OUTPUT);
    
    leftLeg.assignLeg(0, servoPin1); //right knee - hip
    rightLeg.assignLeg(servoPin2, servoPin3); //right knee - hip 

}

// Loop phase
//
// Brief call functions on infinite loop
// Details tbd
//
void loop(){
    
    //state machine counter (persistant)
    static int machinestate = 0;
    const int machinestateMax = 4; //max statemachine
    const int machinestateMax1 = machinestateMax+1; //max statemachine for modulo counting

    //check if there is an event, if there is one increment state machine counter and mark event done
    //statemachine counter is limited for machinestateMac (modulus)
    if (theButton.buttonEventGet()==true) {
        machinestate = ++machinestate % machinestateMax1;
    }
    
    // set LEDs according to state
    switch (machinestate) {
        case 0:{
            digitalWrite(greenLed, HIGH); // turn the green LED on pin 3 on
            digitalWrite(yellowLed, LOW);  // turn the red LED on pin 4 off
            digitalWrite(redLed, LOW);  // turn the red LED on pin 5 off
            leftLeg.setLeg(10, 10); // set leg to 0°
            rightLeg.setLeg(10, 10); //set leg to 0°
            break;
        }
        case 1:{
            digitalWrite(greenLed, HIGH);
            digitalWrite(yellowLed, HIGH);
            digitalWrite(redLed, LOW);
            leftLeg.setLeg(45, 45);
            rightLeg.setLeg(45, 45);
            break;
        }
        case 2:{
            digitalWrite(greenLed, LOW);
            digitalWrite(yellowLed, HIGH);
            digitalWrite(redLed, LOW);
            leftLeg.setLeg(90, 90);
            rightLeg.rollLeg(); //long roll of leg
            break;
        }
        case 3:{
            digitalWrite(greenLed, LOW);
            digitalWrite(yellowLed, HIGH);
            digitalWrite(redLed, HIGH);
            leftLeg.setLeg(90, 90);
            rightLeg.setLeg(90,90);
            break;
        }
        case 4:{
            digitalWrite(greenLed, LOW);
            digitalWrite(yellowLed, LOW);
            digitalWrite(redLed, HIGH);
            leftLeg.setLeg(170, 170);
            rightLeg.setLeg(170, 170);
            break;
        }
        default:{ // detect if I did it wrong :-)
            digitalWrite(greenLed, HIGH); 
            digitalWrite(yellowLed, HIGH); 
            digitalWrite(redLed, HIGH);  
        }
    }
    delay(10);
}

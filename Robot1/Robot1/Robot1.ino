//
// Robot1
//
// RobotTestFirmware
// Developed with [embedXcode](http://embedXcode.weebly.com)
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


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#include "Arduino.h"
#elif defined(SPARK) // Spark specific
#include "application.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#include "MChButton.h"
#include "MChLeg.h"

// Define variables and constants
//
// Brief	Name of the LED
// Details	Each board has a LED but connected to a different pin
//
uint8_t myLED;

// pin connections
const int buttonIndex = 2; //pin for button
const int greenLed = 3;//pin for green Led
const int yellowLed = 4;//pin for yellow Led
const int redLed = 5;//pin for red Led
const int servoPin1 = 9;//pin for servo
const int servoPin2 = 10;//pin for servo
const int servoPin3 = 11;//pin for servo
//state machine counter (persistant)
int machinestate = 0;
const int machinestateMax = 4; //max statemachine
const int machinestateMax1 = machinestateMax+1; //max statemachine for modulo counting


// Setup phase
//
// Brief assign functions to pins and create objects
// Details tbd
//
void setup(){
    // declare the LED pins as outputs
    pinMode(greenLed,OUTPUT);
    pinMode(yellowLed,OUTPUT);
    pinMode(redLed,OUTPUT);
    
    // declare the switch pin as an input
    /*pinMode(buttonIndex,INPUT);*/
    MChButton theButton(buttonIndex);
    
    // attach pin to servo object
    /*
    mountLeftLeg(0, servoPin1);  //knee - hip (no knee yet)
    mountRightLeg(servoPin2, servoPin3);  //knee - hip */
    MChLeg leftLeg(0, servoPin1);
    MChLeg rightLeg(servoPin2, servoPin3);
}

// Loop phase
//
// Brief call functions on infinite loop
// Details tbd
//
void loop(){
    
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
            leftLeg.setLeg(0, 0); //set leg to 0°
            rightLeg.setLeg(0, 0); //set leg to 0°
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
            rightLeg.rollLeg();
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
            leftLeg.setLeg(180, 180);
            rightLeg.setLeg(180, 180);
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

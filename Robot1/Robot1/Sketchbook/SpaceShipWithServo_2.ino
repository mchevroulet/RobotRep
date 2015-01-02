/*
 Sequencial LEDs lighting on button pressed
 Activating 3 servos in parallel with LED lighting
 
 Created Dec 15th 2014
 by Michel Chevroulet
  
 Derived form 
  Arduino Starter Kit example
  Project 2  - Spaceship Interface
  by Scott Fitzgerald
*/

//leg control file
#include <leg>
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
//click event manager (persistent)
int buttonClick = false;
int buttonClickServed = false;

int buttonDown(){
  // read button switch
  if (digitalRead(buttonIndex) == true){
    return true;
  } else{
    return false;
  }
}

void buttonEventCheck(){
  //clear button event if it was served and if button is not pressed anymore
  //don't forget to use buttonEventServed() to indicate when the event was served
  if ((buttonClickServed == true) and (buttonDown() == false)) {
    buttonClick = false;
    buttonClickServed = false;  
  }  
  //read button to detect new event
  if ((buttonClick == false) and (buttonDown() == true)){
    buttonClick = true;
    buttonClickServed = false;
  }
}

int buttonEvent(){
  //check is there is a button event to be served
  if ((buttonClick == true) and (buttonClickServed == false)){
    return true;
  } 
  else {
    return false;
  }
}

void buttonEventServed(){
  //inform that button event was served
  buttonClickServed = true;
}

int buttonEventGet(){
  //global function checking for event and serving it
  buttonEventCheck();
  if (buttonEvent()==true){
    buttonEventServed();
    return true;
  }
  else{
    return false;
  }
}

void setup(){
  // declare the LED pins as outputs 
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);

  // declare the switch pin as an input   
  pinMode(buttonIndex,INPUT);
  
  // attach pin to servo object
  mountLeftLeg(0, servoPin1);  //knee - hip (no knee yet)
  mountRightLeg(servoPin2, servoPin3);  //knee - hip
}

void loop(){

/*
// read the value of the switch
  // checks to see if there is voltage
  // on the pin or not  
  buttonEventCheck();
  
  // if the switch is pressed, go to next state
  // and inform event that it is served
  if (buttonEvent() == true){
    ++machinestate;
    if (machinestate > machinestateMax) {
      machinestate = 0;
    }
    buttonEventServed();
  }
*/

  //check if there is an event, if there is one increment state machine counter and mark event done
  //statemachine counter is limited for machinestateMac (modulus)
  if (buttonEventGet()==true) {
    machinestate = ++machinestate % machinestateMax1;
  }  
  
  // set LEDs according to state  
  switch (machinestate) {
    case 0:{
      digitalWrite(greenLed, HIGH); // turn the green LED on pin 3 on
      digitalWrite(yellowLed, LOW);  // turn the red LED on pin 4 off
      digitalWrite(redLed, LOW);  // turn the red LED on pin 5 off
      setLeftLeg(0, 0); //set leg to 0°
      setRightLeg(0, 0); //set leg to 0°
      break;
    }
    case 1:{    
      digitalWrite(greenLed, HIGH); 
      digitalWrite(yellowLed, HIGH);  
      digitalWrite(redLed, LOW);
      setLeftLeg(45, 45);
      setRightLeg(45, 45);
     break; 
    }
    case 2:{    
      digitalWrite(greenLed, LOW); 
      digitalWrite(yellowLed, HIGH);  
      digitalWrite(redLed, LOW);
      setLeftLeg(90, 90);
      rollRightLeg();
     break; 
    }
    case 3:{    
      digitalWrite(greenLed, LOW); 
      digitalWrite(yellowLed, HIGH);  
      digitalWrite(redLed, HIGH);
      setLeftLeg(90, 90);
      setRightLeg(90,90);
     break; 
    }
    case 4:{
      digitalWrite(greenLed, LOW); 
      digitalWrite(yellowLed, LOW); 
      digitalWrite(redLed, HIGH);  
      setLeftLeg(180, 180);
      setRightLeg(180, 180);
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


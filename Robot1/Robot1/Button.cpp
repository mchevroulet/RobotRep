//
//  Button.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "Button.h"

Button::Button(int index){
    buttonIndex = index;
    pinMode(buttonIndex,INPUT);
    buttonClick = false;
    buttonClickServed = false;
}

Button::~Button(){
}

int Button::buttonDown(){
    // read button switch
    if (digitalRead(buttonIndex) == true){
        return true;
    } else{
        return false;
    }
}

void Button::buttonEventCheck(){
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

int Button::buttonEvent(){
    //check is there is a button event to be served
    if ((buttonClick == true) and (buttonClickServed == false)){
        return true;
    }
    else {
        return false;
    }
}

void Button::buttonEventServed(){
    //inform that button event was served
    buttonClickServed = true;
}

int Button::buttonEventGet(){
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


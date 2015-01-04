//
//  Button.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "MChButton.h"

MChButton::MChButton(int index){
    this->buttonIndex = index;
    pinMode(this->buttonIndex,INPUT);
    this->buttonClick = false;
    this->buttonClickServed = false;
}

MChButton::~MChButton(){
}

int MChButton::buttonDown(){
    // read button switch
    if (digitalRead(this->buttonIndex) == true){
        return true;
    } else{
        return false;
    }
}

void MChButton::buttonEventCheck(){
    //clear button event if it was served and if button is not pressed anymore
    //don't forget to use buttonEventServed() to indicate when the event was served
    if ((this->buttonClickServed == true) and (this->buttonDown() == false)) {
        this->buttonClick = false;
        this->buttonClickServed = false;
    }
    //read button to detect new event
    if ((this->buttonClick == false) and (this->buttonDown() == true)){
        this->buttonClick = true;
        this->buttonClickServed = false;
    }
}

int MChButton::buttonEvent(){
    //check is there is a button event to be served
    if ((this->buttonClick == true) and (this->buttonClickServed == false)){
        return true;
    }
    else {
        return false;
    }
}

void MChButton::buttonEventServed(){
    //inform that button event was served
    this->buttonClickServed = true;
}

int MChButton::buttonEventGet(){
    //global function checking for event and serving it
    this->buttonEventCheck();
    if (this->buttonEvent()==true){
        this->buttonEventServed();
        return true;
    }
    else{
        return false;
    }
}


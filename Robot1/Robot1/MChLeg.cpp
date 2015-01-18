//
//  Leg.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "MChLeg.h"

// Servo objects are created by MChLeg class when an object of the class is created
// Servo objects are assigned a pin by MChLeg::MChLeg constructor
// Servo pin is detached by MChLeg::~MChLeg destructor
// Servo objects are set to a 90 initial position (mid-range)

MChLeg::MChLeg(int x, int y){
    this->kneeIndex = x;
    this->hipIndex = y;
    if (this->kneeIndex != 0) {
        this->kneeServo.attach(this->kneeIndex);
        this->kneeServo.write(90);
    }
    if (this->hipIndex != 0) {
        this->hipServo.attach(this->hipIndex);
        this->hipServo.write(90);
    }
}

MChLeg::~MChLeg(){
    if (this->kneeIndex != 0) {
        this->kneeServo.detach();
    }
    if (this->hipIndex != 0) {
        this->hipServo.detach();
    }
}

void MChLeg::setLeg(int x, int y){
    this->kneeAngle = x;
    this->hipAngle = y;
    if (this->kneeIndex != 0) {
        this->kneeServo.write(this->kneeAngle);
    }
    if (this->hipIndex != 0) {
        this->hipServo.write(this->hipAngle);
    }
}

void MChLeg::rollLeg(){
    //move leg to make a step
    this->setLeg(90, 90);
    delay(200);
    this->setLeg(45, 90);
    delay(100);
    this->setLeg(10, 170);
    delay(250);
    this->setLeg(45, 90);
    delay(100);
    this->setLeg(90, 90);
}

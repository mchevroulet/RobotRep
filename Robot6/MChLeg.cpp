//
//  Leg.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "MChLeg.h"

// Servo objects are created by MChLeg class when an object of the class is created
// Servo objects are assigned a pin by MChLeg::assignLeg (connot be in constructor, I don't know why)
// Servo pin is detached by MChLeg::~MChLeg destructor
// Servo objects position is 0 - 180 degrees on regular servos

const int cMChLegServoMin = 600; //default is 544
const int cMChLegServoMax = 2400; //default is 2400

MChLeg::MChLeg(){
    this->kneeIndex = 0;
    this->hipIndex = 0;
}

MChLeg::~MChLeg(){
    if (this->kneeIndex != 0) {
        this->kneeServo.detach();
    }
    if (this->hipIndex != 0) {
        this->hipServo.detach();
    }
}

void MChLeg::assignLeg(int x, int y){
    if (this->kneeIndex != 0) {
        this->kneeServo.detach();
    }
    if (this->hipIndex != 0) {
        this->hipServo.detach();
    }
    this->kneeIndex = x;
    this->hipIndex = y;
    if (this->kneeIndex != 0) {
        this->kneeServo.attach(this->kneeIndex, cMChLegServoMin, cMChLegServoMax);
    }
    if (this->hipIndex != 0) {
        this->hipServo.attach(this->hipIndex, cMChLegServoMin, cMChLegServoMax);
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

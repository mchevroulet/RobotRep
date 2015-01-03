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
    kneeIndex = x;
    hipIndex = y;
    if (kneeIndex != 0) {
        kneeServo.attach(kneeIndex);
        kneeServo.write(90);
    }
    if (hipIndex != 0) {
        hipServo.attach(hipIndex);
        hipServo.write(90);
    }
}

MChLeg::~MChLeg(){
    if (kneeIndex != 0) {
        kneeServo.detach();
    }
    if (hipIndex != 0) {
        hipServo.detach();
    }
}

void MChLeg::setLeg(int x, int y){
    kneeAngle = x;
    hipAngle = y;
    if (kneeIndex != 0) {
        kneeServo.write(kneeAngle);
    }
    if (hipIndex != 0) {
        hipServo.write(hipAngle);
    }
}

void MChLeg::rollLeg(){
    //move leg to make a step
    setLeg(90, 90);
    delay(200);
    setLeg(45, 90);
    delay(100);
    setLeg(10, 170);
    delay(250);
    setLeg(45, 90);
    delay(100);
    setLeg(90, 90);
}

//
//  Leg.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "Leg.h"

void Leg::Leg(int x, int y): kneeServo(x), hipServo(y){
    kneeIndex = x;
    hipIndex = y;
    if (kneeIndex <> 0) {
        kneeServo.attach(kneeIndex);
    }
    if (hipIndex <> 0) {
        hipServo.attach(hipIndex);
    }
    setLeg(90, 90);
}

void Leg::~Leg(){
    if (kneeIndex <> 0) {
        kneeServo.detach();
    }
    if (hipIndex <> 0) {
        hipServo.detach();
    }
}

void Leg::setLeg(int x, int y){
    kneeAngle = x;
    hipAngle = y;
    if (kneeIndex <> 0) {
        kneeServo.write(kneeAngle);
    }
    if (hipIndex <> 0) {
        hipServo.write(hipAngle);
    }
}

void Leg::rollLeg(){
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

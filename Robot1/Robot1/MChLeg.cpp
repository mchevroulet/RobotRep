//
//  Leg.cpp
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "MChLeg.h"

void MChLeg::MChLeg(int, int){
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

void MChLeg::~MChLeg(){
    if (kneeIndex <> 0) {
        kneeServo.detach();
    }
    if (hipIndex <> 0) {
        hipServo.detach();
    }
}

void MChLeg::setLeg(int x, int y){
    kneeAngle = x;
    hipAngle = y;
    if (kneeIndex <> 0) {
        kneeServo.write(kneeAngle);
    }
    if (hipIndex <> 0) {
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

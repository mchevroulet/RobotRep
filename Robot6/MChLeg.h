//
//  MChLeg.h
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//



#ifndef MChLeg_h
#define MChLeg_h

#include <Arduino.h>
#include "Servo.h"


class MChLeg{
    int kneeIndex, hipIndex;
    int kneeAngle, hipAngle;
    Servo kneeServo; 
    Servo hipServo;
  public:
    MChLeg();
    ~MChLeg();
    void assignLeg(int, int); // (knee servo index, hip servo index); use 0 if no servo
    void setLeg(int, int); // (knee angle, hip angle); in degrees, 0-180, 90 is straight
    void rollLeg();
};

#endif // end #ifndef MChLeg_h


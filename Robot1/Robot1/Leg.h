//
//  Leg.h
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#ifndef Robot1_Leg_h
#define Robot1_Leg_h



#endif

#include <Servo.h>

class Leg{
    int kneeIndex, hipIndex;
    int kneeAngle, hipAngle;
    Servo kneeServo, hipServo;
  public:
    Leg(int, int); // knee servo index, hip servo index, use 0 if no servo
    ~Leg();
    void setLeg(int, int); // knee angle, hip angle, in degrees, 90 is straight
    void rollLeg();
};
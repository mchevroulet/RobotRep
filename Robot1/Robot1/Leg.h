//
//  Leg.h
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#include "Arduino.h"
#elif defined(SPARK) // Spark specific
#include "application.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

#ifndef Robot1_Leg_h
#define Robot1_Leg_h



#endif

#include <Servo.h>

class Leg{
    int kneeIndex, hipIndex;
    int kneeAngle, hipAngle;
    Servo kneeServo; 
    Servo hipServo;
  public:
    Leg(int x, int y): kneeServo(x), hipServo(y); // (knee servo index, hip servo index); use 0 if no servo
    ~Leg();
    void setLeg(int, int); // (knee angle, hip angle); in degrees, 0-180, 90 is straight
    void rollLeg();
};

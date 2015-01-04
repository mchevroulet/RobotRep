//
//  Button.h
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//


#ifndef MChButton_h
#define MChButton_h


#include <Arduino.h>


class MChButton{
    int buttonClick, buttonClickServed;
    int buttonIndex;
  public:
    MChButton(int);
    ~MChButton();
    int buttonDown();
    void buttonEventCheck();
    int buttonEvent();
    void buttonEventServed();
    int buttonEventGet();
};

#endif  //#ifndef MChButton_h

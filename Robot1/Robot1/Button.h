//
//  Button.h
//  Robot1
//
//  Created by michel on 02.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#ifndef Robot1_Button_h
#define Robot1_Button_h



#endif

class Button{
    int buttonClick, buttonClickServed;
    int buttonIndex;
  public:
    Button(int);
    ~Button();
    int buttonDown();
    void buttonEventCheck();
    int buttonEvent();
    void buttonEventServed();
    int buttonEventGet();
};
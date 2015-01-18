//
//  MChSM.h
//  Robot1
//
//  Created by michel on 18.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//


#ifndef MChSM_h
#define MChSM_h

#include <Arduino.h>
#include "MChLeg.h" //for the actions

const int MChmachinestateMax = 5; //max statemachine
const int MChmachinestateMax1 = MChmachinestateMax+1; //max statemachine for modulo counting

struct MChSMState{
  int stateId;
  void (*stateAction)(); //pointer to function for state
};
    

class MChStateMachine{
public:
    MChStateMachine();
    ~MChStateMachine();
    void setState(int);
    int getState();
    void incrementState();
    void addState(MChSMState state);
private:    
    int machinestate;
    MChSMState machinestates [MChmachinestateMax1];
    void doState();
};

#endif MChSM_h

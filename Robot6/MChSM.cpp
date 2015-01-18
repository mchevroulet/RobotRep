//
//  MChSM.cpp
//  Robot1
//
//  Created by michel on 18.01.15.
//  Copyright (c) 2015 MCh_Home. All rights reserved.
//

#include "MChSM.h"

MChStateMachine::MChStateMachine(){
}

MChStateMachine::~MChStateMachine(){
}

int MChStateMachine::getState(){
  return this->machinestate;
}

void MChStateMachine::setState(int newState){
  this->machinestate = newState;
  this->doState();
}

void MChStateMachine::incrementState(){
    this->setState((this->getState() + 1) % MChmachinestateMax);
}

void MChStateMachine::addState(MChSMState state){
  if ((state.stateId >= 0)&&(state.stateId < MChmachinestateMax)){
    this->machinestates[state.stateId] = state;
  }
}

void MChStateMachine::doState(){
    // set LEDs according to state
    void (*action)();
    action = this->machinestates[machinestate].stateAction;
    (*action)();
}


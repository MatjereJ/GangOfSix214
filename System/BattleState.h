//
// Created by JOHANES MATSEBA on 2022/10/26.
//

#ifndef PROJECTASSIGNMENT_BATTLESTATE_H
#define PROJECTASSIGNMENT_BATTLESTATE_H
#include "IndividualCountry.h"
#include <iostream>


using namespace std;

class BattleState {
public:
    BattleState();
    BattleState *successor;
    void Add(BattleState *Succ);
    virtual void handleChange(IndividualCountry *C);
};


#endif //PROJECTASSIGNMENT_BATTLESTATE_H

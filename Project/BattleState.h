#ifndef BattleState_h
#define BattleState_h
#include "Country.h"

class BattleState
{

public:
    BattleState();
    BattleState *successor;
    void Add(BattleState *Succ);
    virtual void handleChange(Country *C);
};

#endif
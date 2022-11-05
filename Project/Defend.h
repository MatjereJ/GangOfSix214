#ifndef Defend_h
#define Defend_h
#include "BattleState.h"

class Defend : public BattleState
{
public:
    void handleChange(Country *C);
    void TakeChance(Country *C);
};
#endif
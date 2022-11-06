#ifndef Surrender_h
#define Surrender_h
#include "BattleState.h"


class Surrender : public BattleState
{
public:
    void handleChange(IndividualCountry *C);
};
#endif
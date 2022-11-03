#ifndef RequestAlliance_h
#define RequestAlliance_h
#include "BattleState.h"

class RequestAlliance : public BattleState
{
public:
    void handleChange(Country *C);
};
#endif
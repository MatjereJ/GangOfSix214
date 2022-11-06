#ifndef AttackStrategy_h
#define AttackStrategy_h
#include "IndividualCountry.h"

class AttackStrategy
{
public:
    virtual void LaunchAttack(IndividualCountry *C) = 0;
};
#endif
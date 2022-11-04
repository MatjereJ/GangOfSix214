#ifndef AttackStrategy_h
#define AttackStrategy_h
#include "Country.h"

class AttackStrategy
{
public:
    virtual void LaunchAttack(Country *C) = 0;
};
#endif
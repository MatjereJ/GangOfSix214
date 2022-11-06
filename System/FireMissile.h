#ifndef FireMissile_h
#define FireMissile_h
#include "AttackStrategy.h"
#include <vector>
#include <iostream>

class FireMissile : public AttackStrategy
{
public:
    void LaunchAttack(IndividualCountry *C);
};

#endif
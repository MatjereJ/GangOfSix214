#ifndef FireMissile_h
#define FireMissile_h
#include "AttackStrategy.h"
#include <list>
#include <iostream>

class FireMissile : public AttackStrategy
{
public:
    void LaunchAttack(Country *C);
};

#endif
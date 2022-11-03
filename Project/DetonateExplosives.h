#ifndef DetonateExplosives_h
#define DetonateExplosives_h
#include "AttackStrategy.h"
#include <list>
#include <iostream>

class DetonateExplosives : public AttackStrategy
{
public:
    void LaunchAttack(Country *C);
};

#endif
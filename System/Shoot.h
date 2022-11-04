#ifndef Shoot_h
#define Shoot_h
#include "AttackStrategy.h"
#include <list>
#include <iostream>

class Shoot : public AttackStrategy
{
public:
    void LaunchAttack(Country *C);
};

#endif
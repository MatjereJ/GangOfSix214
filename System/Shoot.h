#ifndef Shoot_h
#define Shoot_h
#include "AttackStrategy.h"
#include <list>
#include <iostream>

class Shoot : public AttackStrategy
{
public:
    Shoot();
    /***
     * @brief Totals the amount of Rifleman and MachineGunners a country has and decreases that damage from opposing countries hp
     * @param C IndividualCountry Pointer that will be used to see what weaponary country has
     */
    void LaunchAttack(IndividualCountry *C);
};

#endif
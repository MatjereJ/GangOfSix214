#ifndef FireMissile_h
#define FireMissile_h
#include "AttackStrategy.h"
#include <vector>
#include <iostream>

class FireMissile : public AttackStrategy
{
public:
    FireMissile();
    /***
     * @brief Totals the amount of missiles,aircrafts and warships a country has and decreases that damage from opposing countries hp
     * @param C IndividualCountry Pointer that will be used to see what weaponary country has
     */
    void LaunchAttack(IndividualCountry *C);
};

#endif
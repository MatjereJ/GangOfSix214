#ifndef DetonateExplosives_h
#define DetonateExplosives_h
#include "AttackStrategy.h"
#include <list>
#include <iostream>

/***
 * @brief inherits from AttackStrategy
 */

class DetonateExplosives : public AttackStrategy
{
public:
    DetonateExplosives();
    /***
     * @brief Totals the amount of bombs country has and decreases that damage from opposing countries hp
     * @param C IndividualCountry Pointer that will be used to seee what weaponary country has
     */
    void LaunchAttack(IndividualCountry *C);
};

#endif
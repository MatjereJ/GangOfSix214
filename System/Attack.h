#ifndef Attack_h
#define Attack_h
#include "BattleState.h"
#include "DetonateExplosives.h"
#include "Shoot.h"
#include "FireMissile.h"
#include "Context.h"

#include "Country.h"
#include "WarParticipant.h"
/***
 * @brief one of the states
 * @details inherits from BattleStates
 */


class Attack : public BattleState
{
public:
    Attack();
    /***
     * @brief This function will implement attack functionality
     * @details The attack will use state design pattern by sending through context dependant on which weaponary the individual country has and will use that attackStrategy
     * @param C IndividualCountry pointer that will be used to get opposing countries HP and attack dependant on if C has a greater than or equal HP
     */
    void handleChange(IndividualCountry *C);
};
#endif
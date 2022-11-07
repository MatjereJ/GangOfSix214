#ifndef Defend_h
#define Defend_h
#include "BattleState.h"
#include "Country.h"

/***
 * @brief one of the states
 * @details inherits from BattleStates
 */

class Defend : public BattleState
{
public:
    Defend();
    /***
 * @brief Here defend states implements defend functionailty
 * @details The defend state will cause the country to either stay put and do nothing or attack and take a chance in which its attack will be much stronger than a normal attack
     * @param C Individual Country that will defend dependant on its hp
 */
    void handleChange(IndividualCountry *C) override;
};
#endif
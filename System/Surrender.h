#ifndef Surrender_h
#define Surrender_h
#include "BattleState.h"

/***
 * @brief one of the states
 * @details inherits from BattleStates
 */

class Surrender : public BattleState
{
public:
    Surrender();
    /***
* @brief Here defend states implements defend functionalty
* @details The surrender state will cause the country to surrender
    * @param C Individual Country that will be used to access its opposing country. The opposing country will surrender if it has less than 100 hp
*/
    void handleChange(IndividualCountry *C);
};
#endif
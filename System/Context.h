#ifndef Context_h
#define Context_h
#include "AttackStrategy.h"

/***
 * @brief Context class used to pick which attack strategy indiviualCountries will use dependant on their machinery
 */
class Context
{
private:
    AttackStrategy *state;

public:
    Context(AttackStrategy *s);
    ~Context();
    /***
     * @brief instantiates state member variable
     * @param s AttackStrategy pointer that state will point to
     */
    void SetState(AttackStrategy *s);
    /***
     * @brief will implement which attackStrategy will be used dependant on countries machinery
     * @param C IndividualCountry pointer that will be used to check the type of machinery country has
     */
    void implement(IndividualCountry *C);
};

#endif
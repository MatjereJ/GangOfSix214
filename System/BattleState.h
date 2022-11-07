//
// Created by Andinda on 2022/10/26.
//

/***
 * @brief BattleState class that will deal with the different states currently will be in either defend,attack or surrender
 * @author Andinda Bakaianga
 */

#ifndef PROJECTASSIGNMENT_BATTLESTATE_H
#define PROJECTASSIGNMENT_BATTLESTATE_H
#include "IndividualCountry.h"
#include <iostream>


using namespace std;

class BattleState {
public:
    BattleState();
    BattleState *successor;
    /***
     * @brief Creating the chain of responsibility that will handle what state currently will be in
     * @param Succ is the BattleState pointer to be added to the chain of the other states
     */
    void Add(BattleState *Succ);
    /***
     * @brief Handles which state the country is going to and sends it through the chain to the right state
     * @param C is IndividualCountry pointer that will be handle by a state
     */
    virtual void handleChange(IndividualCountry *C);
};


#endif //PROJECTASSIGNMENT_BATTLESTATE_H

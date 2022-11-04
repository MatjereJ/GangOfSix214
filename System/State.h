//
// Created by JOHANES MATSEBA on 2022/10/29.
//

#ifndef PROJECTASSIGNMENT_STATE_H
#define PROJECTASSIGNMENT_STATE_H

#include <list>
#include "WarParticipant.h"
#include "WarTheatre.h"
#include "BattleState.h"
#include "CountryObserver.h"
#include "Sea.h"
#include "AirSpace.h"
#include "Land.h"
#include <iostream>
#include <cstdlib>
#include "time.h"

#include <vector>


using namespace std;
class Country;
class State {

public:
    State(int,BattleState*, WarTheatre*,vector<WarParticipant*>,vector<CountryObserver*>,Country*,bool);
    int getHP(){return hp;};
    BattleState* getBattleState(){ return battlestate;};
    WarTheatre* getWarTheatre(){return warTheatre;};
    vector<WarParticipant*> getWarParticipants(){return warParticipants;};
    vector<CountryObserver*> getCountryObservers(){return countryObservers;};
    Country* getOppCountry(){return opposingCountry;};
    bool getW(){return win;};
private:
    int hp;
    BattleState* battlestate;
    WarTheatre* warTheatre;
    std::vector<WarParticipant*> warParticipants;
    std::vector<CountryObserver*> countryObservers;
    Country* opposingCountry;
    bool win=false;
};


#endif //PROJECTASSIGNMENT_STATE_H

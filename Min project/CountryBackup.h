//
// Created by JOHANES MATSEBA on 2022/10/24.
//

#ifndef PROJECTASSIGNMENT_COUNTRYBACKUP_H
#define PROJECTASSIGNMENT_COUNTRYBACKUP_H
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
//#include "Country.h"
#include "State.h"
#include <vector>

using namespace std;
class CountryBackup {
private:
    friend class Country;
    int hp;
    State* state;
    Country* opposingCountry;
    BattleState* battleState;
    WarTheatre* warTheatre;
    std::vector<WarParticipant*> warParticipants;
    std::vector<CountryObserver*> countryObservers;
    bool win;

public:
    CountryBackup(int,BattleState*, WarTheatre*,vector<WarParticipant*>,vector<CountryObserver*>,Country*,bool);
    BattleState* getBattleState();
    WarTheatre* getWarTheatre();
    WarParticipant* getWarParticipants();
    CountryObserver* getCountryObservers();
    virtual ~CountryBackup();
};


#endif //PROJECTASSIGNMENT_COUNTRYBACKUP_H

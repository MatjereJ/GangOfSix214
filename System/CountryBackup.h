//
// Created by JOHANES MATSEBA on 2022/10/24.
//

#ifndef PROJECTASSIGNMENT_COUNTRYBACKUP_H
#define PROJECTASSIGNMENT_COUNTRYBACKUP_H
#include <list>
#include "WarParticipant.h"
#include "WarTheatre.h"
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
    friend class IndividualCountry;
    int hp;
    State* state;
    IndividualCountry* opposingCountry;
    WarTheatre* warTheatre;
    std::vector<WarParticipant*> warParticipants;
    std::vector<CountryObserver*> countryObservers;
    bool win;

public:
    CountryBackup(int, WarTheatre*,vector<WarParticipant*>,vector<CountryObserver*>,IndividualCountry*,bool);
    WarTheatre* getWarTheatre();
    WarParticipant* getWarParticipants();
    CountryObserver* getCountryObservers();
    State* getState() {
        return state;
    }
    IndividualCountry* getOppCountry() {
        return opposingCountry;
    }
    virtual ~CountryBackup();
};


#endif //PROJECTASSIGNMENT_COUNTRYBACKUP_H

//
// Created by JOHANES MATSEBA on 2022/10/24.
//

#include "CountryBackup.h"

CountryBackup::CountryBackup(int HP, WarTheatre *wT, vector<WarParticipant *> participants, vector<CountryObserver *>observers, IndividualCountry *opp, bool win) {
state=new State(HP,wT,participants,observers,opp,win);
}

CountryBackup::~CountryBackup() {
    delete state;
    state=0;
}
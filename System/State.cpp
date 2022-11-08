//
// Created by JOHANES MATSEBA on 2022/10/29.
//

#include "State.h"

State::State(int HP, WarTheatre *wT, vector<WarParticipant *> participants, vector<CountryObserver *>observers, IndividualCountry *opp, bool win) {
    hp=HP;
    warTheatre=wT;
    warParticipants=participants;
    countryObservers=observers;
    opposingCountry=opp;
    this->win=win;

}



//
// Created by JOHANES MATSEBA on 2022/10/29.
//

#include "State.h"

State::State(int HP, WarTheatre *wT, vector<WarParticipant *> participants, vector<CountryObserver *>observers, IndividualCountry *opp, bool win) {
    hp=HP;
    warTheatre=wT;
    for(int i=0;i<participants.size();i++){
        warParticipants[i]=participants[i];
    }

    for(int i=0;i<observers.size();i++){
        countryObservers[i]=observers[i];
    }

    opposingCountry=opp;
    this->win=win;
}



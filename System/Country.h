//
// Created by JOHANES MATSEBA on 2022/10/19.
//

#ifndef PROJECTASSIGNMENT_COUNTRY_H
#define PROJECTASSIGNMENT_COUNTRY_H
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
#include "CountryBackup.h"
#include <vector>
#include <string>

using namespace std;

class Country {
public:



    Country(std::string, bool);
    Country(Country *C);
    Country();
    virtual bool add(CountryObserver* c){return false;};
    virtual bool remove(CountryObserver* c){return false;};
    virtual void notify(){};
    virtual int getHp()=0;
    virtual ~Country(){};

private:

    vector<CountryObserver*> countryObservers;
    string name;

};


#endif //PROJECTASSIGNMENT_COUNTRY_H

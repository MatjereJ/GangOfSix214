#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include "Country.h"
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CountryObservers;
class  IndividualCountry: public Country{
     public:
        IndividualCountry();
        IndividualCountry(string name,int weaponHP,int soldiierHP,int transport);
        bool add(CountryObserver* c);
        bool remove(CountryObserver* c);
        void notify();
        string getName();
        int getWeaponHP();
        int getSoldierHP();
        int getTransport();
        int getSize();
        void setHP(int weaponHP,int soldierHP,int transport);
        void setAlliance( vector<IndividualCountry*> alliance);
        vector<IndividualCountry*> getAlliance();
    private:
        vector<CountryObserver*> countryObservers;
        vector<IndividualCountry*> alliance;
        int weaponHP;
        int soldierHP;
        int transport;
        int size;
        string name;
};
#endif
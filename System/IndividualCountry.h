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
        IndividualCountry(string name);
        bool add(CountryObserver* c);
        bool remove(CountryObserver* c);
        void notify();
        int getWeaponHP();
        void setWeaponHP(int v);
    private:
        vector<CountryObserver*> countryObservers;
       
        int weaponHP;
        int soldierHP;
        int transport;
        string name;
};
#endif
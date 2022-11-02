#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IndividualCountry: Country {//ConcreteSubject
    public:
        IndividualCountry();
        int getWeaponHP();
        int getSoldierHP();
        int getTransport();
        void setWeaponHP(int);
        void setSoldierHP(int);
        void setTransport(int);
    private:
        int weaponHP;
        int soldierHP;
        int transport;
        
};
#endif
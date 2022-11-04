#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CountryObserver {//Observer
    public:
     virtual void update(int weaponHP,int soldierHP,int transport)=0;
};
#endif
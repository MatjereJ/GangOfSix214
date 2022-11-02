#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class CountryObserver {//Observer
    public:
     virtual void update();
};
#endif
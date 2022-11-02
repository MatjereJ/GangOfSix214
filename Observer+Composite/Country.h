#ifndef COUNTRY_H
#define COUNTRY_H
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Country {//Subject
    public:
        bool add(CountryObserver* c);
        bool remove(CountryObserver* c);
        void notify();
    private:
     vector<CountryObserver*> countryObservers;
    
};
#endif
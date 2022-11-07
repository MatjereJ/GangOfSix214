#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CountryObserver {//Observer
    public:
    /**
        @brief Medics and ObservingAllies override and update country resources when they
               start to run low.
        @author Areyeng Mphahlele

        @return void
        @date  27/10/2022 
     
     */
     virtual void update()=0;
};
#endif
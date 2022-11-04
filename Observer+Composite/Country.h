#ifndef COUNTRY_H
#define COUNTRY_H
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Country 
{//Subject
    public:

        
        Country();
        virtual bool add(CountryObserver* c)=0;
        virtual bool remove(CountryObserver* c)=0;
        virtual void notify()=0;
        void setHp(int hp);
        int getHP();
        void updateHp(int);
        

    private:
        int hp; 
        string cName;
        
};
#endif
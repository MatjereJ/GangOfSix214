#include "Alliance.h"
#include "IndividualCountry.h"
#include "WarParticipant.h"
#include "AirCraft.h"
#include "AirSpace.h"
#include "Attack.h"
#include "Surrender.h"
#include "Attack.cpp"
#include "AttackStrategy.h"
#include "BattleState.h"
#include "Bomb.h"
#include "Context.h"
#include "Country.h"
#include "CountryBackup.h"
#include "CountryMemory.h"
#include "CountryObserver.h"
#include "CountryObserverIterator.h"
#include "Defend.h"
#include "DetonateExplosives.h"
#include "ExplosiveFactory.h"
#include "FireArmFactory.h"
#include "FireArmFactory.cpp"

#include <iostream>
using namespace std;

void initializeCountries();
void pickCountry();
void fight();
void selectOpposingCountry();
void getCountryStats(int cNum);
void endGame();

IndividualCountry *country[10];
IndividualCountry *myCountry;
int countryNum, countrySize = 2;

int main()
{
    cout << "***********     Game Simulation    ***************\n";
    initializeCountries();
    pickCountry();
    fight();
    endGame();
    return 0;
}

void initializeCountries()
{
    country[0] = new IndividualCountry("China", 1, false);
    country[1] = new IndividualCountry("Russia", 1, false);
    // And so on
}

void pickCountry()
{
    cout << "Select a Country from the list below by entering it's number" << endl;
    for (int i = 0; i < countrySize; i++)
    {
        cout << i << ": " << country[i] << endl;
    }
    cin >> countryNum;
    myCountry = country[countryNum];
}

void fight()
{
    selectOpposingCountry();
    Country *tempC = myCountry;
    BattleState *State = new BattleState();
    Attack *Att = new Attack;
    Defend *Def = new Defend;
    Surrender *surr = new Surrender;
    State->Add(Att);
    State->Add(Def);
    State->Add(surr);
    myCountry->setBattleState(State);
    Country *Opps = myCountry->getOpposingC();
    Opps->setBattleState(State);

    while (myCountry->getHp() > 0 && Opps->getHp() > 0)
    {
        State->handleChange(tempC);
        if (Opps->getHp() < 500)
        {
            Opps->notify();
        }
        if (Opps->getHp() > 0)
        {
            if (myCountry->getHp() < 500)
            {
                myCountry->notify();
            }
        }
    }
}
/*
 void selectOpposingCountry(){
    bool stats=false;
    while(stats=false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin>>countryStat;
        if(countryStat=="Yes"){
            cout<<"Select a Country Number"<<endl;
            for(int i=0; i<countrySize; i++) {
                cout<<i<<": "<<country[i]<<endl;
            }
        }else if(countryStat=="No"){
            stats=true;
        }
    }
    cout<<"Now you've had a chance to look at the countries, Choose a Country to fight"<<endl;
    for(int i=0; i<countrySize; i++) {
        if(i!=countryNum)
            cout<<i<<": "<<country[i]<<endl;
    }
}*/

void getCountryStats(int cNum)
{
}

void endGame()
{
}
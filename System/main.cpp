#include "Alliance.h"
#include "IndividualCountry.h"
#include "WarParticipant.h"
#include "AirCraft.h"
#include "AirSpace.h"
#include "Attack.h"
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


#include <iostream>
using namespace std;

 void initializeCountries();
 void pickCountry();
void fight();
void selectOpposingCountry();
void getCountryStats(int cNum);
 void endGame();

IndividualCountry*  country[10];
IndividualCountry* myCountry;
int countryNum, countrySize=2;

int main()
{
    cout<<"***********     Game Simulation    ***************\n";
    initializeCountries();
    pickCountry();
    fight();
    endGame();
    return 0;
}

 void initializeCountries(){
    country[0]=new IndividualCountry("China", 38, 200, 17, 4);
    country[1]=new IndividualCountry("Russia", 50, 209, 53, 19);
    //And so on
}

 void pickCountry(){
    cout<<"Select a Country from the list below by entering it's number"<<endl;
    for(int i=0; i<countrySize; i++) {
        cout<<i<<": "<<country[i]<<endl;
    }
    cin>>countryNum;
    myCountry=country[countryNum];
}

 void fight(){
     /*
     while(!country->surrender()){
         selectOpposingCountry();

     }
 */
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

 void getCountryStats(int cNum){

}

 void endGame(){

}
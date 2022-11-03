#include "Country.h"
#include "WarParticipant.h"
#include "WarParticipantIterator.h"
#include "CountryObserver.h"
#include "CountryObserverIterator.h"
#include "Alliance.h"
#include "IndividualCountry.h"
#include <iostream>
using namespace std;

public void initializeCounties();
public void pickCountry();
public void fight();
public void selectOpposingCountry();
public void getCountryStats(int cNum);
public void endGame();

Country* [] country;
IndividualCountry* myCountry;
int countryNum, countrySize;

int main()
{
    cout<<"***********     Game Simulation    ***************\n";
    initializeCountries();
    pickCountry();
    fight();
    endGame();
	return 0;
}

public void initializeCountries(){
    country[0]=new IndividualCountry("China", 38, 200, 17, 4);
    country[1]=new IndividualCountry("Russia", 50, 209, 53, 19);
    //And so on
}

public void pickCountry(){
    cout<<"Select a Country from the list below by entering it's number"<<endl;
    for(int i=0; i<countrySize; i++) {
        cout<<i<<": "<<country[i]<<endl;
    }
    cin<<countryNum;
    myCountry=country[countryNum];
}

public void fight(){
    while(!country->surrender()){
        selectOpposingCountry();

    }

}

public void selectOpposingCountry(){
    bool stats=false;
    while(stats=false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin<<countryStat;
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
}

public void getCountryStats(int cNum){

}

public void endGame(){

}
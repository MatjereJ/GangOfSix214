#include "SoldierFactory.h"
#include "Soldier.h"
#include "iostream"
using namespace std;

Soldier* SoldierFactory::createSoldier(int HP){
    Soldier* temp=new Soldier(HP);
    cout<<"Soldier Created"<<endl;
    return temp;
}
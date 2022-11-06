#include "SoldierFactory.h"
#include "Soldier.h"
#include "iostream"
#include "MachineGunner.h"
#include "Rifleman.h"
using namespace std;

SoldierFactory::SoldierFactory() {

}

Rifleman* SoldierFactory::createRifleman(int HP){
    Soldier* temp=new Soldier(HP);
    cout<<"Soldier Created"<<endl;
    return temp;
}

MachineGunner* SoldierFactory::createMachineGunner(int HP) {
    Soldier* temp=new Soldier(HP);
    cout<<"Soldier Created"<<endl;
    return temp;
}
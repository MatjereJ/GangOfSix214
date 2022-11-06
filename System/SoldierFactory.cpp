#include "SoldierFactory.h"
#include "Soldier.h"
#include "iostream"
#include "MachineGunner.h"
#include "Rifleman.h"
using namespace std;

SoldierFactory::SoldierFactory() {

}

Rifleman* SoldierFactory::createRifleman(int HP,int damage){
    Rifleman* temp=new Rifleman(HP,damage);
    cout<<"Soldier Created"<<endl;
    return temp;
}

MachineGunner* SoldierFactory::createMachineGunner(int HP,int damage) {
    MachineGunner* temp=new MachineGunner(HP,damage);
    cout<<"Soldier Created"<<endl;
    return temp;
}
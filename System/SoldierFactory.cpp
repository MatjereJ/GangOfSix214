#include "SoldierFactory.h"
#include "Soldier.h"
#include "iostream"
#include "MachineGunner.h"
#include "Rifleman.h"
using namespace std;

SoldierFactory::SoldierFactory() {

}

Rifleman* SoldierFactory::createRifleman(int damage,int HP){
    Rifleman* temp=new Rifleman(damage,HP);
    return temp;
}

MachineGunner* SoldierFactory::createMachineGunner(int damage,int HP) {
    MachineGunner* temp=new MachineGunner(damage,HP);
    return temp;
}
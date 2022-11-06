#include "FireArmFactory.h"
#include "Rifleman.h"
#include "MachineGunner.h"
#include "iostream"
using namespace std;

Rifleman* FireArmFactory::createRifle(int hp,int damage){
    Rifleman* temp=new Rifleman(hp,damage);
    return temp;
}

MachineGunner* FireArmFactory::createMachineGun(int hp,int damage){
    cout<<"Machine Gun Created"<<endl;
    MachineGunner* temp=new MachineGunner(hp,damage);
    return temp;
}


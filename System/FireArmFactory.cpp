#include "FireArmFactory.h"
#include "Rifleman.h"
#include "MachineGunner.h"
#include "iostream"
using namespace std;

Rifleman* FireArmFactory::createRifle(int damage){
    Rifleman* temp=new Rifleman(damage);
    return temp;
}

MachineGunner* FireArmFactory::createMachineGun(int damage){
    cout<<"Machine Gun Created"<<endl;
    MachineGunner* temp=new MachineGunner(damage);
    return temp;
}

void Rifleman::doNotting() {

}
#include "FireArmFactory.h"
#include "Rifle.h"
#include "MachineGun.h"
#include "iostream"
using namespace std;

Rifle* FireArmFactory::createRifle(int damage){
    Rifle* temp=new Rifle(damage);
    return temp;
}

MachineGun* FireArmFactory::createMachineGun(int damage){
    cout<<"Machine Gun Created"<<endl;
    MachineGun* temp=new MachineGun(damage);
    return temp;
}

void Rifle::doNotting() {

}
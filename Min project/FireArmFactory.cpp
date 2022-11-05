#include "FireArmFactory.h"
#include "iostream"
using namespace std;

Rifleman *FireArmFactory::createRifle(int damage)
{
    Rifleman *temp = new Rifleman(damage, 30);
    return temp;
}

MachineGunner *FireArmFactory::createMachineGun(int damage)
{
    cout << "Machine Gun Created" << endl;
    MachineGunner *temp = new MachineGunner(damage, 30);
    return temp;
}

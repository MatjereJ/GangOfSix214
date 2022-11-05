#include "MachineGunner.h"

MachineGunner::MachineGunner(int d, int h) : WarParticipant("FireArmFactory", "MachineGunner", d, h)
{
}

MachineGunner *MachineGunner::clone()
{
    MachineGunner *temp = new MachineGunner(this->getDamage(), this->getHP());
    return temp;
}

void MachineGunner::doNotting()
{
}

MachineGunner::MachineGunner() : WarParticipant("FireArmFactory", "MachineGunner", 6, 20)
{
}
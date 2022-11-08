#include "pch.h"
#include "MachineGunner.h"

MachineGunner::MachineGunner(int d, int h) : WarParticipant("FireArmFactory", "MachineGunner", d, h) {
    this->type = "MachineGunner";
}

MachineGunner* MachineGunner::clone() {
    MachineGunner* temp = new MachineGunner(this->getDamage(), this->getHP());
    return temp;
}

void MachineGunner::doNotting() {

}
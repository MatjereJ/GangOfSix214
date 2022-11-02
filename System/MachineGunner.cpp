#include "MachineGunner.h"

MachineGun::MachineGun(int damage) : WarParticipant("FireArmFactory", "MachineGunner"){
    this->damage=damage;
}

WarParticipant* MachineGun::clone() {
    MachineGun* temp=new MachineGun(damage);
    return temp;
}

void MachineGun::doNotting() {

}
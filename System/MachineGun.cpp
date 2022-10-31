#include "MachineGun.h"

MachineGun::MachineGun(int damage) : WarParticipant("FireArmFactory", "MachineGun"){
    this->damage=damage;
}

WarParticipant* MachineGun::clone() {
    MachineGun* temp=new MachineGun(damage);
    return temp;
}

void MachineGun::doNotting() {

}
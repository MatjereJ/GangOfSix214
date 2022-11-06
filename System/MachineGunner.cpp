#include "MachineGunner.h"

MachineGunner::MachineGunner(int d, int h) : WarParticipant("FireArmFactory", "MachineGunner", d, h){
    damage=d;
    hp=h;
}

MachineGunner* MachineGunner::clone() {
    MachineGunner* temp=new MachineGunner(damage, hp);
    return temp;
}

void MachineGunner::doNotting() {

}
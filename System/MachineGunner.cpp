#include "MachineGunner.h"

MachineGun::MachineGun(int d, int h) : WarParticipant("FireArmFactory", "MachineGunner", d, h){

}

MachineGunner* MachineGun::clone() {
    MachineGun* temp=new MachineGun(damage);
    return temp;
}

void MachineGun::doNotting() {

}
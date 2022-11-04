#include "Rifleman.h"

Rifleman::Rifle(int d, int h) : WarParticipant("FireArmFactory", "Rifleman", d, h){

}

Rifleman* Rifleman::clone() {
    Rifleman* temp=new Rifleman(damage);
    return temp;
}

void WarShip::doNotting() {

}
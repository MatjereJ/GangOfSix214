#include "Rifleman.h"

Rifleman::Rifleman(int d, int h) : WarParticipant("FireArmFactory", "Rifleman", d, h){
    damage=d;
    hp=h;
}

Rifleman* Rifleman::clone() {
    Rifleman* temp=new Rifleman(damage, hp);
    return temp;
}

void Rifleman::doNotting() {

}
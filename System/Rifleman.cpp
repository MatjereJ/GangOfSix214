#include "Rifleman.h"

Rifleman::Rifleman(int d, int h) : WarParticipant("FireArmFactory", "Rifleman", d, h){
    type="RifleMan";
}

Rifleman* Rifleman::clone() {
    Rifleman* temp=new Rifleman(damage, hp);
    return temp;
}

void Rifleman::doNotting() {

}
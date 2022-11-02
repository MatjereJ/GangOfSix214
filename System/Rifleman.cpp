#include "Rifleman.h"

Rifleman::Rifle(int damage) : WarParticipant("FireArmFactory", "Rifleman"){
    this->damage=damage;
}

Rifleman* Rifleman::clone() {
    Rifleman* temp=new Rifleman(damage);
    return temp;
}
#include "pch.h"
#include "Rifleman.h"

Rifleman::Rifleman(int d, int h) : WarParticipant("FireArmFactory", "Rifleman", d, h) {
   this->type = "RifleMan";
}

Rifleman* Rifleman::clone() {
    Rifleman* temp = new Rifleman(this->getDamage(),this->getHP());
    return temp;
}

void Rifleman::doNotting() {

}
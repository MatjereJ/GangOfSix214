#include "Rifle.h"

Rifle::Rifle(int damage) : WarParticipant("FireArmFactory", "Rifle"){
    this->damage=damage;
}

WarParticipant* Rifle::clone() {
    Rifle* temp=new Rifle(damage);
    return temp;
}
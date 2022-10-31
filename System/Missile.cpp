#include "Missile.h"

Missile::Missile(int damage) : WarParticipant("FireArmFactory", "Missile"){
    this->damage=damage;
}

WarParticipant* Missile::clone() {
    Missile* temp=new Missile(damage);
    return temp;
}
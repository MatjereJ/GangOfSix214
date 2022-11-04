#include "Missile.h"

Missile::Missile(int d, int h) : WarParticipant("FireArmFactory", "Missile", d, h){
    this->damage=damage;
}

Missile* Missile::clone() {
    Missile* temp=new Missile(damage);
    return temp;
}

#include "Missile.h"

Missile::Missile(int d, int h) : WarParticipant("FireArmFactory", "Missile", d, h){
    damage=d;
    hp=h;
}

Missile* Missile::clone() {
    Missile* temp=new Missile(damage, hp);
    return temp;
}

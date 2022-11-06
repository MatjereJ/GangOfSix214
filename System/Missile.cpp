#include "Missile.h"

Missile::Missile(int d, int h) : WarParticipant("FireArmFactory", "Missile", d, h){
    type="Missile";
}

Missile* Missile::clone() {
    Missile* temp=new Missile(damage, hp);
    return temp;
}

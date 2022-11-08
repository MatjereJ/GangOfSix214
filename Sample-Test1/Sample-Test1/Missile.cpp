#include "pch.h"

#include "Missile.h"

Missile::Missile(int d, int h) : WarParticipant("FireArmFactory", "Missile", d, h) {
    this->type = "Missile";
}

Missile* Missile::clone() {
    Missile* temp = new Missile(this->getDamage(), this->getHP());
    return temp;
}
void Missile::doNotting() {

}
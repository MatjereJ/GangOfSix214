#include "Bomb.h"

Bomb::Bomb(int damage): WarParticipant("ExplosiveFactory", "Bomb") {
    this->damage=damage;
}

WarParticipant* Bomb::clone() {
    Bomb* temp=new Bomb(damage);
    return temp;
}

void Bomb::doNotting() {

}
#include "Bomb.h"

Bomb::Bomb(int d, int h): WarParticipant("ExplosiveFactory", "Bomb", d, h) {
    damage=d;
    hp=h;
}

Bomb* Bomb::clone() {
    Bomb* temp=new Bomb(damage, hp);
    return temp;
}

void Bomb::doNotting() {

}
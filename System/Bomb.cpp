#include "Bomb.h"

Bomb::Bomb(int d, int h): WarParticipant("ExplosiveFactory", "Bomb", d, h) {

}

Bomb* Bomb::clone() {
    Bomb* temp=new Bomb(damage);
    return temp;
}

void Bomb::doNotting() {

}
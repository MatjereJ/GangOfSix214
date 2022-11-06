#include "Bomb.h"

Bomb::Bomb(int d, int h): WarParticipant("ExplosiveFactory", "Bomb", d, h) {
type="Bomb";
}

Bomb* Bomb::clone() {
    Bomb* temp=new Bomb(damage, hp);
    return temp;
}

void Bomb::doNotting() {

}
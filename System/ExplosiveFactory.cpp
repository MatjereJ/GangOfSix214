#include "ExplosiveFactory.h"
#include "Bomb.h"
#include "Missile.h"

WarParticipant* ExplosiveFactory::createBomb(int damage) {
    Bomb* temp=new Bomb(damage);
    return temp;
}

WarParticipant* ExplosiveFactory::createMissile(int damage){
    Missile* temp=new Missile(damage);
    return temp;
}

void Missile::doNotting() {

}
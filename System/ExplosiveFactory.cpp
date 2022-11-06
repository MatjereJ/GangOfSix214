#include "ExplosiveFactory.h"
#include "Bomb.h"
#include "Missile.h"

ExplosiveFactory::ExplosiveFactory() {

}

WarParticipant* ExplosiveFactory::createBomb(int damage) {
    Bomb* temp=new Bomb(damage, 30);
    return temp;
}

WarParticipant* ExplosiveFactory::createMissile(int damage){
    Missile* temp=new Missile(damage, 30);
    return temp;
}

void Missile::doNotting() {

}
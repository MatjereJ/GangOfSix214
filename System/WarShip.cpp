#include "WarShip.h"

WarShip::WarShip(int d, int h) : WarParticipant("WarTransportFactory", "WarShip", d, h){
    damage=d;
    hp=h;
}

WarShip* WarShip::clone() {
    WarShip* temp=new WarShip(damage, hp);
    return temp;
}

void WarShip::doNotting() {

}
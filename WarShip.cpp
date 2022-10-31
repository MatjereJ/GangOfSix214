#include "WarShip.h"

WarShip::WarShip(int hp) : WarParticipant("WarTransportFactory", "WarShip"){
    HP=hp;
}

WarParticipant* WarShip::clone() {
    WarShip* temp=new WarShip(HP);
    return temp;
}

void WarShip::doNotting() {

}
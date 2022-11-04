#include "WarShip.h"

WarShip::WarShip(int d, int h) : WarParticipant("WarTransportFactory", "WarShip", d, h){
    HP=hp;
}

WarShip* WarShip::clone() {
    WarShip* temp=new WarShip(HP);
    return temp;
}

void WarShip::doNotting() {

}
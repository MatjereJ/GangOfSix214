#include "WarShip.h"

WarShip::WarShip(int d, int h) : WarParticipant("WarTransportFactory", "WarShip", d, h){
   type="WarShip";
}

WarShip* WarShip::clone() {
    WarShip* temp=new WarShip(damage, hp);
    return temp;
}

void WarShip::doNotting() {

}
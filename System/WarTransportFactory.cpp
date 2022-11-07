#include "WarTransportFactory.h"

WarTransportFactory::WarTransportFactory() {

}

AirCraft* WarTransportFactory::createAirCraft(int hp) {
    AirCraft* temp=new AirCraft(70, hp);
    return temp;
}

WarShip* WarTransportFactory::createWarShip(int damage) {
    WarShip* temp=new WarShip(damage, 150);
    return temp;
}
#include "WarTransportFactory.h"
#include "AirCraft.h"
#include "WarShip.h"

WarParticipant* WarTransportFactory::createAirCraft(int hp) {
    AirCraft* temp=new AirCraft(hp);
    return temp;
}

WarParticipant* WarTransportFactory::createWarShip(int hp) {
    WarShip* temp=new WarShip(hp);
    return temp;
}
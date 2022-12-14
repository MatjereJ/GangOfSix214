#ifndef PRACTICAL_ASSIGNMENT_3_WARTRANSPORTFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_WARTRANSPORTFACTORY_H
#include "WarParticipantFactory.h"
#include "WarParticipant.h"
#include "AirCraft.h"
#include "WarShip.h"

class WarTransportFactory: public WarParticipantFactory{
public:
    WarTransportFactory();
    AirCraft* createAirCraft(int hp);
    WarShip* createWarShip(int damage);
};


#endif //PRACTICAL_ASSIGNMENT_3_WARTRANSPORTFACTORY_H

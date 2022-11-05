#ifndef PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H
#include "WarParticipantFactory.h"
#include "WarParticipant.h"

class WarTransportFactory: public WarParticipantFactory{
public:
    WarParticipant* createAirCraft(int HP);
    WarParticipant* createWarShip(int HP);
};


#endif //PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H

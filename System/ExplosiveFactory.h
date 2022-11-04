#ifndef PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H
#include "WarParticipantFactory.h"
#include "WarParticipant.h"

class ExplosiveFactory: public WarParticipantFactory{
public:
    WarParticipant* createBomb(int damage);
    WarParticipant* createMissile(int damage);
};


#endif //PRACTICAL_ASSIGNMENT_3_EXPLOSIVEFACTORY_H

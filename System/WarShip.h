#ifndef PRACTICAL_ASSIGNMENT_3_WARSHIP_H
#define PRACTICAL_ASSIGNMENT_3_WARSHIP_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class WarShip: public WarParticipant {
public:
    WarShip(int d, int h);
    WarShip* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_WARSHIP_H

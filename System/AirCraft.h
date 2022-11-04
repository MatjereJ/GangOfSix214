#ifndef PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#define PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class AirCraft: public WarParticipant {
public:
    AirCraft(int d, int h);
    Aircraft* clone();
    void doNotting();

};


#endif //PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H

#ifndef PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H
#define PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H
#include "WarParticipant.h"

class Rifleman: public WarParticipant{
    int damage;
public:
    Rifleman(int damage);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H

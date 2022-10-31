#ifndef PRACTICAL_ASSIGNMENT_3_RIFLE_H
#define PRACTICAL_ASSIGNMENT_3_RIFLE_H
#include "WarParticipant.h"

class Rifle: public WarParticipant{
    int damage;
public:
    Rifle(int damage);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_RIFLE_H

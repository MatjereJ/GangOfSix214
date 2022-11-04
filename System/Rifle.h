#ifndef PRACTICAL_ASSIGNMENT_3_RIFLE_H
#define PRACTICAL_ASSIGNMENT_3_RIFLE_H
#include "WarParticipant.h"

class Rifle: public WarParticipant{
    int damage;
public:
    Rifle(int damage);
    Rifle(string type) : WarParticipant(type, 5){};
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_RIFLE_H

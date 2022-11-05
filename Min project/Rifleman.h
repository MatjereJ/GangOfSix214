#ifndef PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H
#define PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H
#include "WarParticipant.h"

class Rifleman : public WarParticipant
{
public:
    Rifleman(int d, int h);
    Rifleman();
    Rifleman *clone();
    void doNotting();
};

#endif // PRACTICAL_ASSIGNMENT_3_RIFLEMAN_H

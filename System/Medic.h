#ifndef PRACTICAL_ASSIGNMENT_3_MEDIC_H
#define PRACTICAL_ASSIGNMENT_3_MEDIC_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Medic: public WarParticipant {
private:
    int HP;
    int healingHP;
public:
    Medic(int hp);
    WarParticipant* clone();
    void doNotting();
    int getHealingHP();
    void setHealingHP(int hp);
};


#endif //PRACTICAL_ASSIGNMENT_3_MEDIC_H

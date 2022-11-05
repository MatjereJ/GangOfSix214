#ifndef PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H
#define PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#include <string>
using namespace std;

class WarParticipant
{

public:
    WarParticipant(string manufacturer, string type, int d, int h);
    virtual void doNotting() = 0;
    std::string getType();
    void incrementParticipantNumber();
    int getNumParticipants();
    int getHP();
    int getDamage();
    void setHp(int h);
    void setDamage(int d);

private:
    string manufacturer;
    string type;
    int damage;
    int hp;
    int numParticipants; // Iterator
};

#endif // PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

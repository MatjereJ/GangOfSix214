#ifndef PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H
#define PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#include <string>
using namespace std;

class WarParticipant{

public:
    WarParticipant(string manufacturer, string type, int d, int h);
    virtual void doNotting()=0;
    std::string getType();
    void incrementParticipantNumber();
    int getNumParticipants();
    int getHP();
    int getDamage();
private:
    string manufacturer;
    string type;
    int numParticipants; //Iterator
protected:
    int damage;
    int hp;
};


#endif //PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#ifndef PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H
#define PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#include <string>
using namespace std;

class WarParticipant{

public:
    WarParticipant(string manufacturer, string type);
    WarParticipant(string type, int dmg);
    virtual void doNotting()=0;
    string getDescription();
    WarParticipant* clone();
    std::string getType();
    void incrementParticipantNumber();
    int getNumParticipants();
    //WarParticipant(std::string, int);
private:
    string manufacturer;
    string type;
    int damage;
    int numParticipants; //Iterator
};


#endif //PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

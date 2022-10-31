#ifndef PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H
#define PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#include <string>
using namespace std;

class WarParticipant{
private:
    string manufacturer;
    string type;
public:
    WarParticipant(string manufacturer, string type);
    virtual void doNotting()=0;
    string getDescription();
    WarParticipant* clone();
};


#endif //PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

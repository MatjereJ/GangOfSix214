#ifndef PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H
#define PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

#include <string>
using namespace std;

class WarParticipant{
private:
    string manufacturer;
    string type;
//Mokoena
    int numParticipants;
public:
    WarParticipant(string manufacturer, string type);
    virtual void doNotting()=0;
    string getDescription();
    WarParticipant* clone();

    
//Mokoena
    WarParticipant(std::string, int);
		std::string getType();
		void incrementParticipantNumber();
		int getNumParticipants();
};


#endif //PRACTICAL_ASSIGNMENT_3_WARPARTICIPANT_H

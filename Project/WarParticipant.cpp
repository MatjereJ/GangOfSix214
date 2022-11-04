#include "WarParticipant.h"

    WarParticipant::WarParticipant(std::string manufacturer, std::string type) {
        this->manufacturer=manufacturer;
        this->type=type;
    }

    string WarParticipant::getDescription() {
        return type;
    }

//    WarParticipant::~WarParticipant(){
//        delete this;
//    }


WarParticipant::WarParticipant(std::string type, int num) 
{
	this->type = type;
	numParticipants = num;
}

std::string WarParticipant::getType()
{
	return type;
}

void WarParticipant::incrementParticipantNumber()
{
	numParticipants++;
}

int WarParticipant::getNumParticipants()
{
	return numParticipants;
}

    
#include "WarParticipant.h"

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
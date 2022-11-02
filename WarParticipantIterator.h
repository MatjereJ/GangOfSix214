#ifndef WARPARTICIPANTITERATOR_H
#define WARPARTICIPANTITERATOR_H
#include "IteratorTool.h"
#include <vector>
#include "WarParticipant.h"
#include "Country.h"

class Country;

class WarParticipantIterator : public IteratorTool
{
	public:
		WarParticipantIterator(Country*);
		void first();
		void next();
		bool isLastEl();
		WarParticipant* currentEl();
	
	private:
		std::vector<WarParticipant*>::iterator it;
		std::vector<WarParticipant*> storeList;
		WarParticipant* curr;
};
#endif
#ifndef WARPARTICIPANTITERATOR_H
#define WARPARTICIPANTITERATOR_H
#include "IteratorTool.h"
#include <list>
#include "WarParticipant.h"
#include "Country.h"

class Country;

class WarParticipantIterator : public IteratorTool
{
	friend class Country;
	public:
		WarParticipantIterator(Country*);
		void first();
		void next();
		bool isLastEl();
		WarParticipant* currentEl();
	
	private:
		std::list<WarParticipant*>::iterator it;
		std::list<WarParticipant*> storeList;
		WarParticipant* curr;
};
#endif
#ifndef WARPARTICIPANTITERATOR_H
#define WARPARTICIPANTITERATOR_H
#include "IteratorTool.h"
#include <vector>
#include "WarParticipant.h"
class IndividualCountry;
using namespace std;

class WarParticipantIterator : public IteratorTool
{
	friend class IndividualCountry;
	public:
		WarParticipantIterator(vector<WarParticipant*>);
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
#include "WarParticipantIterator.h"

WarParticipantIterator::WarParticipantIterator(vector<WarParticipant*> list): IteratorTool()
{
	storeList = list;
	it = storeList.begin();
	curr = *it;
}

void WarParticipantIterator::first()
{
	it = storeList.begin();
	curr = *it;
}

void WarParticipantIterator::next()
{
	it++;
	curr = *it;
}

bool WarParticipantIterator::isLastEl()
{
	if(it == storeList.end())
	{
		return true;
	}
	return false;
}

WarParticipant* WarParticipantIterator::currentEl()
{
	return curr;
}
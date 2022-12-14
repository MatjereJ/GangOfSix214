#include "CountryIterator.h"

CountryIterator::CountryIterator(vector<Country*> obj): IteratorTool()
{
	storeList = obj;
	it = storeList.begin();
	curr = *it;
}

void CountryIterator::first()
{
	it = storeList.begin();
	curr = *it;
}

void CountryIterator::next()
{
	it++;
	curr = *it;
}

bool CountryIterator::isLastEl()
{
	if(it == storeList.end())
	{
		return true;
	}
	return false;
}

Country* CountryIterator::currentEl()
{
	return curr;
}
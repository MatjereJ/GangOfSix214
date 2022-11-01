#include "CountryObserverIterator.h"

CountryObserverIterator::CountryObserverIterator(Country* obj): IteratorTool()
{
	storeList = obj->getCountryObservers();
	it = storeList.begin();
	curr = *it;
}

void CountryObserverIterator::first()
{
	it = storeList.begin();
	curr = *it;
}

void CountryObserverIterator::next()
{
	it++;
	curr = *it;
}

bool CountryObserverIterator::isLastEl()
{
	if(it == storeList.end())
	{
		return true;
	}
	return false;
}

CountryObserver* CountryObserverIterator::currentEl()
{
	return curr;
}
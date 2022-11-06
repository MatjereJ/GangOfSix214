#ifndef COUNTRYOBSERVERITERATOR_H
#define COUNTRYOBSERVERITERATOR_H
#include "IteratorTool.h"
#include <list>
#include "CountryObserver.h"

class IndividualCountry;

class CountryObserverIterator : public IteratorTool
{
	friend class IndividualCountry;
	public:
		CountryObserverIterator(vector<CountryObserver*>);
		void first();
		void next();
		bool isLastEl();
		CountryObserver* currentEl();
	
	private:
		std::vector<CountryObserver*>::iterator it;
		std::vector<CountryObserver*> storeList;
		CountryObserver* curr;
};
#endif
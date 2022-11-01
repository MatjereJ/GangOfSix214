#ifndef COUNTRYOBSERVERITERATOR_H
#define COUNTRYOBSERVERITERATOR_H
#include "IteratorTool.h"
#include <list>
#include "CountryObserver.h"
#include "Country.h"

class Country;

class CountryObserverIterator : public IteratorTool
{
	friend class Country;
	public:
		CountryObserverIterator(Country*);
		void first();
		void next();
		bool isLastEl();
		CountryObserver* currentEl();
	
	private:
		std::list<CountryObserver*>::iterator it;
		std::list<CountryObserver*> storeList;
		CountryObserver* curr;
};
#endif
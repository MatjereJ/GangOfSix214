#ifndef COUNTRYITERATOR_H
#define COUNTRYITERATOR_H
#include "IteratorTool.h"
#include <vector>
//#include "Alliance.h"
#include "Country.h"

class Country;

class CountryIterator : public IteratorTool
{
	friend class Country;
	public:
		CountryIterator(Country*);
		void first();
		void next();
		bool isLastEl();
		Country* currentEl();
	
	private:
		std::vector<Country*>::iterator it;
		std::vector<Country*> storeList;
		Country* curr;
};
#endif
#include "IndividualCountry.h"
#include <iostream>

IndividualCountry::IndividualCountry(std::string name, std::string type) : Country(name), indivCountryName(name), cType(type)
{
}

IndividualCountry::~IndividualCountry()
{
	std::cout<<"Country "<<indivCountryName<<" deleted\n";
}

void IndividualCountry::addAlly(Country* newAlly)
{
}

void IndividualCountry::removeAlly(Country* oldAlly)
{	
}

std::string IndividualCountry::getType()
{
	return cType;
}

std::vector<Country*> IndividualCountry::getVectArray()
{
	return std::vector<Country*>();
}

void IndividualCountry::setAlliance(Country* newAlly)
{
	storeAllies = newAlly;
}

Country* IndividualCountry::getAlliance()
{
	return storeAllies;
}
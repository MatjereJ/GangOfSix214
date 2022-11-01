#include "CountryObserver.h"
#include <iostream>

CountryObserver::CountryObserver(std::string obsName) : name(obsName)
{
}

CountryObserver::~CountryObserver()
{
	std::cout<<"Observer named "<<name<<" deleted.\n";
}

std::string CountryObserver::getName()
{
	return name;
}

void CountryObserver::print()
{
	std::cout<<"I am "<<name<<" and I am observing the country.\n";
}
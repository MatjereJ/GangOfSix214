#include "Country.h"
#include <iostream>

Country::Country(std::string name)
{
	cName = name;
}
Country::Country(std::string name, BattleState* state)
{
	cName = name;
	this->state = state;
}

Country::~Country()
{
	wp.clear();
	std::cout<<"Parent of "<<cName <<" deleted.\n";
}

void Country::setState(BattleState* newState)
{
	this->state = newState;
}

BattleState* Country::getState()
{
	return state;
}

void Country::addWarParticipant(WarParticipant* warPtc)
{
	wp.push_back(warPtc);
}

void Country::addCountryObserver(CountryObserver* cObs)
{
	observerList.push_back(cObs);
}

std::list<CountryObserver*> Country::getCountryObservers()
{
	return observerList;
}
std::list<WarParticipant*> Country::getWarParticipants()
{
	return wp;
}

void Country::setWarTheatre(WarTheatre* place)
{
	wt = place;
}

WarTheatre* Country::getWarTheatre()
{
	return wt;
}

void Country::startWar()
{
	std::cout<<"Launch attack on enemy. War beginning.\n";
}

void Country::withdraw()
{
	std::cout<<"We are losing a lot of lives. We are withdrawing from the war.\n";
}

void Country::joinExistingGroup()
{
	std::cout<<"We cannot do this alone. We need to join an alliance.\n";
}

void Country::changeSides()
{
	std::cout<<"Our alliance is weak. Let us form a better alliance.\n";
}

void Country::requestAssistance()
{
	std::cout<<"We need help. We are losing.\n";
}

WarParticipantIterator* Country::createWarParticipantIterator()
{
	return new WarParticipantIterator(this);
}

CountryObserverIterator* Country::createCountryObserverIterator()
{
	return new CountryObserverIterator(this);
}

std::string Country::getName()
{
	return cName;
}
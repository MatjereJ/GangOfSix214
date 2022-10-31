#include "Alliance.h"
#include <iostream>

Alliance::Alliance(std::string name, std::string type) : Country(name), allianceName(name), cType(type)
{
}

Alliance::~Alliance()
{
	std::cout<<"Alliance "<<allianceName<<" deleted.\n";
}

std::string Alliance::getType()
{
	return cType;
}

void Alliance::addAlly(Country* newAlly)
{
	if(!countryExists(this->getVectArray(), newAlly))
	{
		allianceLists.push_back(newAlly);
		std::cout<<"Ally Added.\n";
	}
	else
	{
		std::cout<<"Ally already exists.\n";
	}
}

void Alliance::removeAlly(Country* oldAlly)
{
	if(countryExists(this->getVectArray(), oldAlly))
	{
		
	}
}

std::vector<Country*> Alliance::getVectArray()
{
	return allianceLists;
}

bool Alliance::countryExists(std::vector<Country*> arr, Country* countryEl)
{
	if(arr.empty())
	{
		return false;
	}
	
	std::vector<Country*>::iterator move;
	
	for(move = arr.begin(); move != arr.end(); move++)
	{
		if((*move)->getName() == countryEl->getName())
		{
			return true;
		}
		else if((*move)->getType() == "Alliance")
		{
			return countryExists((*move)->getVectArray(), countryEl);
		}
	}
	return false;
}

bool Alliance::removeAllyHelper(std::vector<Country*> arr, Country* countryEl)
{
	return false;
}
void Alliance::setAlliance(Country* newAlly)
{
	return;
}

Country* Alliance::getAlliance()
{
	return NULL;
}
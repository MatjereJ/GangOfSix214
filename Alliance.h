#ifndef ALLIANCE_H
#define ALLIANCE_H
#include <string>
#include <vector>
#include "Country.h"
#include "CountryIterator.h"

class Alliance : public Country
{
	public:
		Alliance(std::string, std::string);
		~Alliance();
		std::string getType();
		/*void addAlly(Country*);
		void removeAlly(Country*);*/
		std::vector<Country*> getVectArray();
		/*bool countryExists(std::vector<Country*>, Country*);
		bool removeAllyHelper(std::vector<Country*>, Country*);
		void setAlliance(Country*);
		Country* getAlliance();*/
		CountryIterator* createCountryIterator();
	
	private:
		std::string allianceName;
		std::vector<Country*> allianceLists;
		std::string cType;
};
#endif
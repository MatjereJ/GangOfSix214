#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include <string>
#include "Country.h"

class IndividualCountry : public Country
{
	public:
		IndividualCountry(std::string, std::string);
		~IndividualCountry();
		void addAlly(Country*);
		void removeAlly(Country*);
		std::string getType();
		std::vector<Country*> getVectArray();
		void setAlliance(Country*);
		Country* getAlliance();
		
	private:
		Country* storeAllies;
		std::string indivCountryName;
		std::string cType;
};
#endif
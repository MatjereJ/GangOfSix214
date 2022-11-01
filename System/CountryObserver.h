#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include <string>

class Country;
class CountryObserver
{
	public:
		CountryObserver(std::string);
		~CountryObserver();
		std::string getName();
		void print();
	
	private:
		std::string name;
};
#endif
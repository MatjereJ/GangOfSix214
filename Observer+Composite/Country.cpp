#include "CountryObserver.h"
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>

bool Country::add(CountryObserver* assistance){
     countryObservers.push_back(assistance); 
     return true;
}
bool Country::remove(CountryObserver* assistance){
  bool found = false;

  vector<CountryObserver*>::iterator it = countryObservers.begin();
  while ((it != countryObservers.end()) && (! found)) {
    if (*it == assistance) {
      found = true;
      countryObservers.erase(it);
    }
    ++it;
  }
  return found;
}
void Country::notify(){
    vector<CountryObserver*>::iterator it = countryObservers.begin();
  for (it = countryObservers.begin(); it != countryObservers.end(); ++it){
    (*it)->update();
  }
}
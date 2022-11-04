//
// Created by JOHANES MATSEBA on 2022/10/24.
//

#ifndef PROJECTASSIGNMENT_COUNTRYMEMORY_H
#define PROJECTASSIGNMENT_COUNTRYMEMORY_H
#include "CountryBackup.h"

class CountryMemory {
private:
    CountryBackup* backup;

public:
    CountryMemory();
    CountryBackup* retrieveBackup();
    void storeBackup(CountryBackup* s);
    ~CountryMemory();
};


#endif //PROJECTASSIGNMENT_COUNTRYMEMORY_H

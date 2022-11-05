//
// Created by JOHANES MATSEBA on 2022/10/24.
//

#include "CountryMemory.h"


void CountryMemory::storeBackup(CountryBackup *s) {
    backup=s;
}

CountryBackup* CountryMemory::retrieveBackup() {
    return backup;
}

CountryMemory::~CountryMemory() {
    delete backup;
}


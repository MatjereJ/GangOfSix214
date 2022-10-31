#include "WarParticipant.h"

    WarParticipant::WarParticipant(std::string manufacturer, std::string type) {
        this->manufacturer=manufacturer;
        this->type=type;
    }

    string WarParticipant::getDescription() {
        return type;
    }

//    WarParticipant::~WarParticipant(){
//        delete this;
//    }

    
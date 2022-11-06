#ifndef Attack_h
#define Attack_h
#include "BattleState.h"
#include "DetonateExplosives.h"
#include "Shoot.h"
#include "FireMissile.h"
#include "Context.h"
#include "WarParticipants.h"
//#include "IndividualCountry.h"

class Attack : public BattleState
{
public:
    void handleChange(IndividualCountry *C);
};
#endif
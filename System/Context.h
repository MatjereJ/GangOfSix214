#ifndef Context_h
#define Context_h
#include "AttackStrategy.h"
#include "Country.h"

class Context
{
private:
    AttackStrategy *state;

public:
    Context(AttackStrategy *s);
    ~Context();
    void SetState(AttackStrategy *s);
    void implement(Country *C);
};

#endif
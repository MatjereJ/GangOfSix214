#include "Context.h"
#include <iostream>

Context::Context(AttackStrategy *s)
{
    state = s;
}

Context::~Context()
{
    delete state;
    state = nullptr;
}

void Context::SetState(AttackStrategy *s)
{
    state = s;
}

void Context::implement(Country *C)
{
    state->LaunchAttack(C);
}
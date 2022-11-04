//
// Created by JOHANES MATSEBA on 2022/10/26.
//

#include "BattleState.h"


void BattleState::handleChange(Country *C)
{
    if (successor == nullptr)
    {
        cout << "No chain has been added" << endl;
    }
    else
        successor->handleChange(C);
}

void BattleState::Add(BattleState *succ)
{
    if (successor == nullptr)
        successor = succ;
    else
    {
        cout << "Element added to chain" << endl;
        BattleState *curr = this;
        while (curr->successor != nullptr)
        {
            curr = curr->successor;
        }
        curr->successor = succ;
    }
}

BattleState::BattleState()
{
    successor = nullptr;
}
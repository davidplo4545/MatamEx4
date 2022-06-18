//
// Created by David on 08/06/2022.
//
#ifndef MATAMEX4_VAMPIRE_H
#define MATAMEX4_VAMPIRE_H
#include "BattleCard.h"

class Vampire: public BattleCard{
    static const int FORCE_DECREASE = 1;
public:
    Vampire();
    void applyEncounter(Player& player) const override;

};


#endif //MATAMEX4_VAMPIRE_H

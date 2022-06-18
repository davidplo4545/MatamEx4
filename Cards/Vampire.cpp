//
// Created by David on 08/06/2022.
//
#include "BattleCard.h"
#include "Vampire.h"
using std::ostream;

Vampire::Vampire():BattleCard("Vampire"){}

void Vampire::applyEncounter(Player &player) const {
    BattleCard::applyEncounter(player);
    if(player.getAttackStrength() < m_force)
    {
        player.nerf(Vampire::FORCE_DECREASE);
    }
}


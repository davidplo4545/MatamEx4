//
// Created by David on 08/06/2022.
//

#include "Barfight.h"

Barfight::Barfight():Card("Barfight"){}

void Barfight::applyEncounter(Player &player) const {
//    const Fighter* fighter = dynamic_cast<const Fighter*>(player);
    Player* fighter = &player;
    if(fighter != nullptr)
    {
        printBarfightMessage(true);
    }
    else
    {
        player.damage(DAMAGE);
        printBarfightMessage(false);
    }
}

//
// Created by David on 08/06/2022.
//
#include "Card.h"
#include "Pitfall.h"
using std::ostream;

Pitfall::Pitfall():Card("Pitfall"){}

void Pitfall::applyEncounter(Player &player) const {
//    const Rogue* rogue = dynamic_cast<const Rogue*>(player);
    Player* rogue = &player;
    if(rogue != nullptr)
    {
        printPitfallMessage(true);
    }
    else
    {
        player.damage(DAMAGE);
        printPitfallMessage(false);
    }
}



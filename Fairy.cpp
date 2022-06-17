//
// Created by David on 08/06/2022.
//

#include "Fairy.h"
#include "Wizard.h"
using namespace std;
Fairy::Fairy():Card("Fairy"){}

void Fairy::applyEncounter(Player &player) const {
    const Wizard* wizard = dynamic_cast<const Wizard*>(&player);

    if(wizard != nullptr)
    {
        player.heal(HEAL);
        printFairyMessage(true);
    }
    else
    {
        printFairyMessage(false);
    }
}

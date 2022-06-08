//
// Created by David on 08/06/2022.
//

#include "Treasure.h"
#include "Card.h"

Treasure::Treasure():Card("Treasure"){}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(LOOT);
    printTreasureMessage();
}

//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_TREASURE_H
#define MATAMEX4_TREASURE_H
#include "../Players/Player.h"
#include "Card.h"

class Treasure :public Card{
    const int LOOT = 10;
public:
    Treasure();
    void applyEncounter(Player& player) const override;
};



#endif //MATAMEX4_TREASURE_H

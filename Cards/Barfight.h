//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_BARFIGHT_H
#define MATAMEX4_BARFIGHT_H
#include "Card.h"


class Barfight :public Card{
    const int DAMAGE = 10;
public:
    Barfight();
    void applyEncounter(Player& player) const override;
};


#endif //MATAMEX4_BARFIGHT_H

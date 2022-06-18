//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_FAIRY_H
#define MATAMEX4_FAIRY_H
#include "Card.h"

class Fairy :public Card{
    const int HEAL = 10;
public:
    Fairy();
    void applyEncounter(Player& player) const override;
};


#endif //MATAMEX4_FAIRY_H

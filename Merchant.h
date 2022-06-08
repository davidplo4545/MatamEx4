//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_MERCHANT_H
#define MATAMEX4_MERCHANT_H
#include "card.h"
#include "player.h"

class Merchant :public Card{
    const int HEAL = 10;
public:
    Merchant();
    void applyEncounter(Player& player) const override;
};



#endif //MATAMEX4_MERCHANT_H

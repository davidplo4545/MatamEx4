//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_MERCHANT_H
#define MATAMEX4_MERCHANT_H
#include "card.h"
#include "player.h"

class Merchant :public Card{
    const std::map<int,std::vector<int>> STORE = {
            {1,{5,1}}, // Heal: amount:1, cost: 5
            {2,{10,1}}, // Buff: force:1, cost: 10
    };

    bool applySelectedOption(int option, Player &player) const;
public:
    Merchant();
    void applyEncounter(Player& player) const override;
};



#endif //MATAMEX4_MERCHANT_H

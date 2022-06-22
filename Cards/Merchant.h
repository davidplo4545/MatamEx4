//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_MERCHANT_H
#define MATAMEX4_MERCHANT_H
#include "Card.h"
#include "../Players/Player.h"

class Merchant :public Card{
    static const int NONE_OPTION = 0;
    static const int HEAL_OPTION = 1;
    static const int BUFF_OPTION = 2;

    static const int NO_MONEY = 0;
    const std::map<int,std::vector<int>> STORE = {
            {1,{5,1}}, // Heal: amount:1, cost: 5
            {2,{10,1}}, // Buff: force:1, cost: 10
    };
    static bool isValidNumber(std::string str);
    void applySelectedOption(int option, Player &player) const;
public:
    Merchant();
    void applyEncounter(Player& player) const override;
};



#endif //MATAMEX4_MERCHANT_H

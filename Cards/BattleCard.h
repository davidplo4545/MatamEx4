//
// Created by david on 6/14/2022.
//

#ifndef MATAMEX4_BATTLECARD_H
#define MATAMEX4_BATTLECARD_H
#include "Card.h"


class BattleCard: public Card{
protected:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
    static const int FULL_DMG = -1;

private:
    const std::map<std::string,std::vector<int>> CARDS_DICT = {
            {"Goblin",{6,2,10}},
            {"Dragon",{25,1000,FULL_DMG}},
            {"Vampire",{10,2,10}},
    };

public:
    explicit BattleCard(std::string name);
    void printCardInfo(std::ostream& os) const override;

    void applyEncounter(Player& player) const override;
};


#endif //MATAMEX4_BATTLECARD_H

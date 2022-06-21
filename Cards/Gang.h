//
// Created by david on 6/20/2022.
//

#ifndef MATAMEX4_GANG_H
#define MATAMEX4_GANG_H
#include "BattleCard.h"
#include <memory>

class Gang :public Card{
    std::vector<std::unique_ptr<BattleCard>> m_gangMembers;

public:
    Gang();
    void applyEncounter(Player &player) const override;
    void pushToGang(std::unique_ptr<BattleCard> card);
};


#endif //MATAMEX4_GANG_H

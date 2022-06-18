//
// Created by david on 6/14/2022.
//

#include "BattleCard.h"
using std::string;
using std::ostream;

BattleCard::BattleCard(string name):
        Card(name){
    m_force = BattleCard::CARDS_DICT.at(name)[0];
    m_loot = BattleCard::CARDS_DICT.at(name)[1];
    m_hpLossOnDefeat = BattleCard::CARDS_DICT.at(name)[2];
}

void BattleCard::printCardInfo(ostream& os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, false);
    printEndOfCardDetails(os);
}

void BattleCard::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else
    {
        int hpLoss = m_hpLossOnDefeat == BattleCard::FULL_DMG ? player.getHealth() : m_hpLossOnDefeat;
        player.damage(hpLoss);
        printLossBattle(player.getName(), m_name);
    }
}

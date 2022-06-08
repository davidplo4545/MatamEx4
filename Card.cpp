#include "Card.h"
#include "utilities.h"
using namespace std;
using std::string;

std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.printCardInfo(os);
    return os;
}

Card::Card(string name):
    m_name(name){
}

void Card::printCardInfo(ostream& os) const {
    printCardDetails(os, m_name);
}

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

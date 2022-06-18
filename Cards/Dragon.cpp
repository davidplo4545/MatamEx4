//
// Created by David on 08/06/2022.
//
#include "BattleCard.h"
#include "Dragon.h"
using std::ostream;
Dragon::Dragon():BattleCard("Dragon"){}

void Dragon::printCardInfo(ostream& os) const {
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, true);
    printEndOfCardDetails(os);
}

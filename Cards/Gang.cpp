//
// Created by david on 6/20/2022.
//

#include "Gang.h"
#include "BattleCard.h"
using namespace std;
Gang::Gang():Card("Gang"){}

void Gang::pushToGang(std::unique_ptr<BattleCard> card) {
    m_gangMembers.push_back(move(card));
}

void Gang::applyEncounter(Player &player) const {
    int numMembers = m_gangMembers.size();
    bool hasLost = false;
    for(int i=0;i<numMembers;i++)
    {
//        cout << "Playing VS GANG" << endl;
//        cout << "Current Monster:";
//        m_gangMembers[i]->printCardInfo(cout);
        if(!hasLost)
        {
            hasLost = m_gangMembers[i]->applyGangEncounter(player);
        }
        else
        {
            m_gangMembers[i]->applyLostGang(player);
        }
    }
    if(!hasLost)
    {
        player.levelUp();
        printWinBattle(player.getName(), "Gang");

    }

}



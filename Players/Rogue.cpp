#include "Rogue.h"
#include "../utilities.h"
using std::string;
using std::ostream;
Rogue::Rogue(string name): Player(name, "Rogue"){}

void Rogue::addCoins(int coins)
{
    if(coins > 0)
    {
        m_coins+=coins*2;
    }
}

void Rogue::print(ostream& os) const
{
	printPlayerDetails(os, m_name, m_job,m_level, m_force, m_hp,m_coins);
}
#include "Wizard.h"
#include "../utilities.h"
using std::string;
using std::ostream;
Wizard::Wizard(string name):Player(name, "Wizard"){}
void Wizard::heal(int hpSupply)
{
    hpSupply *=2;
    if(hpSupply > 0)
    {
        m_hp= hpSupply + m_hp > m_maxHp ? m_maxHp : m_hp+hpSupply;
    }
}

void Wizard::print(ostream& os) const
{
	printPlayerDetails(os, m_name, m_job,m_level, m_force, m_hp,m_coins);
}
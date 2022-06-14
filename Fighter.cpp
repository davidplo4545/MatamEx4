#include "Fighter.h"
#include "utilities.h"
using std::string;
using std::ostream;
Fighter::Fighter(string name): Player(name, "Fighter"){}

int Fighter::getAttackStrength() const
{
    return 2*m_force+m_level;
}

void Fighter::print(ostream& os) const
{
	printPlayerDetails(os, m_name,m_job,m_level, m_force, m_hp,m_coins);
}
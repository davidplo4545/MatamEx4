#include "Wizard.h"

virtual void Player::getAttackStrength()
{
    return this->2*m_force+this->m_level;
}

virtual void print(ostream& os) const 
{
	utilities::printPlayerDetails(os, this->m_name,Player::JOB,this->m_level, this->m_force, this->m_hp,this->m_coins);
}
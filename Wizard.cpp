#include "Wizard.h"

void Player::heal(int hpSupply)
{
    this->heal(2*hpSupply);
}

void Player::print(ostream& os) const 
{
	utilities::printPlayerDetails(os, this->m_name, player::JOB,this->m_level, this->m_force, this->m_hp,this->m_coins);
}
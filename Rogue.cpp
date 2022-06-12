#include "Rouge.h"

void Player::addCoins(int coins)
{
    this->addCoins(2*coins);
}

void print(ostream& os) const 
{
	utilities::printPlayerDetails(os, this->m_name,Player::JOB,this->m_level, this->m_force, this->m_hp,this->m_coins);
}
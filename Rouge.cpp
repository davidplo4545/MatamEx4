#include "Rouge.h"

virtual void Player::addCoins(int coins)
{
    if(coins > 0)
    {
        this->m_coins+=2*coins;
    }
}

virtual void print(ostream& os) const 
{
	utilities::printPlayerDetails(os, this->m_name,job,this->m_level, this->m_force, this->m_hp,this->m_coins);
}
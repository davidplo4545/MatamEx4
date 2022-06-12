#include "Wizard.h"

virtual void Player::heal(int hpSupply)
{
    hpSupply*=2;
    if(hpSupply > 0)
    {
        this->m_hp= hpSupply + this->m_hp > this->m_maxHp ? this->m_maxHp : this->m_hp+hpSupply;
    }
}

virtual void print(ostream& os) const 
{
	utilities::printPlayerDetails(os, this->m_name,job,this->m_level, this->m_force, this->m_hp,this->m_coins);
}
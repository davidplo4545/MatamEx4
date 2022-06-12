#include "Player.h"
const int DEAD = 0;
const int DEFAULT_FORCE = 5;
const int DEFAULT_HP = 100;
Player::Player(string name)
{
    maxHp = 100;
    this->m_level = 1;
    this->m_coins=10;
    this->m_force = 5;
    this->m_hp = maxHp;
    this->m_name = name;

}
Player::Player(const Player& player)
{
    this->m_level = player.m_level;
    this->m_coins=player.m_coins;
    this->m_force = player.m_force;
    this->m_maxHp = player.m_maxHp;
    this->m_hp = player.m_hp;
    this->m_name  = string(player.m_name);
    
}
Player& Player::operator=(const Player& player) 
{
    if(this == &player)
    {
        return *this;
    }
    this->m_level = player.m_level;
    this->m_coins = player.m_coins;
    this->m_force = player.m_force;
    this->m_maxHp = player.m_maxHp;
    this->m_hp    = player.m_hp;

    this->m_name  = string(player.m_name);
    return *this;
}


ostream& operator<<(ostream& os, const Player& player)
{
	s.print(os);
	return os;
}




void Player::levelUp()
{
    if(this->m_level<10)
    {
        this->m_level++;
    }
}
int Player::getLevel()
{
    return this->m_level;
}
int Player::getAttackStrength()
{
    return this->m_force+this->m_level;
}
void Player::buff(int boost)
{   if(boost > 0)
    {
        this->m_force+=boost;
    }
}
void Player::heal(int hpSupply)
{
    if(hpSupply > 0)
    {
        this->m_hp= hpSupply + this->m_hp > this->m_maxHp ? this->m_maxHp : this->m_hp+hpSupply;
    }
}
void Player::damage(int damage)
{
    if(damage > 0)
    {
        this->m_hp = this->m_hp - damage < 0 ? DEAD : this->m_hp-damage;
    }
}
void Player::addCoins(int coins)
{
    if(coins > 0)
    {
        this->m_coins+=coins;
    }
}
bool Player::isKnockedOut()
{
    return !(this->m_hp);
}
bool Player::pay(int payment)
{
    if(payment>this->m_coins)
    {
        return false;
    }
    if(payment > 0)
    {
        this->m_coins-=payment;
    }

    return true;
}



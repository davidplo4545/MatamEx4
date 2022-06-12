#include "Player.h"

Player::Player(string name)
{
    this->m_maxHp = Player::MAX_HP;
    this->m_level = Player::LEVEL;
    this->m_coins = Player::COINS;
    this->m_force =Player::FORCE;
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
    this->m_name = player.m_name;
    
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

    this->m_name  = player.m_name;
    return *this;
}


ostream& operator<<(ostream& os, const Player& player)
{
	player.print(os);
	return os;
}

int Player::getCoins()
{
    return this->m_coins;
}

int Player::getHealth()
{
    return this->m_hp;
}

string Player::getName()
{
    return this->m_name;
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



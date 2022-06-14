#include "Player.h"
using namespace std;
using std::string;
Player::Player(string name, string job):m_name(name), m_job(job),m_level(Player::LEVEL), m_force(Player::FORCE),m_coins(Player::COINS), m_maxHp(Player::MAX_HP), m_hp(Player::MAX_HP)
{}
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

int Player::getCoins() const
{
    return this->m_coins;
}

int Player::getHealth() const
{
    return this->m_hp;
}

string Player::getName() const
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



int Player::getLevel() const
{
    return this->m_level;
}
int Player::getAttackStrength() const
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
bool Player::isKnockedOut() const
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



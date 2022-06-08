#include "Player.h"
using namespace std;
using std::string;

Player::Player(string name, int maxHp, int force):m_name(name)
{
    m_maxHp = maxHp <= 0 ? DEFAULT_HP : maxHp;
    m_level = 1;
    m_coins=0;
    m_force = force <= 0 ? DEFAULT_FORCE : force;
    m_hp = m_maxHp;
}
Player::Player(const Player& player)
{
    m_level = player.m_level;
    m_coins=player.m_coins;
    m_force = player.m_force;
    m_maxHp = player.m_maxHp;
    m_hp = player.m_hp;
    m_name  = string(player.m_name);
}
Player& Player::operator=(const Player& player)
{
    if(this == &player)
    {
        return *this;
    }
    m_level = player.m_level;
    m_coins = player.m_coins;
    m_force = player.m_force;
    m_maxHp = player.m_maxHp;
    m_hp    = player.m_hp;

    m_name  = string(player.m_name);
    return *this;
}
Player::~Player() = default;

void Player::printInfo() const
{
    return;
}
void Player::levelUp()
{
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

string Player::getName() const{
    return m_name;
}

int Player::getHealth() const {
    return m_hp;
}

int Player::getCoins() const {
    return m_coins;
}
int Player::getLevel() const
{
    return m_level;
}
int Player::getAttackStrength() const
{
    return m_force+m_level;
}
void Player::buff(int boost)
{   if(boost > 0)
    {
        m_force+=boost;
    }
}
void Player::heal(int hpSupply)
{
    if(hpSupply > 0)
    {
        m_hp= hpSupply + m_hp > m_maxHp ? m_maxHp : m_hp+hpSupply;
    }
}
void Player::damage(int damage)
{
    if(damage > 0)
    {
        m_hp = m_hp - damage < 0 ? DEAD : m_hp-damage;
    }
}
void Player::addCoins(int coins)
{
    if(coins > 0)
    {
        m_coins+=coins;
    }
}
bool Player::isKnockedOut() const
{
    return !(m_hp);
}
bool Player::pay(int payment)
{
    if(payment>m_coins)
    {
        return false;
    }
    if(payment > 0)
    {
        m_coins-=payment;
    }

    return true;
}

#include "Player.h"
using namespace std;

Player::Player(string name, string job):
    m_name(name), m_job(job)
{
    m_level = Player::LEVEL;
    m_force = Player::FORCE;
    m_coins = Player::COINS;
    m_maxHp = Player::MAX_HP;
    m_hp = Player::MAX_HP;
    m_state = State::PLAYING;
}

void Player::changePlayerState() {
    if(m_level == MAX_LEVEL)
        m_state = State::WON;
    else if(m_hp == DEAD)
        m_state = State::LOST;
}
bool Player::hasWon() const
{
    return m_state == State::WON;
}

bool Player::hasLost() const
{
    return m_state == State::LOST;
}

ostream& operator<<(ostream& os, const Player& player)
{
	player.print(os);
	return os;
}

int Player::getCoins() const
{
    return m_coins;
}

int Player::getHealth() const
{
    return m_hp;
}

string Player::getName() const
{
    return m_name;
}


void Player::levelUp()
{
    if(m_level<10)
    {
        m_level++;
    }
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

void Player::nerf(int damageDecrease)
{   if(damageDecrease > 0 && m_force-damageDecrease >= 0)
    {
        m_force-=damageDecrease;
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



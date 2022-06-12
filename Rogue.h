#include <iostream>

#include "utilities.h"
using namespace std;
using std::string;

#ifndef PLAYER
#define PLAYER
class Player{
    private:
    int m_level, m_force, m_maxHp, m_hp, m_coins;
    string m_name;

    public:
    Player(const string name); // constructor
    Player(const Player&); //copy constructor
    Player& operator=(const Player& player);// assignment

    ~Player();

protected:
    friend ostream& operator<<(ostream& os, const Player& player);
    virtual void print(ostream& os) const = 0;
};
    
    void levelUp();
    int getLevel();
    void buff(int boost);
    virtual void heal(int hpSupply);
    void damage(int damage);
    virtual void addCoins(int coins);
    bool isKnockedOut();
    bool pay(int payment);
    virtual int getAttackStrength();
#endif

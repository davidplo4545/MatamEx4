#include <iostream>

#include "utilities.h"
using namespace std;
using std::string;




#ifndef PLAYER
#define PLAYER
class Player{
    private:

    static const int DEAD = 0;
    static const int FORCE = 5;
    static const int MAX_HP = 100;
    static const int LEVEL = 1;
    static const int COINS = 10;


    int m_level, m_force, m_maxHp, m_hp, m_coins;
    string m_name;

    public:
    Player(const string name); // constructor
    Player(const Player&); //copy constructor
    Player& operator=(const Player& player);// assignment

    ~Player();

protected:
    friend ostream& operator<<(ostream& os, const Player& player);
    
};
    virtual void print(ostream& os) const = 0;

    int getCoins();
    int getHealth();
    string getName();

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

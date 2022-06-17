#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H


#include <cstring>

enum State { PLAYING, LOST, WON };

class Player{
private:
    static const int DEAD = 0;
    static const int FORCE = 5;
    static const int MAX_HP = 100;
    static const int MAX_LEVEL = 10;
    static const int LEVEL = 1;
    static const int COINS = 10;
protected:
    State m_state;
    int m_level, m_force, m_maxHp, m_hp, m_coins;

    std::string m_name, m_job;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

public:
    explicit Player(const std::string name, const std::string job); // constructor

    virtual ~Player() {}
    virtual void print(std::ostream& os) const = 0;

    int getCoins() const;
    int getHealth() const;
    std::string getName() const;

    bool hasWon() const;
    bool hasLost() const;
    void levelUp();
    int getLevel() const;
    void buff(int boost);
    virtual void heal(int hpSupply);
    void damage(int damage);
    virtual void addCoins(int coins);
    bool isKnockedOut() const;
    bool pay(int payment);
    virtual int getAttackStrength() const;
    void changePlayerState();


};

#endif

#ifndef PLAYER
#define PLAYER

#include <iostream>

#include "utilities.h"
#include <string>




class Player{
private:
    int m_level, m_force, m_maxHp, m_hp, m_coins;
    std::string m_name;


public:
    static const int DEAD = 0;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_HP = 100;
    static const int MAX_LEVEL = 10;
    /**
    * C'tor of Player class
    *
    * @param name - The name of the player.
    * @param maxHp - The maximum amount of player's hp.
    * @param force - The numerical value of the player's force.
    * @return
    *      A new instance of Player.
    **/
    Player(const std::string name, int maxHp=100, int force=5); // constructor
    Player(const Player&); //copy constructor
    Player& operator=(const Player& player);// assignment

    ~Player();

    /**
    *   printInfo: Prints all the player's info.
    * @return
    */
    void printInfo() const;
    /**
    *   levelUp: Increases the player's level up to a maximum of 10.
    * @return
    */
    void levelUp();

    /**
    *   getLevel: Returns the player's level.
    * @return
    * 	The current player's level
    */
    int getLevel() const;
    int getHealth() const;
    int getCoins() const;
    string getName() const;
    /**
    *   buff: Boosts the player's force value
    * @param boost - The amount of force to be added.
    * @return
    */
    void buff(int boost);

    /**
    *   heal: Heals the player up to a maximum value of his max hp.
    *
    * @param hpSupply - The amount of hp to be added.
    * @param value - The character which needs to be added.
    * @return
    */
    void heal(int hpSupply);

    /**
    *   damage: Reduces the player's hp by the given amount (minimal value is 0).
    *
    * @param damage - The amount of hp to be reduced.
    * @return
    */
    void damage(int damage);

    /**
    *   addCoins: Adds coins to the player (cannot reduce the coin count).
    *
    * @param coins - The amount of coins to be added.
    * @return
    */
    void addCoins(int coins);

    /**
    *   isKnockedOut: Returns the current player's state of health.
    * @return
    * 	true if the player has 0 hp, otherwise false.
    */
    bool isKnockedOut() const;

    /**
    *   pay: Pays a specific amount of coins. The payment would not be made
    *   if the player does not have enough money.
    *
    * @param payment - The amount of coins to be paid.
    * @return
    * 	true if payment was successfully, otherwise false.
    */
    bool pay(int payment);

    /**
    *   getAttackStrength: Returns the player's strength value.
    *
    * @return
    * 	player's force X player's level.
    */
    int getAttackStrength() const;

};
#endif
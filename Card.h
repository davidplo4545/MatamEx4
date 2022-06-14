#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "Player.h"
#include "utilities.h"
#include "vector"
#include "map"
#include "iostream"

/*
 * Numeric stats of a card.
 */


/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum  CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
protected:
    friend std::ostream& operator<<(std::ostream& os,
                               const Card& card);
    std::string m_name;
public:

    /*
     * C'tor of Card class
     *
     * @param stats - The name of the card.
     * @return
     *      A new instance of Card.
    */
    Card(std::string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printCardInfo(std::ostream& os) const;


    /*
     * C'tor to the "default card"
    */
    Card() = default;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() {};
    Card& operator=(const Card& other) = default;

};






#endif //EX2_Card_H
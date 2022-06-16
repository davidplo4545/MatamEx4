#ifndef MTMCHKIN_H
#define MTMCHKIN_H
#include <iostream>
#include <vector>
#include "Declarations.h"
#include <memory>
#include "Card.h"

template<typename T>
Card* createInstance()
{
    return new T;
}

class Mtmchkin{

private:
    static const int MIN_CARD_COUNT = 5;
    const std::map<std::string, Card*(*)()> CARDS_CONVERTER ={
            {"Fairy",&createInstance<Fairy>},
            {"Goblin",&createInstance<Goblin>},
            {"Vampire",&createInstance<Vampire>},
            {"Dragon",&createInstance<Dragon>},
            {"Merchant",&createInstance<Merchant>},
            {"Pitfall",&createInstance<Pitfall>},
            {"Barfight",&createInstance<Barfight>},
            {"Treasure",&createInstance<Treasure>},
    };

    int m_roundCount = 0;
    std::vector<std::shared_ptr<Player>> m_winners;
    std::vector<std::shared_ptr<Player>> m_losers;
    std::vector<std::shared_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Card>> m_cards;

    void pushToDeck(std::string cardName, int currLine);
    bool isTeamSizeValid(int teamSize) const;
    void initializePlayers();

public:
//                            unique

    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

};



#endif /* MTMCHKIN_H_ */
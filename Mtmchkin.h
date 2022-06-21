#ifndef MTMCHKIN_H
#define MTMCHKIN_H
#include <iostream>
#include <vector>
#include "Declarations.h"
#include <memory>
#include "Cards/Card.h"
#include <deque>

template<typename T>
Card* createCardInstance()
{
    return new T;
}

template<typename T>
BattleCard* createBattleCardInstance()
{
    return new T;
}

template<typename T>
Player* createPlayerInstance(std::string name)
{
    return new T(name);
}

class Mtmchkin{

private:
    static const int MIN_CARD_COUNT = 5;
    const std::string END_GANG = "EndGang";
    const std::string START_GANG = "Gang";
    const std::map<std::string, Card*(*)()> CARDS_CONVERTER ={
            {"Fairy",&createCardInstance<Fairy>},
            {"Gang",&createCardInstance<Gang>},
            {"Goblin",&createCardInstance<Goblin>},
            {"Vampire",&createCardInstance<Vampire>},
            {"Dragon",&createCardInstance<Dragon>},
            {"Merchant",&createCardInstance<Merchant>},
            {"Pitfall",&createCardInstance<Pitfall>},
            {"Barfight",&createCardInstance<Barfight>},
            {"Treasure",&createCardInstance<Treasure>},
    };

    const std::map<std::string, BattleCard*(*)()> BATTLE_CARDS_CONVERTER ={
            {"Goblin",&createBattleCardInstance<Goblin>},
            {"Vampire",&createBattleCardInstance<Vampire>},
            {"Dragon",&createBattleCardInstance<Dragon>},
    };

    const std::map<std::string, Player*(*)(std::string)> PLAYER_CONVERTER ={
            {"Wizard",&createPlayerInstance<Wizard>},
            {"Fighter",&createPlayerInstance<Fighter>},
            {"Rogue",&createPlayerInstance<Rogue>},
    };

    int m_roundCount = 0;
    int m_currCard = 0;
    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;
    std::deque<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Card>> m_cards;

    void pushToDeck(std::string cardName, int currLine);
    void pushGangToDeck(std::ifstream &source, int currLine);
    static bool isTeamSizeValid(int teamSize);
    void initializePlayers();
    void initializeCards(std::string fileName);

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
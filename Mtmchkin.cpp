#include "Mtmchkin.h"
#include "fstream"
#include "iostream"
#include "Declarations.h"
#include "Exception.h"
#include "utilities.h"
using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> split(string str)
{
    vector<string> result;
    string spaceDel = " ";
    int spacePos = 0;
    string temp;
    while(spacePos != -1)
    {
        spacePos = str.find(spaceDel);
        result.push_back(str.substr(0,spacePos));
        str.erase(0,spacePos+1);
    }
    return result;
}

Mtmchkin::Mtmchkin(const std::string fileName)
{

    ifstream source(fileName);
    if(!source)
    {
        throw DeckFileNotFound();
    }
    string cardName;
    int cardCount=0;

    try{
        while (getline(source, cardName, '\n'))
        {
            cardCount += 1;
            pushToDeck(cardName, cardCount);
        }

    } catch(const std::ios_base& e){

    }
    if (cardCount<Mtmchkin::MIN_CARD_COUNT)
    {
        throw DeckFileInvalidSize();
    }
    this->initializePlayers();
};


void Mtmchkin::pushToDeck(string cardName, int cardCount)
{
    try{
        unique_ptr<Card> newCard(Mtmchkin::CARDS_CONVERTER.at(cardName)());
        m_cards.push_back(move(newCard));
    }
    catch(std::exception& e)
    {
        throw(DeckFileFormatError(cardCount));
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

bool isValidString(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(!isalpha(str[i]))
        {
            return false;
        }
    }
    return str.size() <= 15;
}
void Mtmchkin::initializePlayers()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int numberOfPlayers = 0;
    while(!isTeamSizeValid(numberOfPlayers))
    {
        cin >> numberOfPlayers;
        cin.ignore(1000, '\n');

        if(!isTeamSizeValid(numberOfPlayers))
        {
            printInvalidTeamSize();
        }
    }
    string playerDetails;
    bool isCreated = false;

    for(int i=0; i<numberOfPlayers; i++)
    {
        printInsertPlayerMessage();
        isCreated = false;
        vector<string> words;
        while(!isCreated)
        {
            getline(std::cin,playerDetails);

            words = split(playerDetails);
            if(words.size() != 2)
            {
                printInvalidName();
                continue;
            }
            if(!isValidString(words[0]))
            {
                printInvalidName();
                continue;
            }
            if(!isValidString(words[1]) )
            {
                printInvalidClass();
                continue;
            }
            try{
                m_players.push_back(unique_ptr<Player>(PLAYER_CONVERTER.at(words[1])(words[0])));
            }
            catch(const exception& e){
                printInvalidClass();
                continue;
            };

            isCreated = true;
        }
    }
}

bool Mtmchkin::isTeamSizeValid(int teamSize)
{
    return (teamSize>=2 && teamSize<=6);
}

bool Mtmchkin::isGameOver() const {
    return m_players.empty();
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;
    int length = m_winners.size();
    for(int i=0;i<length;i++)
    {
        printPlayerLeaderBoard(ranking, *m_winners[i]);
        ranking+=1;
    }
    length = m_players.size();
    for(int i=0;i<length;i++)
    {
        printPlayerLeaderBoard(ranking, *m_players[i]);
        ranking-=-1;
    }
    length = m_losers.size();
    for(int i=length-1;i>=0;i--)
    {
        printPlayerLeaderBoard(ranking, *m_losers[i]);
        ranking+=1;

    }
}


void Mtmchkin::playRound() {
    m_roundCount+=1;

    int numPlayers = m_players.size();
    printRoundStartMessage(m_roundCount);
    for (int i = 0; i < numPlayers; i++) {
        printTurnStartMessage(m_players.front()->getName());

        m_cards[m_currCard]->applyEncounter(*m_players.front());
        m_players.front()->changePlayerState();
        if(m_players.front()->hasWon())
        {
            m_winners.push_back(move(m_players.front()));
            m_players.pop_front();
        }
        else if(m_players.front()->hasLost())
        {

            m_losers.push_back(move(m_players.front()));
            m_players.pop_front();
        }
        else
        {
            unique_ptr<Player> tempPlayer = move(m_players.front());
            m_players.pop_front();
            m_players.push_back(move(tempPlayer));
        }
        if(isGameOver())
        {
            printGameEndMessage();
            return;
        }

        m_currCard = (m_currCard + 1) % (m_cards.size());
    }
}



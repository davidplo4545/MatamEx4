#include "Mtmchkin.h"
#include "fstream"
#include "iostream"
#include "Declarations.h"
#include "Exception.h"
#include "utilities.h"
using namespace std;

vector<string> Mtmchkin::split(string str)
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

    printStartGameMessage();
    this->initializeCards(fileName);
    this->initializePlayers();
}

int Mtmchkin::pushGangToDeck(ifstream &source, int currCount)
{
    bool isGang = true;
    unique_ptr<Gang> tempGang = unique_ptr<Gang>(new Gang());
    int tempCount=currCount;
    string cardName;
    while (isGang && getline(source, cardName, '\n'))
    {
        if(cardName == END_GANG)
        {
            isGang = false;
            break;
        }
        try
        {
            unique_ptr<BattleCard> newBattleCard(Mtmchkin::BATTLE_CARDS_CONVERTER.at(cardName)());
            tempGang->pushToGang(move(newBattleCard));
        }
        catch(exception& e)
        {
            throw(DeckFileFormatError(tempCount+1));
        }
        tempCount++;

    }
    if(isGang)
    {
        throw DeckFileFormatError(tempCount+1);
    }
    m_cards.push_back(move(tempGang));
    return tempCount;
}

void Mtmchkin::initializeCards(string fileName) {
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
            if(cardName == START_GANG) {
                cardCount = pushGangToDeck(source,cardCount+1);
            }
            else
            {
                pushToDeck(cardName, cardCount+1);
            }
            cardCount += 1;
        }
    } catch(const std::ios_base& e){

    }
    if (m_cards.size()<Mtmchkin::MIN_CARD_COUNT)
    {
        throw DeckFileInvalidSize();
    }
}


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

bool Mtmchkin::isValidString(string str)
{
    int len = str.size();
    for(int i=0;i<len;i++)
    {
        if(!isalpha(str[i]))
        {
            return false;
        }
    }
    return str.size() <= MAX_NAME_LEN;
}

bool Mtmchkin::isValidNumber(string str)
{
    int len = str.size();
    for(int i=0;i<len;i++)
    {
        if(!isdigit(str[i]))
        {
            return false;
        }
    }
    return str.size() == 1;
}

void Mtmchkin::createPlayers(int numberOfPlayers)
{
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
            if(words.size() != 2 || !isValidString(words[0]))
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
void Mtmchkin::initializePlayers()
{
    printEnterTeamSizeMessage();
    int numberOfPlayers = 0;
    while(!isTeamSizeValid(numberOfPlayers))
    {
        string input;
        getline(cin, input);
        if(!isValidNumber(input))
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            continue;
        }
        numberOfPlayers = stoi(input);
        if(!isTeamSizeValid(numberOfPlayers))
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    createPlayers(numberOfPlayers);
}

bool Mtmchkin::isTeamSizeValid(int teamSize)
{
    return (teamSize>=MIN_TEAM_SIZE && teamSize<=MAX_TEAM_SIZE);
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

void Mtmchkin::movePlayer()
{
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
}
void Mtmchkin::playRound() {
    m_roundCount+=1;

    int numPlayers = m_players.size();
    printRoundStartMessage(m_roundCount);
    for (int i = 0; i < numPlayers; i++) {
        printTurnStartMessage(m_players.front()->getName());

        m_cards[m_currCard]->applyEncounter(*m_players.front());
        m_players.front()->changePlayerState();
        movePlayer();
        if(isGameOver())
        {
            printGameEndMessage();
            return;
        }

        m_currCard = (m_currCard + 1) % (m_cards.size());
    }
}

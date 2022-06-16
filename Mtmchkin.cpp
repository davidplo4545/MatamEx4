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
        cout << str.substr(0,spacePos) << endl;
        str.erase(0,spacePos+1);
    }
    return result;
}

Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream fileReader(fileName);
    string cardName;
    try{
        int cardCount=0;
        while (getline(fileReader, cardName, '\n'))
        {
            cardCount += 1;
            pushToDeck(cardName, cardCount);
            m_cards[cardCount-1]->printCardInfo(cout);
        }

        if (cardCount<Mtmchkin::MIN_CARD_COUNT)
        {
            throw DeckFileInvalidSize();
        }
    } catch(std::ios::failure& e){
            std::cout<<e.what();
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
            m_players.push_back(shared_ptr<Player>(new Wizard(words[0])));
            isCreated = true;
            cout << words[0] <<" has been successfuly created";
        }
    }
}

bool Mtmchkin::isTeamSizeValid(int teamSize) const
{
    return (teamSize>=2 && teamSize<=6);
}



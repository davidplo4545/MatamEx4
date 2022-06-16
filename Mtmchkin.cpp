#include "Mtmchkin.h"
#include "fstream"
#include "iostream"
#include "Exception.h"
using namespace std;


Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream fileReader(fileName);
    string cardName;
try{
        int currLine=0;
    while (getline(fileReader, cardName, '\n'))
    {
        currLine += 1;
        pushToDeck(cardName, currLine);
    }
    if (currLine<5)
    {
    throw DeckFileInvalidSize();
    }

} catch(std::exception& e){
        std::cout<<e.what();
}
};


void Mtmchkin::pushToDeck(string cardName, int currLine)
{
        if(cardName == "Fairy")
        {
                m_cards.push_back(unique_ptr<Card>(new Fairy()));
        }
        else if(cardName == "Barfight")
        {
                m_cards.push_back(unique_ptr<Card>(new Barfight()));
        }
        else if(cardName == "Dragon")
        {
                m_cards.push_back(unique_ptr<Card>(new Dragon()));
        }
        else if(cardName == "Goblin")
        {
                m_cards.push_back(unique_ptr<Card>(new Goblin()));
        }
        else if(cardName == "Merchant")
        {
                m_cards.push_back(unique_ptr<Card>(new Merchant()));
        }
        else if(cardName == "Pitfall")
        {
                m_cards.push_back(unique_ptr<Card>(new Pitfall()));
        }
        else if(cardName == "Treasure")
        {
                m_cards.push_back(unique_ptr<Card>(new Treasure()));
        }
        else if(cardName == "Dragon")
        {
                m_cards.push_back(unique_ptr<Card>(new Dragon()));
        }


        else
        {
                throw(DeckFileFormatError(currLine));
        }
                

}





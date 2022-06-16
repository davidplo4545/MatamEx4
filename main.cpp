#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Card.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Goblin.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>
#include "Mtmchkin.h"
using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;

bool lightTestCard()
{
    Goblin* gCard = new Goblin();
    cout << *gCard;
    return false;
}
bool testCard()
{
    vector<unique_ptr<Card>> cards;
    cards.push_back(unique_ptr<Card>(new Goblin()));

    cards.push_back(unique_ptr<Card>(new Vampire()));
    cards.push_back(unique_ptr<Card>(new Dragon()));
    cards.push_back(unique_ptr<Card>(new Goblin()));
    cards.push_back(unique_ptr<Card>(new Goblin()));
    cards.push_back(unique_ptr<Card>(new Vampire()));
    cards.push_back(unique_ptr<Card>(new Vampire()));
    cards.push_back(unique_ptr<Card>(new Dragon()));
    for(unique_ptr<Card>& card : cards){
        cout << *card;
    }
    cards.erase(cards.begin(),cards.end());
    return true;
}

void testMtmchkin()
{
    Mtmchkin mtmchkin = Mtmchkin("input.txt");
}

int main() {
#include "Exception.h"
//    testMtmchkin();
    // try{
    //     throw DeckFileNotFound();
    // }
    // catch(const DeckFileNotFound& e)
    // {
    //     cout <<e.what();
    // }

    Mtmchkin test("input.txt");
   // testCard();
    return 0;
}

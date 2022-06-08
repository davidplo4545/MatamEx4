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
int main() {

    testCard();
    return 0;
}

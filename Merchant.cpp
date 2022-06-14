//
// Created by David on 08/06/2022.
//

#include "Merchant.h"
#include "Card.h"
#include "Player.h"

Merchant::Merchant():Card("Merchant"){}

bool Merchant::applySelectedOption(int option, Player &player) const {
    bool isSuccessful = false;
    if (option == 1) // Heal
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.heal(Merchant::STORE.at(option)[1]);
            isSuccessful = true;
        }
        else{
            printMerchantInsufficientCoins(cout);
        }
    }
    else if(option == 2) // Buff
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.buff(Merchant::STORE.at(option)[1]);
            isSuccessful = true;
        }
        else
        {
            printMerchantInsufficientCoins(cout);
        }
    }
    else if(option == 0)
    {
        isSuccessful = true;
    }

    return isSuccessful;
}
void Merchant::applyEncounter(Player &player) const {
    bool hasTransacted = false;
    string userInput;
    int option = -1;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(),player.getCoins());
    while(!hasTransacted)
    {
        try
        {
            getline(cin,userInput);
            option=stoi(userInput);
            if(option >= 0 && option <=2)
            {
                bool isSuccessful = applySelectedOption(option, player);
                hasTransacted = isSuccessful;
            }
            else
            {
                printInvalidInput();
            }
        }
        catch(std::exception const& ex)
        {
            printInvalidInput();
            continue;
        }
    }

}
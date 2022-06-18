//
// Created by David on 08/06/2022.
//

#include "Merchant.h"
using std::string;
Merchant::Merchant():Card("Merchant"){}

bool Merchant::applySelectedOption(int option, Player &player) const {
    bool isSuccessful = false;
    if (option == 1) // Heal
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.heal(Merchant::STORE.at(option)[1]);
            player.pay(Merchant::STORE.at(option)[0]);
            printMerchantSummary(std::cout, player.getName(),option,Merchant::STORE.at(option)[0]);
            isSuccessful = true;
        }
        else{
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(option == 2) // Buff
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.buff(Merchant::STORE.at(option)[1]);
            player.pay(Merchant::STORE.at(option)[0]);
            printMerchantSummary(std::cout, player.getName(),option,Merchant::STORE.at(option)[0]);
            isSuccessful = true;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if(option == 0)
    {
        printMerchantSummary(std::cout, player.getName(),option,option);
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
            getline(std::cin,userInput);
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
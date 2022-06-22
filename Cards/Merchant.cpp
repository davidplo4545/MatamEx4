//
// Created by David on 08/06/2022.
//

#include "Merchant.h"
using std::string;
Merchant::Merchant():Card("Merchant"){}

void Merchant::applySelectedOption(int option, Player &player) const {
    if (option == HEAL_OPTION) // Heal
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.heal(Merchant::STORE.at(option)[1]);
            player.pay(Merchant::STORE.at(option)[0]);
            printMerchantSummary(std::cout, player.getName(),option,Merchant::STORE.at(option)[0]);
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), option, NO_MONEY);
        }
    }
    else if(option == BUFF_OPTION) // Buff
    {
        if(player.getCoins() >= Merchant::STORE.at(option)[0])
        {
            player.buff(Merchant::STORE.at(option)[1]);
            player.pay(Merchant::STORE.at(option)[0]);
            printMerchantSummary(std::cout, player.getName(),option,Merchant::STORE.at(option)[0]);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getName(), option, NO_MONEY);
        }
    }
    else if(option == NONE_OPTION)
    {
        printMerchantSummary(std::cout, player.getName(),option,option);
    }
}

bool Merchant::isValidNumber(string str)
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
            if(!isValidNumber(userInput))
            {
                printInvalidInput();
                continue;
            }
            option=stoi(userInput);
            if(option >= NONE_OPTION && option <=BUFF_OPTION)
            {
                applySelectedOption(option, player);
                hasTransacted = true;
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
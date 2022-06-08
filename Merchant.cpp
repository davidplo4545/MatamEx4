//
// Created by David on 08/06/2022.
//

#include "Merchant.h"
#include "Card.h"

Merchant::Merchant():Card("Merchant"){}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(),player.getCoins());
}
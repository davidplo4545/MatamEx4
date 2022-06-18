//
// Created by David on 08/06/2022.
//
#ifndef MATAMEX4_DRAGON_H
#define MATAMEX4_DRAGON_H
#include "BattleCard.h"


class Dragon: public BattleCard{
public:
    Dragon();
    void printCardInfo(std::ostream& os) const override;
};


#endif //MATAMEX4_DRAGON_H

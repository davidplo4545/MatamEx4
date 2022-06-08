//
// Created by David on 08/06/2022.
//

#ifndef MATAMEX4_PITFALL_H
#define MATAMEX4_PITFALL_H


class Pitfall :public Card{
    const int DAMAGE = 10;
public:
    Pitfall();
    void applyEncounter(Player& player) const override;
};


#endif //MATAMEX4_PITFALL_H

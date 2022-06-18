#ifndef FIGHTER_EX4
#define FIGHTER_EX4

#include "Player.h"
#include "string.h"
class Fighter: public Player {
public:
    Fighter(std::string name);
    int getAttackStrength() const override;

protected:
	void print(std::ostream& os) const override;
};

#endif
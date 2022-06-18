#ifndef ROGUE_EX4
#define ROGUE_EX4

#include "Player.h"
#include "string.h"

class Rogue: public Player {
public:
	Rogue(std::string name);
    void addCoins(int coins) override;

protected:
    void print(std::ostream& os) const override;
};

#endif
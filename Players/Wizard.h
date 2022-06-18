#ifndef WIZARD_EX4
#define WIZARD_EX4
#include "Player.h"
#include "string.h"
#include <iostream>
class Wizard: public Player {
public:
    Wizard(std::string name);
    void heal(int hpSupply) override;
protected:
	void print(std::ostream& os) const override;
};

#endif
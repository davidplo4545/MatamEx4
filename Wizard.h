#include "Player.h"

class Wizard: public Player {
private:
    static const string JOB = "Wizard";
public:
	
    void Player::heal(int hpSupply) override;

protected:
	void print(ostream& os) const override;


};
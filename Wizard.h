#include "Player.h"

class Wizard: public Player {
private:
    const string job = "Wizard";
public:
	
    virtual void Player::heal(int hpSupply) override;

protected:
	virtual void print(ostream& os) const override;


};
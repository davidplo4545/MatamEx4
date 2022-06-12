#include "Player.h"

class Rogue: public Player {
private:
    const string job = "Rogue";
public:
	
    virtual void Player::addCoins(int coins) override;

protected:
	virtual void print(ostream& os) const override;


};
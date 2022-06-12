#include "Player.h"

class Rogue: public Player {
private:
    static const string JOB = "Rogue";
public:
	
    void Player::addCoins(int coins) override;

protected:
    void print(ostream& os) const override;


};
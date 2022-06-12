#include "Player.h"

class Fighter: public Player {
private:
    const string JOB = "Fighter";
public:
	
    void Player::getAttackStrength() override;

protected:
	void print(ostream& os) const override;


};
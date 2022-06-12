#include "Player.h"

class Fighter: public Player {
private:
    const string job = "Fighter";
public:
	
    virtual void Player::getAttackStrength() override;

protected:
	virtual void print(ostream& os) const override;


};
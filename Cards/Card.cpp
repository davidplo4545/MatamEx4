#include "Card.h"
#include "../utilities.h"
using namespace std;
using std::string;

std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.printCardInfo(os);
    return os;
}

Card::Card(string name):
    m_name(name){
}

void Card::printCardInfo(ostream& os) const {
    printCardDetails(os, m_name);
    printEndOfCardDetails(cout);
}

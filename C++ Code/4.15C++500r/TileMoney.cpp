
#include "TileMoney.h"
#include "Tile.h"

TileMoney::TileMoney(unsigned int money1) : money(money1) {}

TileMoney::TileMoney(const TileMoney &to_copy){
    cout << "assignment operator" << endl;
    this->money = to_copy.money;
}

TileMoney &TileMoney::operator=(const TileMoney &to_copy) {
    cout << "assignment operator" << endl;
//    this->name = to_copy.name;
//    this->owner = to_copy.owner;
    this->money = to_copy.money;
    return *this;
}

TileMoney::~TileMoney() {

}

Tile * TileMoney::getClone() const {
    return new TileMoney(*this);
}

void TileMoney::print() const {
    printOwnerChar();
    if (this->genus == 0) {
        cout << "$";
    } else if(this->genus == GENUS_POINTS){
        cout << "*";
    }else if(this->genus == GENUS_DICE){
        cout<<"#";
    }
    if (this->owner == NO_OWNER) {
        cout << " ";
    } else {
        cout << owner;
    }

}

void TileMoney::activate(unsigned int who_rolled, const CellId &cell, Board &board) const {

}



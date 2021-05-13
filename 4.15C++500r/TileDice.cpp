
#include "TileDice.h"
#include "Tile.h"

TileDice::TileDice(unsigned int money1) : money(money1) {}

TileDice::TileDice(const TileDice &to_copy){
    cout << "assignment operator" << endl;
    this->money = to_copy.money;
}

TileDice &TileDice::operator=(const TileDice &to_copy) {
    cout << "assignment operator" << endl;
//    this->name = to_copy.name;
//    this->owner = to_copy.owner;
    this->money = to_copy.money;
    return *this;
}

TileDice::~TileDice() {

}

Tile * TileDice::getClone() const {
    return new TileDice(*this);
}

void TileDice::print() const {
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

void TileDice::activate(unsigned int who_rolled, const CellId &cell, Board &board) const {

}



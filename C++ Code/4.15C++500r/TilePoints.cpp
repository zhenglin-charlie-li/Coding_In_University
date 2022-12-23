
#include "TilePoints.h"
#include "Tile.h"

TilePoints ::TilePoints (unsigned int money1) : money(money1) {}

TilePoints ::TilePoints (const TilePoints  &to_copy){
    cout << "assignment operator" << endl;
    this->money = to_copy.money;
}

TilePoints  &TilePoints ::operator=(const TilePoints  &to_copy) {
    cout << "assignment operator" << endl;
//    this->name = to_copy.name;
//    this->owner = to_copy.owner;
    this->money = to_copy.money;
    return *this;
}

TilePoints ::~TilePoints () {

}

Tile * TilePoints ::getClone() const {
    return new TilePoints (*this);
}

void TilePoints ::print() const {
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

void TilePoints ::activate(unsigned int who_rolled, const CellId &cell, Board &board) const {

}



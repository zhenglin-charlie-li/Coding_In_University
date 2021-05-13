#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


#include "Player.h"
#include "CellId.h"
#include "BoardSize.h"
#include "Tile.h"

using namespace std;

Tile::Tile() {
    this->owner = NO_OWNER;
}

void Tile::Create(unsigned int genus1, unsigned int species1) {
    assert(genus1 < GENUS_COUNT);
    this->owner = NO_OWNER;
}


void Tile::setOwner(unsigned int owner1) {
    this->owner = owner1;
}

bool Tile::isOwner() const {
    return this->owner != NO_OWNER;
}

unsigned int Tile::getAffectedPlayer(unsigned int whose_turn) const {
    if (this->owner == NO_OWNER)
        return whose_turn;
    else
        return this->owner;
}

void Tile::activate(unsigned int whose_turn) const {
    //playerIncreaseDiceAndPrint(playerGetIndex(playerGetName(whose_turn)),)
}

void Tile::print() const {
    printOwnerChar();
}

void Tile::printOwnerChar() const {
    if (this->owner == NO_OWNER) {
        cout << " ";
    } else {
        cout << owner;
    }
}

Tile::Tile(const Tile &to_copy) {
    this->name = to_copy.name;
    this->owner = to_copy.owner;
}

Tile::~Tile() {
    cout << "Object is being deleted" << endl;
}

Tile &Tile::operator=(const Tile &to_copy) {
    cout << "assignment operator" << endl;
    this->name = to_copy.name;
    this->owner = to_copy.owner;
    return *this;
}


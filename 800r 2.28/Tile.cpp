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
    this->genus = GENUS_MONEY;
    this->species = 1;
    assert(isInvariantTrue());
}

Tile::Tile(unsigned int genus1, unsigned int species1) {
    Create(genus1, species1);
    assert(isInvariantTrue());
}

void Tile::Create(unsigned int genus1, unsigned int species1) {
    assert(genus1 < GENUS_COUNT);
    this->owner = NO_OWNER;
    this->genus = genus1;
    this->species = species1;
}

bool Tile::isInvariantTrue() const {
    return genus < GENUS_COUNT;
}

void Tile::setOwner(unsigned int owner1) {
    assert(isInvariantTrue());
    this->owner = owner1;
}

bool Tile::isOwner() const {
    assert(isInvariantTrue());
    return this->owner != NO_OWNER;
}

unsigned int Tile::getAffectedPlayer(unsigned int whose_turn) const {
    assert(isInvariantTrue());
    if (this->owner == NO_OWNER)
        return whose_turn;
    else
        return this->owner;
}

unsigned int Tile::getGenus() const {
    assert(isInvariantTrue());
    return this->genus;
}

unsigned int Tile::getSpecies() const {
    assert(isInvariantTrue());
    return this->species;
}

void Tile::activate(unsigned int whose_turn) const {
    assert(isInvariantTrue());
    //not sure
}

void Tile::print() const {
    assert(isInvariantTrue());
    printOwnerChar();
    printGenusChar();
    printSpeciesChar();
}

void Tile::printOwnerChar() const {
    if (this->owner == NO_OWNER) {
        cout << " ";
    } else {
        cout << owner;
    }
}

void Tile::printGenusChar() const {
    if (this->owner == GENUS_MONEY) {
        cout << "$";
    } else {
        cout << "*";
    }
}

void Tile::printSpeciesChar() const {
    cout << species;
}

CellId toCellId(int row, int column) {
    return CellId::toCellId( row,  column);
}

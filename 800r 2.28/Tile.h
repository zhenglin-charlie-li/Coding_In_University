

#pragma once
#include <string>
#include "CellId.h"
const int NO_OWNER = -1;
const unsigned int GENUS_MONEY = 0;
const unsigned int GENUS_COUNT = 4;
const unsigned int GENUS_BOMB = 3;
const unsigned int GENUS_DICE = 1;
const unsigned int GENUS_POINTS = 1;



using namespace std;

class Tile {
private:
    string name;
    unsigned int owner;
    unsigned int genus;
    unsigned int species;

    void printOwnerChar() const;

    void printGenusChar() const;

    void printSpeciesChar() const;

    bool isInvariantTrue() const;

    void Create(unsigned int genus1, unsigned int species1);

public:
    Tile();

    Tile(unsigned int genus1, unsigned int species1);

    bool isOwner() const;

    unsigned int getAffectedPlayer(
            unsigned int whose_turn) const;

    unsigned int getGenus() const;

    unsigned int getSpecies() const;

    void setOwner(unsigned int owner1);

    void activate(unsigned int whose_turn) const;

    void print() const;


};

CellId toCellId(int row, int column);
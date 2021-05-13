

#pragma once

#include <string>
#include "CellId.h"
class Board;
const int NO_OWNER = -1;
const unsigned int GENUS_COUNT = 4;
const unsigned int GENUS_DICE = 2;
const unsigned int GENUS_POINTS = 1;


using namespace std;

class Tile {
private:
    string name;

    void Create(unsigned int genus1, unsigned int species1);


protected:
    void printOwnerChar() const;

    unsigned int owner;
    unsigned int genus;
public:
    Tile();

    Tile(const Tile &to_copy);

    virtual ~Tile();

    Tile &operator=(const Tile &to_copy);

//    virtual Tile *getClone() const =0;

    bool isOwner() const;

    unsigned int getAffectedPlayer(
            unsigned int whose_turn) const;

    void setOwner(unsigned int owner1);

//    virtual void activate(unsigned int who_rolled,
//                          const CellId &rolled_cell,
//                          Board &board) const =0;

    virtual void print() const ;


    void activate(unsigned int whose_turn) const;



};

CellId toCellId(int row, int column);
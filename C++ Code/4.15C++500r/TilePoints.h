#pragma once
#include "Tile.h"

using namespace std;

class TilePoints  : public Tile {
private:
    unsigned int money;
public:
    explicit TilePoints (unsigned int money1);

    TilePoints (const TilePoints  &to_copy);

    virtual ~TilePoints ();

    TilePoints  &operator=(const TilePoints  &to_copy);

    virtual Tile *getClone() const;

    virtual void activate(unsigned int who_rolled,
                          const CellId &cell,
                          Board &board) const;

    virtual void print() const;

};
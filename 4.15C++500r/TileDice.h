#pragma once

#include "Tile.h"

using namespace std;

class TileDice : public Tile {
private:
    unsigned int money;
public:
    explicit TileDice(unsigned int money1);

    TileDice(const TileDice &to_copy);

    virtual ~TileDice();

    TileDice &operator=(const TileDice &to_copy);

    virtual Tile *getClone() const;

    virtual void activate(unsigned int who_rolled,
                          const CellId &cell,
                          Board &board) const;

    virtual void print() const;

};
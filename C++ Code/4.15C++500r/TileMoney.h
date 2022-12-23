#pragma once
#include "Tile.h"

using namespace std;

class TileMoney : public Tile {
private:
    unsigned int money;
public:
    explicit TileMoney(unsigned int money1);

    TileMoney(const TileMoney &to_copy);

    virtual ~TileMoney();

    TileMoney &operator=(const TileMoney &to_copy);

    virtual Tile *getClone() const;

    virtual void activate(unsigned int who_rolled,
                          const CellId &cell,
                          Board &board) const;

    virtual void print() const;

};
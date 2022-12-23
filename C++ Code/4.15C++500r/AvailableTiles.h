#pragma once

#include "Tile.h"

const unsigned int AVAILABLE_TILE_COUNT = 5;

class AvailableTiles {
private:
    Tile available_tile[5];
    int available_tile_cost[5];

    void setRandomTile(unsigned int index);


public:
    AvailableTiles();

    void print() const;

    int getCost(unsigned int index) const;

    const Tile &getTile(unsigned int index) const;

    void replaceAt(unsigned int index);


};
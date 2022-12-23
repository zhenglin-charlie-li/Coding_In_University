
#include <cassert>
#include <iostream>
#include "AvailableTiles.h"


void AvailableTiles::setRandomTile(unsigned int index) {
    assert(index < AVAILABLE_TILE_COUNT);
    int P = rand()%3+1;
    available_tile[index]=Tile(1,P);//not sure
    available_tile_cost[index]=P*P;
}

AvailableTiles::AvailableTiles() {
    for (int i=0;i<AVAILABLE_TILE_COUNT;i++) {
        setRandomTile(i);
    }
}

int AvailableTiles::getCost(unsigned int index) const {
    assert(index < AVAILABLE_TILE_COUNT);
    return available_tile_cost[index];
}

const Tile &AvailableTiles::getTile(unsigned int index) const {
    assert(index < AVAILABLE_TILE_COUNT);
    return available_tile[index];
}

void AvailableTiles::replaceAt(unsigned int index) {
    assert(index < AVAILABLE_TILE_COUNT);
    for (int i=index;i<AVAILABLE_TILE_COUNT-1;i++) {
        available_tile[i]=available_tile[i+1];
    }
    setRandomTile(AVAILABLE_TILE_COUNT-1);
}

void AvailableTiles::print() const {
    for (int i = 0; i < AVAILABLE_TILE_COUNT; ++i) {
        cout <<"  " << i <<" :  "<<available_tile[i].getGenus()<<"   $"<<available_tile[i].getSpecies()*available_tile[i].getSpecies()<<endl;
    }
}
#pragma once

#include "BoardSize.h"
#include "Tile.h"
#include "CellId.h"

class Board {
private:
    Tile board_member[BOARD_SIZE][BOARD_SIZE]{};

    static void printColumnNameRow() ;

    static void printBorderRow() ;

    static void printEmptyRow() ;

    void printDataRow(int row) const;

    static bool check_cell_on_board(const CellId &cell_id) ;
public:
    Board();

    void print() const;

    const Tile &getAt(const CellId &cell_id) const;

    void setAt(const CellId &cell_id, const Tile &value, unsigned int owner);
};



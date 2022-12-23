
#include "CellId.h"

CellId::CellId(int row, int column) {
    this->row = row;
    this->column = column;
}

int CellId::getColumn() const {
    return column;
}

int CellId::getRow() const {
    return row;
}

CellId CellId::toCellId(int row, int column) {
    return { row,  column};
}

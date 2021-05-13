
#pragma once



class CellId {
private:
    int row;
    int column;
public:
    CellId(int row, int column);
    int getColumn() const;
    int getRow() const;
    static CellId toCellId(int row, int column);
};
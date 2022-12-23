
#pragma once


#include<iostream>
using namespace std;

class CellId {
private:
public:
    CellId(int row, int column);

    int row;
    int column;
    CellId();

    int getColumn() const;
    int getRow() const;
    static CellId toCellId(int row, int column);
};
CellId toCellId (int row1, int column1);
CellId toCellId (const std::string& str);
bool isOnBoard (const CellId& cell_id);
bool isOnBoard (const std::string& str);
ostream& operator<< (ostream& out,const CellId& cell_id);
bool operator== (const CellId& lhs,const CellId& rhs);
bool operator< (const CellId& lhs,const CellId& rhs);
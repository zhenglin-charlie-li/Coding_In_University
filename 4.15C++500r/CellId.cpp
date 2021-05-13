
#include "CellId.h"
#include "Board.h"

using namespace std;

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

bool operator==(const CellId &lhs, const CellId &rhs) {
    if(lhs.getRow()==rhs.getRow()&&lhs.getColumn()==rhs.getColumn())return true;
    else return false;
}

bool operator<(const CellId &lhs, const CellId &rhs) {
    if(lhs.getRow()<rhs.getRow())return true;
    else if(lhs.getRow()>rhs.getRow())return false;
    if(lhs.getColumn()<rhs.getColumn())return true;
    else if(lhs.getColumn()>rhs.getColumn())return false;
    return false;
}

ostream &operator<<(std::ostream &out, const CellId &cell_id) {
    return out << getRowName(cell_id.getRow()) << getColumnName(cell_id.getColumn());
}

CellId::CellId() {}
CellId toCellId(int row1, int column1) {
    return { row1,  column1};
}
CellId toCellId (const std::string& str){
    int col;
    if(str[2]>='0'&&str[2]<='9')col=(str[1]-'0')*10+str[2]-'0';
    else if(str[1]<'0'||str[1]>'9')col=999;
    else col=str[1]-'0';
    return {str[0]-'A',col};
}
bool isOnBoard (const CellId& cell_id){
    if(cell_id.getRow()<7&&cell_id.getRow()>=0&&cell_id.getColumn()<7&&cell_id.getColumn()>=0)return true;
    return false;
}
bool isOnBoard (const std::string& str){
    CellId cell_id=toCellId(str);
    if(cell_id.getRow()<7&&cell_id.getRow()>=0&&cell_id.getColumn()<7&&cell_id.getColumn()>=0)return true;
    return false;
}
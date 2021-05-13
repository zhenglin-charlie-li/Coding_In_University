#include <cassert>
#include "CellChooser.h"
#include "Board.h"

CellChooser::CellChooser(int row1_roll, int row2_roll, int column1_roll, int column2_roll, int extra_roll,bool is_extra){
    calculateAllAvailable(row1_roll,row2_roll,column1_roll,column2_roll,extra_roll,is_extra);
    selectionSort();
    if(this->count==1)this->chosenCell=this->cellIds[0];
    else this->chosenCell=NOT_CHOSEN;
}
bool CellChooser::isChosen () const{
    assert(isInvariantTrue ());
    return !(NOT_CHOSEN == this->chosenCell);
}
void CellChooser::calculateAllAvailable (int row1_roll,int row2_roll,int column1_roll,int column2_roll,int extra_roll,bool is_extra){
    if(!is_extra){
        addAvailableCell(toCellId(row1_roll+row2_roll,column1_roll+column2_roll));
        return;
    }
    addAvailableCell(toCellId(extra_roll+row2_roll,column1_roll+column2_roll));
    addAvailableCell(toCellId(row1_roll+extra_roll,column1_roll+column2_roll));
    addAvailableCell(toCellId(row1_roll+row2_roll,extra_roll+column2_roll));
    addAvailableCell(toCellId(row1_roll+row2_roll,column1_roll+extra_roll));
    addAvailableCell(toCellId(row1_roll+row2_roll,column1_roll+column2_roll));
}

void CellChooser::addAvailableCell (const CellId& cell_id){
    assert(cell_id.getRow()<7&&cell_id.getRow()>=0&&cell_id.getColumn()<7&&cell_id.getColumn()>=0);
    if(linearSearch(cell_id)==9999999){
        this->cellIds[this->count]=cell_id;
        this->count++;
    }
    selectionSort();
}
unsigned int CellChooser::linearSearch (const CellId& cell_id) const{
    for(int i=0;i<this->count;i++){
        if(this->cellIds[i]==cell_id)return i;
    }return 9999999;
}
unsigned int CellChooser::binarySearch (const CellId& cell_id) const{
    int l,r,mid;
    l=0,r=this->count-1;
    while(l<r){
        mid=(l+r)/2;
        if(cell_id<this->cellIds[mid])r=mid;
        else if(cell_id==this->cellIds[mid])return mid;
        else l=mid+1;
    }return l;
}
void CellChooser::selectionSort () {
    if (this->count == 0)return;
    int i, j;
    for (i = 0; i < this->count - 1; i++)
    {
        int k = i;
        for (j = i + 1; j < this->count; j++)
        {
            if (this->cellIds[j]<this->cellIds[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            CellId tmp = this->cellIds[i];
            this->cellIds[i] = this->cellIds[k];
            this->cellIds[k] = tmp;
        }
    }
}
void CellChooser::insertionSort (){
}
bool CellChooser::isInvariantTrue () const{
    bool flag= true;
    for(int i=0;i< this->count;i++){
        if(this->cellIds[i].getRow()>=7&&this->cellIds[i].getRow()<0&&this->cellIds[i].getColumn()>=7&&this->cellIds[i].getColumn()<0){
            flag= false;
            break;
        }
        if(i< this->count-1&&!(this->cellIds[i]<this->cellIds[i+1])){
            flag= false;
            break;
        }
    }
    if(this->count>=1&&this->count<=BOARD_CELL_COUNT&&flag)return true;
    return false;;
}
CellId CellChooser::getChosen () const{
    assert(isInvariantTrue ());
    assert(isChosen());
    return this->chosenCell;
}
void CellChooser::printAvailable () const{
    assert(isInvariantTrue ());
    cout<<"Available cells:";
    for(int i=0;i<this->count;i++){
        cout<<"  "<<this->cellIds[i];
    }cout<<endl;
}
bool CellChooser::isAvailable (const CellId& cell_id) const{
    assert(isInvariantTrue ());
    int index=binarySearch(cell_id);
    if(cell_id==this->cellIds[index])return true;
    return false;
}
void CellChooser::chooseAvailable (const CellId& cell_id){
    assert(isInvariantTrue ());
    assert(isAvailable(cell_id));
    this->chosenCell=cell_id;
}
void CellChooser::addCellIds (const CellId cells[],unsigned int cell_count){
    assert(isInvariantTrue ());
    for(int i=0;i<cell_count;i++){
        addAvailableCell(cells[i]);
    }
    selectionSort();
}
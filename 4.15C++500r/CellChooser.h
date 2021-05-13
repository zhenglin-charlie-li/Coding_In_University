
#ifndef HOMEWORK4_CELLCHOOSER_H
#define HOMEWORK4_CELLCHOOSER_H

#endif //HOMEWORK4_CELLCHOOSER_H
#include "CellId.h"
const CellId NOT_CHOSEN=CellId(100000,100000);
class CellChooser{
private:
    void calculateAllAvailable (int row1_roll,int row2_roll,int column1_roll,int column2_roll,int extra_roll,bool is_extra);
    void addAvailableCell (const CellId& cell_id);
    unsigned int linearSearch (const CellId& cell_id) const;
    unsigned int binarySearch (const CellId& cell_id) const;
    void selectionSort ();  //  CHOOSE THIS LINE OR NEXT LINE
    void insertionSort ();
    bool isInvariantTrue () const;

public:
    CellId cellIds[50];
    int count=0;
    CellId chosenCell;
    CellChooser (int row1_roll,int row2_roll,int column1_roll,int column2_roll,int extra_roll,bool is_extra);
    bool isChosen () const;
    CellId getChosen () const;
    void printAvailable () const;
    bool isAvailable (const CellId& cell_id) const;
    void chooseAvailable (const CellId& cell_id);
    void addCellIds (const CellId cells[],unsigned int cell_count);
};
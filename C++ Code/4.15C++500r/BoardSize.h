#pragma once



#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;


const int BOARD_SIZE = 7;
const int BOARD_CELL_COUNT = BOARD_SIZE * BOARD_SIZE;

char getRowName (int row);
char getColumnName (int column);

#endif
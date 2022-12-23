#include <iostream>
#include <cassert>
#include "BoardSize.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board_member[i][j] = Tile(GENUS_MONEY, 1);
        }
    }

    for (int i = 1; i < BOARD_SIZE - 1; i++) {
        for (int j = 1; j < BOARD_SIZE - 1; j++) {
            board_member[i][j] = Tile(GENUS_MONEY, 2);
        }
    }

    for (int i = 2; i < BOARD_SIZE - 2; i++) {
        for (int j = 2; j < BOARD_SIZE - 2; j++) {
            board_member[i][j] = Tile(GENUS_MONEY, 3);
        }
    }
    for (int i = 3; i < BOARD_SIZE - 3; i++) {
        for (int j = 3; j < BOARD_SIZE - 3; j++) {
            board_member[i][j] = Tile(GENUS_MONEY, 4);
        }
    }
}

bool Board::check_cell_on_board(const CellId &cell_id) {
    return cell_id.getColumn() <= BOARD_SIZE && cell_id.getRow() <= BOARD_SIZE;
}

const Tile &Board::getAt(const CellId &cell_id) const {
    assert(check_cell_on_board);
    return board_member[cell_id.getRow()][cell_id.getColumn()];
}

void Board::setAt(const CellId &cell_id, const Tile &value, unsigned int owner) {
    assert(check_cell_on_board);
    board_member[cell_id.getRow()][cell_id.getColumn()] = value;
    board_member[cell_id.getRow()][cell_id.getColumn()].setOwner(owner);
}

void Board::print() const {
    printColumnNameRow();
    printBorderRow();
    for (int i = 0; i < BOARD_SIZE; i++) {
        printEmptyRow();
        printDataRow(i);
        cout << endl;
    }
    printEmptyRow();
    printBorderRow();
    printColumnNameRow();
}

void Board::printColumnNameRow() {
    cout << "    0   1   2   3   4   5   6" << endl;
}

void Board::printBorderRow() {
    cout << "  +----------------------------+" << endl;
}

void Board::printEmptyRow() {
    cout << "  |                            |" << endl;
}

void Board::printDataRow(int row) const {
    switch (row){
        case 0:cout<<"A";break;
        case 1:cout<<"B";break;
        case 2:cout<<"C";break;
        case 3:cout<<"D";break;
        case 4:cout<<"E";break;
        case 5:cout<<"F";break;
        case 6:cout<<"G";break;
    }
    cout << " ";
    cout<<"|";
    for (int j = 0; j < BOARD_SIZE; j++) {
        board_member[row][j].print();
        cout << " ";
    }
    cout<<"|";
    switch (row){
        case 0:cout<<"A";break;
        case 1:cout<<"B";break;
        case 2:cout<<"C";break;
        case 3:cout<<"D";break;
        case 4:cout<<"E";break;
        case 5:cout<<"F";break;
        case 6:cout<<"G";break;
    }
}



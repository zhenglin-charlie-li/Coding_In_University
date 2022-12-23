//
//  TestBoard3.cpp
//
//  A test program for the Board module.  This is similar to
//    TestBoard2, except that:
//    -> The board array is now an encapsulated class
//    -> Cells are now specified as CellIds, not row/column pairs
//
//  This program is to be used with Assignment 3: Part B of
//    CS115, 202110.
//
//  Do not modify this file.
//

#include "Board.h"
#include "Board.h"  // repeated to test for #include errors

#include <cassert>
#include <string>
#include <iostream>

#include "TestHelper.h"
#include "BoardSize.h"
#include "Player.h"
#include "Tile.h"

using namespace std;

int main ();
double checkBoardAfterInit (const Board& board);
void checkTileAfterInit (const Tile& current,
                         const Tile& desired,
                         unsigned int& wrong_genus_count,
                         unsigned int& wrong_species_count,
                         unsigned int& wrong_owner_count);
bool checkTile (const Tile& current, const Tile& desired);

const int COMPILE_AND_START_MARKS     = 3;
const int DID_NOT_CRASH_RUNNING_MARKS = 2;
const int COMPILE_AND_NOT_CRASH_MARKS = COMPILE_AND_START_MARKS + DID_NOT_CRASH_RUNNING_MARKS;
const int COMBINED_TEST_MARKS         = 10;
const int TOTAL_MARKS                 = COMPILE_AND_NOT_CRASH_MARKS + COMBINED_TEST_MARKS;

const int BOARD_SIZE_CORRECT       = 7;
const int BOARD_CELL_COUNT_CORRECT = BOARD_SIZE_CORRECT * BOARD_SIZE_CORRECT;
const int BOARD_BYTES_CORRECT      = sizeof(Tile) * BOARD_CELL_COUNT_CORRECT;

const int BOARD_CENTER = BOARD_SIZE_CORRECT / 2;  // integer division
const int MONEY_CENTER = 4;

const unsigned int ROLL_PLAYER_COUNT = 5;

const int  SET_1_ROW    = 0;
const int  SET_1_COLUMN = 1;
const Tile SET_1_VALUE(GENUS_MONEY, 5);
const int  SET_1_OWNER  = 1;

const int  SET_2_ROW    = 3;
const int  SET_2_COLUMN = 6;
const Tile SET_2_VALUE(GENUS_POINTS, 8);
const int  SET_2_OWNER  = 0;



int main ()
{
    testHelperStartup("TestBoard3", COMPILE_AND_START_MARKS, TOTAL_MARKS);

    string player_names[2] = { "Mary", "John" };
    playerInit(2, player_names);

    //
    //  Test board cells
    //

    cout << "Checking board size in bytes" << endl;
    unsigned int board_bytes = sizeof(Board);
    bool correct_board_bytes = board_bytes == BOARD_BYTES_CORRECT;
    if(!correct_board_bytes)
    {
        assert(board_bytes != BOARD_BYTES_CORRECT);
        if(board_bytes < BOARD_BYTES_CORRECT)
            cout << "* Incorrect: Board should contain a 2D array of Tiles" << endl;
        else
            cout << "* Incorrect: Board should contain only a 2D array of Tiles" << endl;
    }
    else
        cout << "* Correct" << endl;
    cout << endl;

    cout << "Initializing board" << endl;
    Board board;  // invokes default constructor
    cout << "Completed without crashing" << endl;
    double correct_init_fraction = checkBoardAfterInit(board);
    cout << endl;

    cout << "Checking setAt (1)" << endl;
    CellId cell_id1 = toCellId(SET_1_ROW, SET_1_COLUMN);
    board.setAt(cell_id1, SET_1_VALUE, SET_1_OWNER);
    const Tile& get_after_set1 = board.getAt(cell_id1);
    Tile value1_with_owner = SET_1_VALUE;
    value1_with_owner.setOwner(SET_1_OWNER);
    bool correct_set1 = checkTile(get_after_set1, value1_with_owner);
    cout << endl;

    cout << "Checking setAt (2)" << endl;
    CellId cell_id2 = toCellId(SET_2_ROW, SET_2_COLUMN);
    board.setAt(cell_id2, SET_2_VALUE, SET_2_OWNER);
    const Tile& get_after_set2 = board.getAt(cell_id2);
    Tile value2_with_owner = SET_2_VALUE;
    value2_with_owner.setOwner(SET_2_OWNER);
    bool correct_set2 = checkTile(get_after_set2, value2_with_owner);
    cout << endl;



    //
    //  Test display
    //

    cout << "Printing board" << endl;
    board.print();
    cout << endl;



    //
    //  Print results
    //

    testHelperPrintSummaryHeader(16, 1, DID_NOT_CRASH_RUNNING_MARKS);
    testHelperPrintSummaryLine("Representation", correct_board_bytes);
    testHelperPrintSummaryLine("boardInit",      correct_init_fraction);
    testHelperPrintSummaryLine("boardSetAt (1)", correct_set1);
    testHelperPrintSummaryLine("boardSetAt (2)", correct_set2);

    unsigned int mark = COMPILE_AND_NOT_CRASH_MARKS;

    if(correct_board_bytes)
        mark += 2;
    mark += (int)(correct_init_fraction * 4);
    if(correct_set1)
        mark += 2;
    if(correct_set2)
        mark += 2;

    assert(mark <= TOTAL_MARKS);
    testHelperPrintMark(mark, TOTAL_MARKS);

    testHelperWaitForEnter();
    return 0;
}



double checkBoardAfterInit (const Board& board)
{
    unsigned int wrong_genus_count   = 0;
    unsigned int wrong_species_count = 0;
    unsigned int wrong_owner_count   = 0;
    unsigned int total_count = (BOARD_CENTER * 2 + 1) * (BOARD_CENTER * 2 + 1);

    for(int ring = 0; ring <= BOARD_CENTER; ring++)
    {
        Tile correct(GENUS_MONEY, MONEY_CENTER - ring);

        for(int row = BOARD_CENTER - ring; row <= BOARD_CENTER + ring; row++)
        {
            const Tile& current1 = board.getAt(toCellId(row, BOARD_CENTER - ring));
            checkTileAfterInit(current1, correct, wrong_genus_count, wrong_species_count, wrong_owner_count);

            if(ring != 0)
            {
                const Tile& current2 = board.getAt(toCellId(row, BOARD_CENTER + ring));
                checkTileAfterInit(current2, correct, wrong_genus_count, wrong_species_count, wrong_owner_count);
            }
        }

        for(int column = BOARD_CENTER - ring + 1; column < BOARD_CENTER + ring; column++)
        {
            const Tile& current1 = board.getAt(toCellId(BOARD_CENTER - ring, column));
            checkTileAfterInit(current1, correct, wrong_genus_count, wrong_species_count, wrong_owner_count);

            const Tile& current2 = board.getAt(toCellId(BOARD_CENTER + ring, column));
            checkTileAfterInit(current2, correct, wrong_genus_count, wrong_species_count, wrong_owner_count);
        }
    }

    if(wrong_genus_count > 0)
        cout << "* Incorrect: " << wrong_genus_count   << " / " << total_count << " tile genuses are wrong" << endl;
    if(wrong_species_count > 0)
        cout << "* Incorrect: " << wrong_species_count << " / " << total_count << " tile species (money values) are wrong" << endl;
    if(wrong_owner_count > 0)
        cout << "* Incorrect: " << wrong_owner_count   << " / " << total_count << " tile owners are wrong" << endl;
    if(wrong_genus_count   == 0 &&
       wrong_species_count == 0 &&
       wrong_owner_count   == 0)
    {
        cout << "* Correct" << endl;
    }

    double fraction_genus   = (double)(wrong_genus_count  ) / (double)(total_count);
    double fraction_species = (double)(wrong_species_count) / (double)(total_count);
    double fraction_owner   = (double)(wrong_owner_count  ) / (double)(total_count);

    double largest_fraction = fraction_genus;
    if(largest_fraction < fraction_species)
        largest_fraction = fraction_species;
    if(largest_fraction < fraction_owner)
        largest_fraction = fraction_owner;

    assert(largest_fraction >= 0.0);
    assert(largest_fraction <= 1.0);
    return 1.0 - largest_fraction;
}

void checkTileAfterInit (const Tile& current,
                         const Tile& desired,
                         unsigned int& wrong_genus_count,
                         unsigned int& wrong_species_count,
                         unsigned int& wrong_owner_count)
{
    if(current.getGenus() != desired.getGenus())
        wrong_genus_count++;
    if(current.getSpecies() != desired.getSpecies())
        wrong_species_count++;
    if(current.isOwner() != desired.isOwner())
        wrong_owner_count++;
}



bool checkTile (const Tile& current, const Tile& desired)
{
    if(current.getGenus() != desired.getGenus())
    {
        cout << "* Incorrect: Genus was " << current.getGenus() << ", should be " << desired.getGenus() << endl;
        return false;
    }
    if(current.getSpecies() != desired.getSpecies())
    {
        cout << "* Incorrect: Species was " << current.getSpecies() << ", should be " << desired.getSpecies() << endl;
        return false;
    }
    if(current.isOwner() != desired.isOwner())
    {
        if(current.isOwner())
            cout << "* Incorrect: Tile has owner but shouldn't" << endl;
        else
            cout << "* Incorrect: Tile should have owner but doesn't" << endl;
        return false;
    }
    if(current.isOwner())
    {
        for(unsigned int i = 0; i < ROLL_PLAYER_COUNT; i++)
        {
            unsigned int current_affected = current.getAffectedPlayer(i);
            unsigned int desired_affected = desired.getAffectedPlayer(i);
            if(current_affected != desired_affected)
            {
                cout << "* Incorrect: Tile should affects player " << current_affected
                     << " (" << i << " rolled), should be " << desired_affected << endl;
                return false;
            }
        }
    }

    cout << "* Correct" << endl;
    return true;
}



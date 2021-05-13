//
//  TestTilePoints6.cpp
//
//  A test program for the TilePoints tiles.
//
//  This program is to be used with Assignment 6: Part D of
//    CS115, 202110.
//
//  Do not modify this file.
//

#include "TilePoints.h"
#include "TilePoints.h"  // repeated to test for #include errors

#include <cassert>
#include <string>
#include <iostream>
#include <sstream>

#include "TestHelper.h"
#include "BoardSize.h"
#include "Player.h"
#include "CellId.h"
#include "Tile.h"

using namespace std;

int main ();

bool testGetClone (const Tile* ptr_tile);
unsigned int checkPrintTile (const TilePoints& tile_unowned,
                             const Tile&      tile_owned);

const int COMPILE_AND_START_MARKS     = 2;
const int DID_NOT_CRASH_RUNNING_MARKS = 1;
const int COMPILE_AND_NOT_CRASH_MARKS = COMPILE_AND_START_MARKS + DID_NOT_CRASH_RUNNING_MARKS;
const int COMBINED_TEST_MARKS         = 7;
const int TOTAL_MARKS                 = COMPILE_AND_NOT_CRASH_MARKS + COMBINED_TEST_MARKS;

const int POINTS_VALUE = 5;

const unsigned int PLAYER_OWNER  = 0;
const unsigned int PLAYER_ROLLER = 1;
const unsigned int ROLL_PLAYER_COUNT = 5;
const CellId ROLLED_CELL = toCellId(0, 0);

const unsigned int PRINT_COUNT = 2;



//
//  Dummy Board class, for testing.  It does nothing.
//
class Board
{
public:
	void print () const;

	const Tile& getAt (const CellId& cell_id) const;
	void setAt (const CellId& cell_id,
	            const Tile& value,
	            unsigned int owner);
private:
	int var;
};

void Board :: print () const
{ }

const Tile& Board :: getAt (const CellId& cell_id) const
{
	static const TilePoints TILE_POINTS(1);  // not a local variable

	return TILE_POINTS;
}

void Board :: setAt (const CellId& cell_id,
                     const Tile& value,
                     unsigned int owner)
{ }



int main ()
{
	testHelperStartup("TestTilePoints6", COMPILE_AND_START_MARKS, TOTAL_MARKS);

	string player_names[2] = { "Mary", "John" };
	playerInit(2, player_names);

	Board board;

	//
	//  Testing TilePoints
	//

	bool correct_inheritance = false;
	bool correct_get_clone   = false;
	bool correct_is_owner1   = false;
	bool correct_affected1   = false;
	bool correct_is_owner2   = false;
	bool correct_affected2   = false;
	bool correct_activate1   = false;
	bool correct_activate2   = false;
	unsigned int correct_print = 0;

	TilePoints* ptr_tile2 = NULL;

	// tile1 will go out of scope when this closes
	{
		cout << "Creating TilePoints with species constructor" << endl;
		TilePoints tile1(POINTS_VALUE);
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Creating TilePoints with copy constructor" << endl;
		assert(ptr_tile2 == NULL);
		ptr_tile2 = new TilePoints(tile1);
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Replacing TilePoints using assignment operator" << endl;
		tile1 = *ptr_tile2;
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Testing self-assignment" << endl;
		tile1 = tile1;
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Testing chained assignment" << endl;
		*ptr_tile2 = tile1 = *ptr_tile2;
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Testing inheritance" << endl;
		TilePoints* ptr_tile1       = &tile1;
		Tile*      ptr_tile_super1 = dynamic_cast<Tile*>(ptr_tile1);
		correct_inheritance = ptr_tile_super1 != NULL;
		if(!correct_inheritance)
			cout << "* Incorrect: TilePoints should inherit from Tile" << endl;
		else
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing getClone" << endl;
		correct_get_clone = testGetClone(ptr_tile_super1);
		cout << endl;

		cout << "Testing ownership (unowned)" << endl;
		correct_is_owner1 = tile1.isOwner() == false;
		if(!correct_is_owner1)
			cout << "* Incorrect: Tile should not have an owner, but isOwner returns true" << endl;
		else
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing affected player (unowned)" << endl;
		correct_affected1 = true;
		for(unsigned int i = 0; i < ROLL_PLAYER_COUNT; i++)
		{
			unsigned int affected = tile1.getAffectedPlayer(i);
			if(correct_affected1 == true && affected != i)
			{
				correct_affected1 = false;
				cout << "* Incorrect: Tile should affects player " << affected
					 << " (" << i << " rolled), should be " << i << endl;
			}
		}
		if(correct_affected1)
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing setOwner (set to " << PLAYER_OWNER << ": \"" << playerGetName(PLAYER_OWNER) << "\")" << endl;
		tile1.setOwner(PLAYER_OWNER);
		cout << "Completed without crashing" << endl;
		cout << endl;

		cout << "Testing ownership (owned)" << endl;
		correct_is_owner2  = tile1.isOwner() == true;
		if(!correct_is_owner2)
			cout << "* Incorrect: Tile should not have an owner, but isOwner returns true" << endl;
		else
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing affected player (owned)" << endl;
		correct_affected2 = true;
		for(unsigned int i = 0; i < ROLL_PLAYER_COUNT; i++)
		{
			unsigned int affected = tile1.getAffectedPlayer(i);
			if(correct_affected2 == true && affected != PLAYER_OWNER)
			{
				correct_affected2 = false;
				cout << "* Incorrect: Tile should affects player " << affected
					 << " (" << i << " rolled), should be " << PLAYER_OWNER << endl;
			}
		}
		if(correct_affected2)
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing activate" << endl;
		cout << " (rolled by player " << PLAYER_ROLLER << ": \"" << playerGetName(PLAYER_ROLLER) << "\", unowned)" << endl;
		stringstream ss1;
		ss1 << playerGetName(PLAYER_ROLLER) << "'s points: *0 + *" << POINTS_VALUE << " = *" << POINTS_VALUE << endl;
		cout << ss1.str();
		testHelperStartCapture();
		ptr_tile2->activate(PLAYER_ROLLER, ROLLED_CELL, board);
		string activate_text1 = testHelperEndCapture();
		correct_activate1 = activate_text1 == ss1.str();
		if(!correct_activate1)
			cout << "* Incorrect: Wrong message printed when tile activated" << endl;
		else
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing activate" << endl;
		cout << " (rolled by player " << PLAYER_ROLLER << ": \"" << playerGetName(PLAYER_ROLLER) << "\","
		     <<   " owned by player " << PLAYER_OWNER  << ": \"" << playerGetName(PLAYER_OWNER)  << "\")" << endl;
		stringstream ss2;
		ss2 << playerGetName(PLAYER_OWNER) << "'s points: *0 + *" << POINTS_VALUE << " = *" << POINTS_VALUE << endl;
		cout << ss2.str();
		testHelperStartCapture();
		tile1.activate(PLAYER_ROLLER, ROLLED_CELL, board);
		string activate_text2 = testHelperEndCapture();
		correct_activate2 = activate_text2 == ss2.str();
		if(!correct_activate2)
			cout << "* Incorrect: Wrong message printed when tile activated" << endl;
		else
			cout << "* Correct" << endl;
		cout << endl;

		cout << "Testing print" << endl;
		correct_print = checkPrintTile(*ptr_tile2, tile1);
		cout << endl;

		cout << "Destroying TilePoints #1" << endl;
	}  // tile1 goes out of scope here (destructor invoked)
	cout << "Completed without crashing" << endl;
	cout << endl;

	cout << "Destroying TilePoints #2" << endl;
	delete ptr_tile2;
	cout << "Completed without crashing" << endl;
	cout << endl;



	//
	//  Print results
	//

	testHelperPrintSummaryHeader(20, 1, DID_NOT_CRASH_RUNNING_MARKS);
	testHelperPrintSummaryLine("Inheritance",        correct_inheritance);
	testHelperPrintSummaryLine("getClone",           correct_get_clone);
	testHelperPrintSummaryLine("isOwner (no)",       correct_is_owner1);
	testHelperPrintSummaryLine("getAffectedPlayer",  correct_affected1);
	testHelperPrintSummaryLine("isOwner (yes)",      correct_is_owner2);
	testHelperPrintSummaryLine("getAffectedPlayer",  correct_affected2);
	testHelperPrintSummaryLine("activate (unowned)", correct_activate1);
	testHelperPrintSummaryLine("activate (owned)",   correct_activate2);
	testHelperPrintSummaryLine("print",              correct_print, PRINT_COUNT);

	unsigned int mark = COMPILE_AND_NOT_CRASH_MARKS;

	if(correct_inheritance)
		mark += 1;
	if(correct_get_clone)
		mark += 2;
	if(correct_is_owner1 &&
	   correct_is_owner2 &&
	   correct_affected1 &&
	   correct_affected2)
	{
		mark += 1;
	}
	if(correct_activate1)
		mark += 1;
	if(correct_activate2)
		mark += 1;
	if(correct_print == PRINT_COUNT)
		mark += 1;

	assert(mark <= TOTAL_MARKS);
	testHelperPrintMark(mark, TOTAL_MARKS);

	testHelperWaitForEnter();
	return 0;
}



bool testGetClone (const Tile* ptr_tile)
{
	if(ptr_tile == NULL)
	{
		cout << "* Skipped: getClone depends on inheritance" << endl;
		return false;
	}

	Tile* ptr_tile_as_base = ptr_tile->getClone();
	if(ptr_tile_as_base == NULL)
	{
		cout << "* Incorrect: getClone should return a copy, not NULL" << endl;
		delete ptr_tile_as_base;
		return false;
	}
	
	if(ptr_tile_as_base == ptr_tile)
	{
		cout << "* Incorrect: getClone should return a copy, not itself" << endl;
		delete ptr_tile_as_base;
		return false;
	}
	
	TilePoints* ptr_tile_as_derived = dynamic_cast<TilePoints*>(ptr_tile_as_base);
	if(ptr_tile_as_derived == NULL)
	{
		cout << "* Incorrect: getClone should return a TilePoints" << endl;
		delete ptr_tile_as_base;
		return false;
	}

	cout << "* Correct" << endl;
	delete ptr_tile_as_base;
	return true;
}

unsigned int checkPrintTile (const TilePoints& tile_unowned,
                             const Tile&      tile_owned)
{
	assert(PRINT_COUNT == 2);
	static const string PRINTED_CORRECT[PRINT_COUNT] =
	{	" *5",	"M*5",	};

	// print "overlines" for tile output
	cout << "         ";
	for(unsigned int i = 0; i < PRINT_COUNT; i++)
	{
		cout << "  ___";
	}
	cout << endl;

	// print correct tile output
	cout << "Correct: ";
	for(unsigned int i = 0; i < PRINT_COUNT; i++)
	{
		cout << "  " << PRINTED_CORRECT[i];
	}
	cout << endl;

	// print tile output from program
	cout << "Results:   ";
	testHelperStartCapture();
	tile_unowned.print();
	string printed_unowned = testHelperEndCapture();
	cout << "  ";
	testHelperStartCapture();
	tile_owned.print();
	string printed_owned = testHelperEndCapture();
	cout << endl;

	// check tile output
	unsigned int correct_count = PRINT_COUNT;
	if(printed_unowned != PRINTED_CORRECT[0])
	{
		cout << "* Incorrect: Unowned tile printed incorrectly" << endl;
		assert(correct_count >= 1);
		correct_count--;
	}
	if(printed_owned != PRINTED_CORRECT[1])
	{
		cout << "* Incorrect: Owned tile printed incorrectly" << endl;
		assert(correct_count >= 1);
		correct_count--;
	}
	if(correct_count == 2)
		cout << "* Correct" << endl;
	return correct_count;
}



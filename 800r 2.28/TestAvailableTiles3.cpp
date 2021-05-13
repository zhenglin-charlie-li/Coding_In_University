//
//  TestAvailableTiles3.cpp
//
//  A test program for the AvailableTiles module.
//
//  This program is to be used with Assignment 3: Part C of
//    CS115, 202110.
//
//  Do not modify this file.
//

#include "AvailableTiles.h"
#include "AvailableTiles.h"  // repeated to test for #include errors

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>

#include "TestHelper.h"
#include "Player.h"
#include "Dice.h"
#include "Tile.h"

using namespace std;

int main ();
unsigned int checkCosts ();
void checkDistribution (bool& is_genus_always_valid,
                        bool& is_species_points_always_valid,
                        bool& no_points_species_too_rare,
                        bool& no_points_species_too_common);

const int COMPILE_AND_START_MARKS     = 5;
const int DID_NOT_CRASH_RUNNING_MARKS = 5;
const int COMPILE_AND_NOT_CRASH_MARKS = COMPILE_AND_START_MARKS + DID_NOT_CRASH_RUNNING_MARKS;
const int COMBINED_TEST_MARKS         = 16;
const int TOTAL_MARKS                 = COMPILE_AND_NOT_CRASH_MARKS + COMBINED_TEST_MARKS;

const unsigned int AVAILABLE_TILE_COUNT_CORRECT = 5;
const unsigned int AVAILABLE_TILE_LAST          = AVAILABLE_TILE_COUNT_CORRECT - 1;

const unsigned int SPECIES_POINTS_MIN = 1;
const unsigned int SPECIES_POINTS_MAX = 3;
const unsigned int SPECIES_POINTS_COUNT = SPECIES_POINTS_MAX - SPECIES_POINTS_MIN + 1;

const unsigned int SPECIES_TOTAL_COUNT = SPECIES_POINTS_COUNT;

const int COST_MIN = 1;
const int COST_MAX = 9;

const unsigned int RANDOM_COUNT = 100000;

const unsigned int SPECIES_POINTS_COUNT_GOOD = RANDOM_COUNT / SPECIES_POINTS_COUNT;
const unsigned int SPECIES_POINTS_COUNT_MIN  = SPECIES_POINTS_COUNT_GOOD * 2/3;
const unsigned int SPECIES_POINTS_COUNT_MAX  = SPECIES_POINTS_COUNT_GOOD * 3/2;




int main789 ()
{
    testHelperStartup("TestAvailableTiles3", COMPILE_AND_START_MARKS, TOTAL_MARKS);

    string player_names[3] = { "1st", "2nd", "3rd" };
    playerInit(3, player_names);

    diceInit();

    //
    //  Run basic tests
    //

    cout << "Checking AVAILABLE_TILE_COUNT" << endl;
    bool correct_count = testHelperConstant(AVAILABLE_TILE_COUNT, AVAILABLE_TILE_COUNT_CORRECT, "AVAILABLE_TILE_COUNT");
    cout << endl;

    cout << "Creating AvailableTiles" << endl;
    AvailableTiles available;
    cout << "Completed without crashing" << endl;
    cout << endl;

    cout << "Checking genus and species for all tiles" << endl;
    Tile stored_tiles[AVAILABLE_TILE_COUNT_CORRECT];
    bool correct_genus   = true;
    bool correct_species = true;
    for(unsigned int i = 0; i < AVAILABLE_TILE_COUNT_CORRECT; i++)
    {
        stored_tiles[i] = available.getTile(i);
        unsigned int genus   = stored_tiles[i].getGenus();
        unsigned int species = stored_tiles[i].getSpecies();

        switch(genus)
        {
            case GENUS_POINTS:
                if(correct_species)
                    if(species < SPECIES_POINTS_MIN || species > SPECIES_POINTS_MAX)
                    {
                        cout << "* Incorrect: Points tile " << i << " has invalid species *" << species << endl;
                        correct_species = false;
                    }
                break;
            default:
                if(correct_genus)
                {
                    cout << "* Incorrect: Tile " << i << " has invalid genus " << genus << endl;
                    correct_genus = false;
                }
                break;
        }
    }
    if(correct_genus && correct_species)
        cout << "* Correct" << endl;
    cout << endl;

    cout << "Checking tile cost for all tiles" << endl;
    int  stored_costs[AVAILABLE_TILE_COUNT_CORRECT];
    bool correct_cost_min = true;
    bool correct_cost_max = true;
    for(unsigned int i = 0; i < AVAILABLE_TILE_COUNT_CORRECT; i++)
    {
        stored_costs[i] = available.getCost(i);
        if(stored_costs[i] < COST_MIN && correct_cost_min)
        {
            cout << "* Incorrect: Tile " << i << " (";
            stored_tiles[i].print();
            cout << ") has invalid cost " << stored_costs[i] << " (too low)" << endl;
            correct_cost_min = false;
        }
        else if(stored_costs[i] > COST_MAX && correct_cost_max)
        {
            cout << "* Incorrect: Tile " << i << " (";
            stored_tiles[i].print();
            cout << ") has invalid cost " << stored_costs[i] << " (too low)" << endl;
            correct_cost_max = false;
        }
    }
    if(correct_cost_min && correct_cost_max)
        cout << "* Correct" << endl;
    cout << endl;

    cout << "Checking replaceAt on last tile (other tiles should be unchanged)" << endl;
    available.replaceAt(AVAILABLE_TILE_LAST);
    cout << "Completed without crashing" << endl;
    bool correct_tile_steady = true;
    bool correct_cost_steady = true;
    for(unsigned int i = 0; i < AVAILABLE_TILE_LAST; i++)
    {
        Tile new_tile = available.getTile(i);
        int  new_cost = available.getCost(i);
        if(correct_tile_steady)
        {
            if(new_tile.getGenus() != stored_tiles[i].getGenus())
            {
                cout << "* Incorrect: Tile " << i << " genus changed from " << stored_tiles[i].getGenus() << " to " << new_tile.getGenus() << endl;
                correct_tile_steady = false;
            }
            else if(new_tile.getSpecies() != stored_tiles[i].getSpecies())
            {
                cout << "* Incorrect: Tile " << i << " species changed from " << stored_tiles[i].getSpecies() << " to " << new_tile.getSpecies() << endl;
                correct_tile_steady = false;
            }
        }
        if(new_cost != stored_costs[i] && correct_cost_steady)
        {
            cout << "* Incorrect: Tile " << i << " cost changed from " << stored_costs[i] << " to " << new_cost << endl;
            correct_cost_steady = false;
        }
    }
    if(correct_tile_steady && correct_cost_steady)
        cout << "* Correct" << endl;
    cout << endl;

    // update stored info for new tile
    stored_tiles[AVAILABLE_TILE_LAST] = available.getTile(AVAILABLE_TILE_LAST);
    stored_costs[AVAILABLE_TILE_LAST] = available.getCost(AVAILABLE_TILE_LAST);

    cout << "Checking replaceAt on first tile (other tiles should shift down array)" << endl;
    available.replaceAt(0);
    cout << "Completed without crashing" << endl;
    bool correct_tile_shift = true;
    bool correct_cost_shift = true;
    for(unsigned int i = 0; i < AVAILABLE_TILE_LAST; i++)
    {
        Tile new_tile = available.getTile(i);
        int  new_cost = available.getCost(i);
        if(correct_tile_shift)
        {
            if(new_tile.getGenus() != stored_tiles[i + 1].getGenus())
            {
                cout << "* Incorrect: Tile " << i << " genus changed from " << stored_tiles[i + 1].getGenus() << " to " << new_tile.getGenus() << endl;
                correct_tile_shift = false;
            }
            else if(new_tile.getSpecies() != stored_tiles[i + 1].getSpecies())
            {
                cout << "* Incorrect: Tile " << i << " species changed from " << stored_tiles[i + 1].getSpecies() << " to " << new_tile.getSpecies() << endl;
                correct_tile_shift = false;
            }
        }
        if(new_cost != stored_costs[i + 1] && correct_cost_shift)
        {
            cout << "* Incorrect: Tile " << i << " cost changed from " << stored_costs[i + 1] << " to " << new_cost << endl;
            correct_cost_shift = false;
        }
    }
    if(correct_tile_shift && correct_cost_shift)
        cout << "* Correct" << endl;
    cout << endl;

    cout << "Checking tile costs" << endl;
    unsigned int correct_costs = checkCosts();
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Checking tile distribution" << endl;
    bool distribution_genus_valid;
    bool distribution_points_species_valid;
    bool distribution_no_points_species_too_rare;
    bool distribution_no_points_species_too_common;
    checkDistribution (distribution_genus_valid,
                       distribution_points_species_valid,
                       distribution_no_points_species_too_rare,
                       distribution_no_points_species_too_common);
    cout << endl;



    //
    //  Print results
    //

    testHelperPrintSummaryHeader(30, 1, DID_NOT_CRASH_RUNNING_MARKS);
    testHelperPrintSummaryLine("AVAILABLE_TILE_COUNT",       correct_count);
    testHelperPrintSummaryLine("Tile genuses good",          correct_genus);
    testHelperPrintSummaryLine("Tile species good",          correct_species);
    testHelperPrintSummaryLine("Tile costs >= min",          correct_cost_min);
    testHelperPrintSummaryLine("Tile costs <= max",          correct_cost_max);
    testHelperPrintSummaryLine("Tiles after replaceAt(end)", correct_tile_steady);
    testHelperPrintSummaryLine("Costs after replaceAt(end)", correct_cost_steady);
    testHelperPrintSummaryLine("Tiles after replaceAt(0)",   correct_tile_shift);
    testHelperPrintSummaryLine("Costs after replaceAt(0)",   correct_cost_shift);
    testHelperPrintSummaryLine("Tile costs",                 correct_costs, SPECIES_TOTAL_COUNT);
    cout << endl;
    cout << "Distribution" << endl;
    testHelperPrintSummaryLine("Only valid genuses",            distribution_genus_valid);
    testHelperPrintSummaryLine("Only valid points species",     distribution_points_species_valid);
    testHelperPrintSummaryLine("No points species too rare",    distribution_no_points_species_too_rare);
    testHelperPrintSummaryLine("No points species too common",  distribution_no_points_species_too_common);

    unsigned int mark = COMPILE_AND_NOT_CRASH_MARKS;

    if(correct_count)
        mark += 1;
    if(correct_genus)
        mark += 1;
    if(correct_species)
        mark += 1;
    if(correct_cost_min)
        mark += 1;
    if(correct_cost_max)
        mark += 1;
    if(correct_tile_steady)
        mark += 1;
    if(correct_cost_steady)
        mark += 1;
    if(correct_tile_shift)
        mark += 2;
    if(correct_cost_shift)
        mark += 2;
    mark += correct_costs;
    if(distribution_genus_valid && distribution_points_species_valid)
        mark += 1;
    if(distribution_no_points_species_too_rare && distribution_no_points_species_too_common)
        mark += 1;

    assert(mark <= TOTAL_MARKS);
    testHelperPrintMark(mark, TOTAL_MARKS);

    testHelperWaitForEnter();
    return 0;
}



unsigned int checkCosts ()
{
    AvailableTiles available;

    bool good_cost_points[SPECIES_POINTS_MAX + 1];
    bool bad_cost_points [SPECIES_POINTS_MAX + 1];
    for(unsigned int s = SPECIES_POINTS_MIN; s <= SPECIES_POINTS_MAX; s++)
    {
        good_cost_points[s] = false;
        bad_cost_points [s] = false;
    }

    for(unsigned int i = 0; i < RANDOM_COUNT; i++)
    {
        available.replaceAt(AVAILABLE_TILE_LAST);
        Tile tile = available.getTile(AVAILABLE_TILE_LAST);
        int  cost = available.getCost(AVAILABLE_TILE_LAST);

        unsigned int species = tile.getSpecies();

        switch(tile.getGenus())
        {
            case GENUS_POINTS:
                if(species >= SPECIES_POINTS_MIN && species <= SPECIES_POINTS_MAX)
                {
                    if(cost != species * species)
                        bad_cost_points[species] = true;
                    else
                        good_cost_points[species] = true;
                }
                break;
        }
    }

    unsigned int good_species_count = 0;
    for(unsigned int s = SPECIES_POINTS_MIN; s <= SPECIES_POINTS_MAX; s++)
    {
        if(bad_cost_points[s])
        {
            if(good_cost_points[s])
                cout << "* Incorrect: *" << s << " points tile sometimes has incorrect cost" << endl;
            else
                cout << "* Incorrect: *" << s << " points tile always has incorrect cost" << endl;
        }
        else if(!good_cost_points[s])
            cout << "* Incorrect: No *" << s << " points tiles to check cost for" << endl;
        else
            good_species_count++;
    }
    if(good_species_count == SPECIES_TOTAL_COUNT)
        cout << "* Correct" << endl;

    return good_species_count;
}

void checkDistribution (bool& is_genus_always_valid,
                        bool& is_species_points_always_valid,
                        bool& no_points_species_too_rare,
                        bool& no_points_species_too_common)
{
    AvailableTiles available;

    unsigned int genus_points_count = 0;
    is_genus_always_valid = true;

    unsigned int species_points_count[SPECIES_POINTS_MAX + 1];
    for(unsigned int s = SPECIES_POINTS_MIN; s <= SPECIES_POINTS_MAX; s++)
        species_points_count[s] = 0;
    is_species_points_always_valid = true;

    for(unsigned int i = 0; i < RANDOM_COUNT; i++)
    {
        available.replaceAt(AVAILABLE_TILE_LAST);
        Tile tile = available.getTile(AVAILABLE_TILE_LAST);
        int  cost = available.getCost(AVAILABLE_TILE_LAST);

        unsigned int species = tile.getSpecies();

        switch(tile.getGenus())
        {
            case GENUS_POINTS:
                genus_points_count++;
                if(species >= SPECIES_POINTS_MIN && species <= SPECIES_POINTS_MAX)
                    species_points_count[species]++;
                else
                    is_species_points_always_valid = false;
                break;
            default:
                is_genus_always_valid = false;
                break;
        }
    }

    // check distributions
    no_points_species_too_rare   = true;
    no_points_species_too_common = true;
    for(unsigned int s = SPECIES_POINTS_MIN; s <= SPECIES_POINTS_MAX; s++)
    {
        if(species_points_count[s] < SPECIES_POINTS_COUNT_MIN)
            no_points_species_too_rare = false;
        if(species_points_count[s] > SPECIES_POINTS_COUNT_MAX)
            no_points_species_too_common = false;
    }

    // print frequencies
    cout << endl;
    cout << " Tile Type  Total     By species..............." << endl;
    cout << "+---------+-------+-------+-------+-------+-------+" << endl;
    cout << "| Points  |"  << setw(6) << right << genus_points_count << " |       |";
    for(unsigned int s = SPECIES_POINTS_MIN; s <= SPECIES_POINTS_MAX; s++)
        cout << setw(6) << right << species_points_count[s] << " |";
    cout << endl;
    cout << "+---------+-------+-------+-------+-------+-------+" << endl;

    // print conclusion
    if(!is_genus_always_valid)
        cout << "* Incorrect: Some tiles have invalid genus" << endl;
    if(!is_species_points_always_valid)
        cout << "* Incorrect: Some points tiles have invalid species" << endl;

    if(!no_points_species_too_rare)
        cout << "* Incorrect: Some species of points tiles are too rare" << endl;
    if(!no_points_species_too_common)
        cout << "* Incorrect: Some species of points tiles are too common" << endl;

    if(is_genus_always_valid &&
       is_species_points_always_valid &&
       no_points_species_too_rare &&
       no_points_species_too_common)
    {
        cout << "* Correct" << endl;
    }
}


//
//  Player.cpp
//

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>

#include "Player.h"

using namespace std;

const unsigned int START_MONEY  = 0;
const unsigned int START_DICE   = 1;
const unsigned int START_POINTS = 0;

struct Player
{
	string name;
	int money;
	int dice;
	int points;
};

static Player players[PLAYER_COUNT_MAX];
static unsigned int player_count = 0;

static bool isInvariantTrue ()
{
	if(player_count > PLAYER_COUNT_MAX)
		return false;
	for(unsigned int i = 0; i < player_count; i++)
		if(players[i].name == "")
			return false;
	return true;
}



void playerInit (unsigned int player_count1,
                 const string names[])
{
	assert(isInvariantTrue());
	assert(player_count1 >= PLAYER_COUNT_MIN);
	assert(player_count1 <= PLAYER_COUNT_MAX);
	for(unsigned int i = 0; i < player_count1; i++)
		assert(names[i] != "");

	player_count = player_count1;
	for(unsigned int i = 0; i < player_count; i++)
	{
		players[i].name = names[i];
		players[i].money  = START_MONEY;
		players[i].dice   = START_DICE;
		players[i].points = START_POINTS;
	}

	assert(isInvariantTrue());
}



unsigned int isInitialized ()
{
	assert(isInvariantTrue());

	if(player_count >= PLAYER_COUNT_MIN &&
	   player_count <= PLAYER_COUNT_MAX)
	{
		return true;
	}
	else
		return false;
}

unsigned int playerGetCount ()
{
	assert(isInvariantTrue());
	assert(isInitialized());

	return player_count;
}

unsigned int playerGetIndex (const string& name)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(name != "");

	for(unsigned int i = 0; i < player_count; i++)
	{
		if(players[i].name == name)
			return i;
	}

	// if we get here, there was no player with name name
	return NO_SUCH_PLAYER;
}

void playerPrint (unsigned int player_index)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());

	cout        << setw(8) << left << players[player_index].name
	     << "$" << setw(4) << left << players[player_index].money
		 << "#" << setw(4) << left << players[player_index].dice
	     << "*" << setw(4) << left << players[player_index].points << endl;
}

const string& playerGetName (unsigned int player_index)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());

	return players[player_index].name;
}

char playerGetTileChar (unsigned int player_index)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());

	assert(players[player_index].name.size() > 0);
	return players[player_index].name[0];
}

bool playerHasMoney (unsigned int player_index,
                     int money)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(money >= 0);

	if(players[player_index].money >= money)
		return true;
	else
		return false;
}

bool playerHasDice (unsigned int player_index,
                    int dice)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(dice >= 0);

	if(players[player_index].dice >= dice)
		return true;
	else
		return false;
}

bool playerHasPointsAnyone (int points)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(points >= 0);

	for(unsigned int i = 0; i < player_count; i++)
	{
		if(players[i].points >= points)
			return true;
	}
	return false;
}



void playerIncreaseMoneyAndPrint (unsigned int player_index,
                                  int increase)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(increase >= 0);

	int old_money = players[player_index].money;
	players[player_index].money += increase;
	int new_money = players[player_index].money;
	cout << players[player_index].name << "'s money:"
	     <<   " $" << old_money
	     << " + $" << increase
	     << " = $" << new_money << endl;

	assert(isInvariantTrue());
}

void playerIncreaseDiceAndPrint (unsigned int player_index,
                                 int increase)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(increase >= 0);

	int old_dice = players[player_index].dice;
	players[player_index].dice += increase;
	int new_dice = players[player_index].dice;
	cout << players[player_index].name << "'s dice:"
	     <<   " #" << old_dice
	     << " + #" << increase
	     << " = #" << new_dice << endl;

	assert(isInvariantTrue());
}

void playerIncreasePointsAndPrint (unsigned int player_index,
                                   int increase)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(increase >= 0);

	int old_points = players[player_index].points;
	players[player_index].points += increase;
	int new_points = players[player_index].points;
	cout << players[player_index].name << "'s points:"
	     <<   " *" << old_points
	     << " + *" << increase
	     << " = *" << new_points << endl;

	assert(isInvariantTrue());
}

void playerDecreaseMoney (unsigned int player_index,
                          int decrease)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(decrease >= 0);
	assert(playerHasMoney(player_index, decrease));

	assert(players[player_index].money >= decrease);
	players[player_index].money -= decrease;

	assert(isInvariantTrue());
}

void playerDecreaseDice (unsigned int player_index,
                         int decrease)
{
	assert(isInvariantTrue());
	assert(isInitialized());
	assert(player_index < playerGetCount());
	assert(decrease >= 0);
	assert(playerHasDice(player_index, decrease));

	assert(players[player_index].dice >= decrease);
	players[player_index].dice -= decrease;

	assert(isInvariantTrue());
}

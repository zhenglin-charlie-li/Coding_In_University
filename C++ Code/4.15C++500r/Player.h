//
//  Player.h
//
//  A module to keep track of the information for the players.
//
//  Each player has a name and an amount of money, dice, and
//    points.  The amount of money and the number of dice can be
//    increased and decreased, while the number of points can
//    only be increased.
//
//  This is an encapsulated global service.
//
#pragma once

#include <string>



//
//  PLAYER_COUNT_MIN
//
//  The minimum number of players in the game.
//
const unsigned int PLAYER_COUNT_MIN = 1;

//
//  PLAYER_COUNT_MAX
//
//  The maximum number of players in the game.
//
const unsigned int PLAYER_COUNT_MAX = 4;

//
//  NO_SUCH_PLAYER
//
//  A special value indicating that there was not a player with
//    the requested name.
//
const unsigned int NO_SUCH_PLAYER = 999999;



//
//  playerInit
//
//  Purpose: To initialize the Player module for the specified
//           players.  Each player starts with $0 money, #1 die,
//           and *0 points.
//  Parameter(s):
//    <1> count: The number of players in the game
//    <2> names: The player names
//  Precondition(s):
//    <1> count >= PLAYER_COUNT_MIN
//    <2> count <  PLAYER_COUNT_MAX
//    <3> names[i] != ""        WHERE 0 <= i < count
//  Returns: N/A
//  Side Effect: The players module is initialized to contain
//               count players with the first count names in
//               names.  If the module was already initialized,
//               all infromation about the previous players is
//               lost.
//
void playerInit (unsigned int count,
                 const std::string names[]);



//
//  isInitialized
//
//  Purpose: To determine whether the player module has been
//           initialized.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the player module is initialized.
//  Side Effect: N/A
//
unsigned int isInitialized ();

//
//  playerGetCount
//
//  Purpose: To determine the number of players in the game.
//  Parameter(s): N/A
//  Precondition(s):
//    <1> isInitialized()
//  Returns: How many players in the game.
//  Side Effect: N/A
//
unsigned int playerGetCount ();

//
//  playerGetIndex
//
//  Purpose: To determine the index of the player with the
//           specified name.
//  Parameter(s):
//    <1> name: The player name
//  Precondition(s):
//    <1> isInitialized()
//    <2> name != ""
//  Returns: The index of the player with name name.  If there
//           isn't a player with that name, NO_SUCH_PLAYER is
//           returned.
//  Side Effect: N/A
//
unsigned int playerGetIndex (const std::string& name);

//
//  playerPrint
//
//  Purpose: To print the information for the specified player.
//  Parameter(s):
//    <1> player_index: Which player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//  Returns: N/A
//  Side Effect: The name, money, dice, and points for player
//               player_index is printed to standard output
//               (cout).
//
void playerPrint (unsigned int player_index);



//
//  playerGetName
//
//  Purpose: To determine the specified player's name.
//  Parameter(s):
//    <1> player_index: Which player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//  Returns: The name of player player_index.
//  Side Effect: N/A
//
const std::string& playerGetName (unsigned int who);

//
//  playerGetTileChar
//
//  Purpose: To determine the character that the specified
//           player uses to mark tile ownership.
//  Parameter(s):
//    <1> player_index: Which player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//  Returns: The char used to show that player player_index owns
//           a tile.
//  Side Effect: N/A
//
char playerGetTileChar (unsigned int player_index);

//
//  playerHasMoney
//
//  Purpose: To determine if the specified player has at least
//           the specified amount of money.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> money: How much money to check for
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> money >= 0
//  Returns: Whether player player_index has at least money
//           money.
//  Side Effect: N/A
//
bool playerHasMoney (unsigned int player_index,
                     int money);

//
//  playerHasDice
//
//  Purpose: To determine if the specified player has at least
//           the specified number of dice.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> dice: How many dice to check for
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> dice >= 0
//  Returns: Whether player player_index has at least dice dice.
//  Side Effect: N/A
//
bool playerHasDice (unsigned int player_index,
                    int dice);

//
//  playerHasPointsAny
//
//  Purpose: To determine if any player has at least the
//           specified number of points.
//  Parameter(s):
//    <1> points: How many points to check for
//  Precondition(s):
//    <1> isInitialized()
//    <2> points >= 0
//  Returns: Whether any player has at least points points.
//  Side Effect: N/A
//
bool playerHasPointsAnyone (int points);



//
//  playerIncreaseMoneyAndPrint
//
//  Purpose: To give the specified player the specified amount
//           of additional money.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> increase: How much money to give the player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> increase >= 0
//  Returns: N/A
//  Side Effect: Player player_index gains increase money.  The
//               change to the player's money is printed,
//               including the player name.
//
void playerIncreaseMoneyAndPrint (unsigned int player_index,
                                  int increase);

//
//  playerIncreaseDiceAndPrint
//
//  Purpose: To give the specified player the specified number
//           of additional dice.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> increase: How many dice to give the player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> increase >= 0
//  Returns: N/A
//  Side Effect: Player player_index gains increase dice.  The
//               change to the player's number of dice is
//               printed, including the player name.
//
void playerIncreaseDiceAndPrint (unsigned int player_index,
                                 int increase);

//
//  playerIncreasePointsAndPrint
//
//  Purpose: To give the specified player the specified number
//           of additional points.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> increase: How many points to give the player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> increase >= 0
//  Returns: N/A
//  Side Effect: Player player_index gains increase points.  The
//               change to the player's points is printed,
//               including the player name.
//
void playerIncreasePointsAndPrint (unsigned int player_index,
                                   int increase);

//
//  playerDecreaseMoney
//
//  Purpose: To reduce the specified player's money by the
//           specified amount.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> decrease: How much money to take from the player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> decrease >= 0
//    <4> playerHasdDice(player_index, decrease)
//  Returns: N/A
//  Side Effect: Player player_index loses decrease money.
//
void playerDecreaseMoney (unsigned int player_index,
                          int decrease);

//
//  playerDecreaseDice
//
//  Purpose: To reduce the specified player's number of dice by
//           the specified amount.
//  Parameter(s):
//    <1> player_index: Which player
//    <2> decrease: How many dice to take from the player
//  Precondition(s):
//    <1> isInitialized()
//    <2> player_index < playerGetCount()
//    <3> decrease >= 0
//    <4> playerHasdDice(player_index, decrease)
//  Returns: N/A
//  Side Effect: Player player_index loses decrease dice.
//
void playerDecreaseDice (unsigned int player_index,
                         int decrease);
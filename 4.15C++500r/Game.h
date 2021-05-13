#ifndef HOMEWORK4_GAME_H
#define HOMEWORK4_GAME_H

#endif //HOMEWORK4_GAME_H
const int PLAYER_NAME = 2;
class Game{
private:
    int playerCount;
    string playerName[10];
//    AvailableTiles availableTiles;
public:
    Board board;
    int dice1,dice2,dice3,dice4;
    Game ();
    void printState (unsigned int whose_turn) const;
    void handleDiceRoll (unsigned int whose_turn);
    bool purchaseTile (unsigned int whose_turn);
};
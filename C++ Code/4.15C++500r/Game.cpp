#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
#include "Board.h"
#include "Dice.h"
#include "BoardSize.h"
#include "Player.h"
#include "Game.h"
#include "CellChooser.h"


Game::Game (){
    this->playerCount=2;
    this->playerName[0]="Bob";
    this->playerName[1]="Sarah";
    playerInit(this->playerCount,this->playerName);
}
void Game::printState (unsigned int whose_turn) const{
    assert(whose_turn<playerGetCount());
    this->board.print();
    cout<<endl;
//    this->availableTiles.print();
}
void Game::handleDiceRoll (unsigned int whose_turn){
    assert(whose_turn<playerGetCount());
    int index=playerGetIndex(playerGetName(whose_turn));
    int row,col;
    if(playerHasDice(index,1)){
        this->dice1 = diceRoll();
        this->dice2 = diceRoll();
        this->dice3 = diceRoll();
        this->dice4 = diceRoll();
        int x=diceRoll();
        string line;
        dicePrint2and2and1(this->dice1,this->dice2,this->dice3,this->dice4,x);
        CellChooser cellChooser(this->dice1,this->dice2,this->dice3,this->dice4,x, true);
        playerDecreaseDice(index,1);
        cellChooser.printAvailable();
        cout<<"Choose a cell to roll: ";
        getline(cin,line);
        row=line[0]-'A';
        col=line[1]-'0';
    }
    else {
        this->dice1 = diceRoll();
        this->dice2 = diceRoll();
        this->dice3 = diceRoll();
        this->dice4 = diceRoll();
        dicePrint2and2(this->dice1, this->dice2, this->dice3, this->dice4);
        CellId cell = toCellId(this->dice1 + this->dice2, this->dice3 + this->dice4);
        cout << "Rolled cell: " << cell << endl;
        row=this->dice1 + this->dice2;
        col=this->dice3 + this->dice4;
    }

}
bool Game::purchaseTile (unsigned int whose_turn){
    assert(whose_turn<playerGetCount());
    int index=playerGetIndex(this->playerName[whose_turn]),num;
    playerPrint(index);
    cout<<"Choose a cell to place a tile: ";
    string line;
    getline(cin,line);
    if (line == "q")return true;
    cout<<"Choose a tile to buy (by index): ";
    cin>>num;
    if(num>=0&&num<=4){
            cout<<"Success: Tile added"<<endl;
        }
        else{
            cout<<"Failure: Money not enough"<<endl;
        }
    return false;
}
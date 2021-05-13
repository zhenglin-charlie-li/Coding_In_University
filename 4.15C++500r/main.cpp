//name:Lisong.zhang
//SID:200390303
//date:Feb,7,2021


#include <string>
#include <iostream>
#include <cstring>
#include "Board.h"
#include "Dice.h"
#include "BoardSize.h"
#include "Player.h"
#include "AvailableTiles.h"
#include "Game.h"


using namespace std;



int main() {
    Game game;
    cout<<"Welcome to the game."<<endl<<endl;
    while (true){
        for(int i=0;i<playerGetCount();i++){
            int row,col;
            int index=playerGetIndex(playerGetName(i));
            game.printState(index);cout<<endl;
            cout<<playerGetName(i)<<"'s turn:"<<endl<<endl;
            game.handleDiceRoll(index);cout<<endl;
            if(game.purchaseTile(index)){
                return 0;
            }
        }
    }
}
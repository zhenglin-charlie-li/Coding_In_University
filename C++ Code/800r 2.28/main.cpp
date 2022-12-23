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


using namespace std;

const int PLAYER_NAME = 2;
string PlayerName[PLAYER_NAME]={"Bob","Sarah"};


int main1() {
    playerInit(PLAYER_NAME,PlayerName);
    Board board;
    board.print();
    AvailableTiles availableTiles;
    while (true){
        for(int i=0;i<PLAYER_NAME;i++){
            availableTiles.print();
            cout << endl << "Player " << PlayerName[i] << "'s turn" << endl;
            bool isrolled=0;
            int index=playerGetIndex(PlayerName[i]);
            int a = diceRoll();
            int b = diceRoll();
            int c = diceRoll();
            int d = diceRoll();
            dicePrint2and2(a,b,c,d);
            cout << "Rolled cell: " << getRowName(a+b) << getColumnName(c+d) << endl;
            if(board.getAt(CellId(a+b,c+d)).getGenus()==GENUS_MONEY){
                playerIncreaseMoneyAndPrint(index,board.getAt(CellId(a+b,c+d)).getSpecies());
            }
            if(board.getAt(CellId(a+b,c+d)).getGenus()!=GENUS_MONEY){
                if(board.getAt(CellId(a+b,c+d)).getAffectedPlayer(index)!=index)
                playerIncreasePointsAndPrint(index,board.getAt(CellId(a+b,c+d)).getSpecies());
            }
            cout << "Which tile do you want to put there?"<<endl;
            cout<<">";
            string line;
            getline(cin,line);
            if (line == "q")
                break;
            int num=line[0]-'0';
            if(num>=0&&num<=4){
                if(playerHasMoney(index,availableTiles.getCost(num))){
                    isrolled=1;
                    playerDecreaseMoney(index,availableTiles.getCost(num));
                    Tile tmp=availableTiles.getTile(num);
                    availableTiles.replaceAt(num);
                    tmp.setOwner(index);
                    //tmp=board.getAt(CellId(a+b,c+d));
                    //tmp.activate(index);
                    board.setAt(CellId(a+b,c+d),tmp,index);
                }
            }
            if(!isrolled)cout<<"fail to buy"<<endl;
        }
    }
}

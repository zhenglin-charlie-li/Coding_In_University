#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

void diceInit ()
{
  srand((unsigned int)time(NULL));
}

int diceRoll ()
{
  return rand()% DICE_SIDE_COUNT;
}

void dicePrint2and2 (int r1, int r2, int c1, int c2)
{cout<<
  "    Row           Column"<<endl<<
		"+---+ +---+     +---+ +---+"<<endl<<
		"| "<<r1<<" | | "<<r2<<" |     | "<<c1<<" | | "<<c2<<" |"<<endl<<
		"+---+ +---+     +---+ +---+"<<endl
    ;
}
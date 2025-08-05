#include <iostream>
#include "gamerule.h"
#include "constants.h"

bool checkWin(const std::array<std::array<int, MAX_GRIP>, MAX_GRIP>& boardState, int side)
{	
	// check columns and rows in the board
	for(int i = FIRST; i <= LAST; i++)
	{
		if(boardState[FIRST][i] == side && boardState[1][i] == side && 
boardState[LAST][i] == side)
		{	
//			std::cout << "Row : " << i << '\n'; 
			return true; 
		}

		if(boardState[i][FIRST] == side && boardState[i][1] == side && 
boardState[i][LAST] == side)
		{	
//			std::cout << "Col : " << i << '\n'; 
			return true; 
		}
	}
	
	// check diagonals in the board
	if(boardState[FIRST][FIRST] == side && boardState[1][1] == side && 
boardState[LAST][LAST] == side)
	{
//		std::cout << "diag : FIRST,FIRST to LAST,LAST\n";
		return true;
	}
	
	if(boardState[FIRST][LAST] == side && boardState[1][1] == side && 
boardState[LAST][FIRST] == side)
	{
//		std::cout << "diag : FIRST,LAST to LAST,FIRST\n";
		return true;
	}

//	std::cout << "Not exist yet!\n";
	return false;
}

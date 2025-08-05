#include <iostream>
#include "gamerule.h"

bool checkWin(const std::array<std::array<int, 3>, 3>& boardState, int side)
{	
	
	// check columns and rows in the board
	for(int i = 0; i < 3; i++)
	{
		if(boardState[0][i] == side && boardState[1][i] == side && 
boardState[2][i] == side)
		{	
//			std::cout << "Row : " << i << '\n'; 
			return true; 
		}

		if(boardState[i][0] == side && boardState[i][1] == side && 
boardState[i][2] == side)
		{	
//			std::cout << "Col : " << i << '\n'; 
			return true; 
		}
	}
	
	// check diagonals in the board
	if(boardState[0][0] == side && boardState[1][1] == side && 
boardState[2][2] == side)
	{
//		std::cout << "diag : 0,0 to 2,2\n";
		return true;
	}
	
	if(boardState[0][2] == side && boardState[1][1] == side && 
boardState[2][0] == side)
	{
//		std::cout << "diag : 0,2 to 2,0\n";
		return true;
	}

//	std::cout << "Not exist yet!\n";
	return false;
}

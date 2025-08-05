#include <iostream>
#include "print.h"
#include "constants.h"

void printBoard(const std::array<std::array<int, MAX_GRIP>, MAX_GRIP>& boardState)
{
	for(int i = FIRST; i <= LAST; i++)
	{	
		for(int j = FIRST; j <= LAST; j++)
		{
			if(boardState[i][j] == EMPTY) std::cout << '.' << ' ';
			if(boardState[i][j] == PLAYER_0) std::cout << 'O' << ' ';
			if(boardState[i][j] == PLAYER_1) std::cout << 'X' << ' ';
		}
		std::cout << "\n";
	}
}

void printWelcomeScreen()
{
	std::cout << "TicTacToe (v1.0) by NTA2008\n\n";
	std::cout << "Play [P]\n";
	std::cout << "Quit [Q]\n";
}

void clearScreen()
{
	#if defined(_WIN32)
		system("cls");
	#else 
		system("clear");
	#endif
}

#include <iostream>
#include "print.h"

void printBoard(const std::array<std::array<int, 3>, 3>& boardState)
{
	for(int i = 0; i < 3; i++)
	{	
		for(int j = 0; j < 3; j++)
		{
			if(boardState[i][j] == 9) std::cout << '.' << ' ';
			if(boardState[i][j] == 1) std::cout << 'O' << ' ';
			if(boardState[i][j] == 0) std::cout << 'X' << ' ';
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

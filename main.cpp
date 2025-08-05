#include <iostream>
#include <array>
#include <utility>
#include <limits>
#include <cctype>
#include "print.h"
#include "gamerule.h"
#include "constants.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

bool clearFailedExtraction()
{
	if(!std::cin)
	{
		if(std::cin.eof())
		{
			std::exit(0); // exit if user enter the EOF charactor
		}
		
		std::cin.clear();
		ignoreLine();
		
		return true;
	}
	
	return false;
}

bool checkIndexInRange(int i)
{
	return (i >= FIRST && i <= LAST);
}

template<typename T> 
T getInput()
{	
	T x;
	std::cout << "Enter your input: ";
	std::cin >> x;
	
	while(clearFailedExtraction())
	{
		std::cout << "Please try again!\n";
		std::cin >> x;
		if(hasUnextractedInput())
		{
			ignoreLine();
		}
	}
	
	return x;
}

std::pair<int, int> getBoardPosInput()
{
	std::pair<int, int> pos;
	std::cout << "Enter your position (x, y): ";
	std::cin >> pos.first >> pos.second;
	
	// check for failed extraction or meaningless posut
	while(clearFailedExtraction() ||
		  !checkIndexInRange(pos.first) ||
		  !checkIndexInRange(pos.second))
	{
		std::cout << "Please try again!\n";
		std::cin >> pos.first >> pos.second;
		if(hasUnextractedInput())
		{
			ignoreLine(); // ignore unextracted input
		}
	}
	
	return pos;
}

int main()
{	
	clearScreen();
	printWelcomeScreen();
	char input{ static_cast<char>(std::toupper(getInput<char>())) };
	
	if(input == 'Q') return 0;
	while((input != 'Q' && input != 'P') || clearFailedExtraction())
	{
		std::cout << "Please try again!\n";
		input = getInput<char>();
	}
	
	while(true)
	{	
		clearScreen();
		std::array<std::array<int, MAX_GRIP>, MAX_GRIP> boardState // create a empty board
		{{
			{{EMPTY, EMPTY, EMPTY}},
			{{EMPTY, EMPTY, EMPTY}},
			{{EMPTY, EMPTY, EMPTY}}
		}};
		int side{ PLAYER_0 };
		int turns{};
		
		while(!checkWin(boardState, side) && turns < MAX_TURN)
		{		
			clearScreen();
			printBoard(boardState);
		
			std::pair<int, int> pos{ getBoardPosInput() };
		
			while(boardState[pos.first][pos.second] != EMPTY)
			{
				std::cout << "Cell already taken. Try again.\n";
				pos = getBoardPosInput();
			}
			boardState[pos.first][pos.second] = side;
			turns++; // increase turn each time the side has completed their move
			
			if(checkWin(boardState, side) == true || turns == MAX_TURN)
				break;
			
			side = (side == PLAYER_0 ? PLAYER_1 : PLAYER_0); // change side each time player enter his input

	}	
		clearScreen();
		printBoard(boardState);
		if(turns == MAX_TURN && !checkWin(boardState, side))
		{
			std::cout << "It's a draw!\n";
		}
		else
		{
			if(side == PLAYER_1) std::cout << "PLAYER_1 WIN!\n";
			else std::cout << "PLAYER_0 WIN!\n";
		}
		
		std::cout << "Do you want to continue?\n";
		std::cout << "Yes [Y]\n";
		std::cout << "No [N]\n";
		input = static_cast<char>(std::toupper(getInput<char>()));
		if(input == 'N') break;
		while((input != 'N' && input != 'Y') || clearFailedExtraction())
		{
			std::cout << "Please try again!\n";
			input = static_cast<char>(std::toupper(getInput<char>()));
			if(hasUnextractedInput())
			{
				ignoreLine();
			}
		}
		
	}
    return PLAYER_0;
}

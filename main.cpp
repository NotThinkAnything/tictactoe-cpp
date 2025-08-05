#include <iostream>
#include <array>
#include <utility>
#include <limits>
#include <cctype>
#include "print.h"
#include "gamerule.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
	if(!std::cin)
	{
		if(std::cin.eof())
		{
			std::exit(0);
		}
		
		std::cin.clear();
		ignoreLine();
		
		return true;
	}
	
	return false;
}

bool checkIndexInRange(int i)
{
	return (i >= 0 && i <= 2);
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
	}
	
	return x;
}

std::pair<int, int> getInput()
{
	std::pair<int, int> pos;
	std::cout << "Enter your position (x, y): ";
	std::cin >> pos.first >> pos.second;
	
	// check for failed extraction or meaningless posut
	while(clearFailedExtraction() || !checkIndexInRange(pos.first)
 || !checkIndexInRange(pos.second))
	{
		std::cout << "Please try again!\n";
		std::cin >> pos.first >> pos.second;
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
		std::array<std::array<int, 3>, 3> boardState // create a empty board
		{{
			{{9, 9, 9}},
			{{9, 9, 9}},
			{{9, 9, 9}}
		}};
		int side{ 1 };
		int turns{};
		
		while(!checkWin(boardState, side) && turns < 9)
		{		
			clearScreen();
			side = (side == 0 ? 1 : 0); // change side each time the loop is repeated
			printBoard(boardState);
		
			std::pair<int, int> pos{ getInput() };
		
			while(boardState[pos.first][pos.second] == 0 
		|| boardState[pos.first][pos.second] == 1)
			{
				std::cout << "Cell already taken. Try again.\n";
				pos = getInput();
			}
			boardState[pos.first][pos.second] = side;

			turns++; // increase turn each time the side has completed their move
	}	
		clearScreen();
		printBoard(boardState);
		if(turns == 9 && !checkWin(boardState, side))
		{
			std::cout << "It's a draw!\n";
		}
		else
		{
			if(side == 1) std::cout << "1 WIN!\n";
			else std::cout << "0 WIN!\n";
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
		}
		
	}
    return 0;
}

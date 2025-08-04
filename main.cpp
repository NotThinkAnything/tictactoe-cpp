#include <iostream>
#include <array>
#include <utility>
#include <limits>
#include <cctype>

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

bool checkNumber(int i)
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

void printBoard(std::array<std::array<int, 3>, 3> boardState)
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

std::pair<int, int> getInput()
{
	std::pair<int, int> pos;
	std::cout << "Enter your position (x, y): ";
	std::cin >> pos.first >> pos.second;
	
	// check for failed extraction or meaningless posut
	while(clearFailedExtraction() || !checkNumber(pos.first) || !checkNumber(pos.second))
	{
		std::cout << "Please try again!\n";
		std::cin >> pos.first >> pos.second;
	}
	
	return pos;
}

bool checkWin(std::array<std::array<int, 3>, 3> boardState, int side)
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

int main()
{	
	system("clear");
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
		system("clear");
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
			system("clear");
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
			input = getInput<char>();
		}
		
	}
    return 0;
}

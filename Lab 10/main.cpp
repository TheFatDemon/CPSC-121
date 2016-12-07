//Eric May
//CPSC 121 Final Lab
//5/8/2016
#include "TicTacToe.h"
#include <iostream>

int main()
{
	//The instance of our class that will be used
	TicTacToe game;
	int res = 0;
	do { 
		//Tell user if the last move was invalid
		if (res == -1)
			std::cout << "Invalid position. Try again.\n";
		//Show current game state
		game.displayBoard();
		//Prompt user for desired move
		std::cout << "Player " << game.nextPlayer << "'s turn. Enter 0-8: ";
		int pos;
		std::cin >> pos;
		//Attempt to make provided move
		res = game.makeMove(pos);
	} while (res <= 0); //While game isn't over
	if (res == 3)//Cat's game
		std::cout << "Nobody wins!\n";
	else//Victory achieved
		std::cout << "Player " << res << " has won!\n";
	system("pause");
	return 0;
}
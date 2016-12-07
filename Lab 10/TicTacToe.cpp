#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			board[x][y] = 0;
		}
	}
	nextPlayer = 1;
}

int TicTacToe::checkWin() {

	// We are checking if the last player won
	int lastPlayer = 0;
	if (nextPlayer == 2) {
		lastPlayer = 1;
	}
	else {
		lastPlayer = 2;
	}

	// Iterate through each column
	for (int x = 0; x < 3; x++)
	{
		// Iterate through each row
		for (int y = 0; y < 3; y++) {
			if (board[x][y] != lastPlayer) {
				// If the spot does not equal the last player's number, last player didn't win
				break;
			}
			if (y == 2) {
				return lastPlayer;
			}
		}
	}

	return 0;
}

void TicTacToe::displayBoard() {
	// Really overly complicated loop to display board
	cout << "+-+-+-+" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << "|";
		}
		cout << endl;
		cout << "+-+-+-+" << endl;
	}
}

int TicTacToe::makeMove(int position) {
	// Check to make sure `position` is within 0-8 range
	if (position < 0 || position > 8) {
		return -1;
	}

	// We now need to get the x and y of the position, relative to the board
	int x = position / 3; // Ex: 5 / 3 = 1
	int y = position % 3; // Ex: 5 % 3 = 2

	// Now that we have X and Y, we check the board if the value is in there already
	if (board[x][y] == 1 || board[x][y] == 2) {
		// The spot is taken
		return -1;
	}
	else {
		// Empty spot WHOO!
		board[x][y] = nextPlayer;
	}

	// Indicate next player
	// If nextPlayer = 1, set it to 2, else set it to 1
	if (nextPlayer == 2) {
		nextPlayer = 1;
	}
	else {
		nextPlayer = 2;
	}

	return checkWin();
}

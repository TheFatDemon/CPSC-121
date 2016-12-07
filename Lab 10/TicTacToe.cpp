#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {

}

int TicTacToe::checkWin() {
	return 0;
}

void TicTacToe::displayBoard() {
	// Really overly complicated loop to display board
	cout << "+-+-+-+" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; i < 3; i++) {
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
	return checkWin();
}

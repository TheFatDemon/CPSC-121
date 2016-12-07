
#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {

}

int TicTacToe::checkWin() {
	return 0;
}

void TicTacToe::displayBoard() {

	cout << "+-+-+-+" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; i < 3; i++) {
			cout << board[i][j] << "|";
		}
		cout << endl;
	}
	cout << "+-+-+-+" << endl;
}

int TicTacToe::makeMove(int position) {
	return 0;
}

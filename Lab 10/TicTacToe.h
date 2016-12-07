//Eric May
//CPSC 121 Final Lab
//5/8/2016
#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
//Contains methods allowing for a user to play a game of tic-tac-toe
class TicTacToe {
private:
	//Board stores a 0 to indicate an empty position, or 1/2 if a player is occupying it
	int board[3][3];
	//Returns 1 or 2 if the respective player has won, 0 if there is no winner, or 3 if the game ends without a winner
	int checkWin();
public:
	//Used to indicate if the next move will be performed by player 1 or player 2
	int nextPlayer;
	//Default constructor, begins game with an empty board
	TicTacToe();
	//Note: Since we aren't dynamically allocating memory, there's no need for a deconstructor
	//Displays the current state of the board
	void displayBoard();
	/*	Returns -1 to indicate an invalid move, or the results of checkWin if the move is valid
	Board Position Mapping
	0	1	2
	3	4	5
	6	7	8
	Use 1-9 if that's easier for you, but make sure you document it!	*/
	int makeMove(int position);
};
#endif // !TICTACTOE_H

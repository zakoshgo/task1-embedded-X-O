#pragma warning(disable : 4996)
#include<stdio.h>

void printBoard(char board[][3]) {
	system("cls");
	for (int rows = 0; rows < 3; rows++) {
		for (int coloum = 0; coloum < 3; coloum++) {
			printf("		%c  ", board[rows][coloum]);
		}
		printf("\n");
	}
}

void move(char board[][3], char mark) {
	int validFlag = 0;
	char pos;
	if (mark == 'X')
		printf("player 1 turn \n");
	else
		printf("player 2 turn \n");
	while (validFlag == 0) {
		printf("choose position to put you mark :) \n");
		scanf(" %c", &pos);


		for (int rows = 0; rows < 3; rows++) {
			for (int coloum = 0; coloum < 3; coloum++) {
				if (board[rows][coloum] == pos) {
					board[rows][coloum] = mark;
					validFlag = 1;
				}
			}

		}
		if (validFlag == 0) {
			printf("This place already filled \n");
		}
	}

}

int gameResultFn(char board[][3]) {
	
	for (int rows = 0; rows < 3; rows++) { // for horizontal 
		int counterX = 0;
		int counterO = 0;
		for (int coloum = 0; coloum < 3; coloum++) {                 //////  X   X  X
			if (board[rows][coloum] == 'X') {						//////   O   4  O
				counterX++;											//////   O   7  8
			}
			else if (board[rows][coloum] == 'O')
				counterO++;
		}
		if (counterX == 3) {
			return 1;
		}
		else if (counterO == 3) {
			return -1;
		}
	}

	for (int coloum = 0; coloum < 3; coloum++) { //for virtical        //////  X   O  O
		int counterX = 0;											   //////  X   4  O
		int counterO = 0;											   //////  X   7  8
		for (int rows = 0; rows < 3; rows++) {
			if (board[rows][coloum] == 'X') {
				counterX++;
			}
			else if (board[rows][coloum] == 'O')
				counterO++;
		}
		if (counterX == 3) {
			return 1;
		}
		else if (counterO == 3) {
			return -1;
		}
	}

	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') { // check main diagonal for X
		return 1;
	}
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') { // check secondary diagonal for X
		return 1;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {// check main diagonal for O
		return -1;
	}
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {// check secondary diagonal for O
		return -1;
	}
	else return 0;
}

void main() {
	int playAgain = 1;
	
	while (playAgain == 1) {
		int gameResult = 0;
		char currentPlayer = 'X';
		char board[3][3] = { '0','1','2','3','4','5','6','7','8' };
		printBoard(board);
		printf("player 1 is X \nplayer 2 is O \n");
		int counter = 0;
		while (counter < 9 && (gameResult == 0)) {
			counter++;
			move(board, currentPlayer);
			printBoard(board);
			gameResult = gameResultFn(board);
			if (gameResult == 1)
				printf("player 1 won \n");
			else if (gameResult == -1)
				printf("player 2 won \n");
			if (currentPlayer == 'X')
				currentPlayer = 'O';
			else
				currentPlayer = 'X';

		}
		if (counter == 9) {
			printf("Draw \n");
		}
		printf("do you want to play again ? \n press 1 for yes \n press 0 for no \n");
		scanf("%d", &playAgain);
	}
	system("pause");
}
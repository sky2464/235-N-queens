//============================================================================
// Name        : queen-n.cpp
// Author      : Navid Saboori, Usman
// Version     : 2
// Professor   : Elaheh Vahdani
// Copyright   : Your copyright notice
// Description : Queen.cpp in C++, Ansi-style
//============================================================================



// PRE PROCESSOR DIRECTIVE
#include <bits/stdc++.h>

// NAMESPACE USED
using namespace std;

// WE ARE CONSIDERING nXn CHESS BOARD, THEREFORE, DEFINING N = user defined, but for the purpose of time and resource efficiency
// for this project, user should manually change the define N 10 to some other number!
#define N 12

// PROTOTYPE DECLARATION
bool isQueenSafe(char chessBoard[][N], int r, int c);
void nQueen(char chessBoard[][N], int r, int c);

// MAIN METHOD STARTS HERE

int main() {

// THIS ARRAY WILL KEEP TRACK OF THE POSITIONS OF QUEENS IN CURRENT CONFIGURATIONS
	char chessBoard[N][N];

// CHESS BOARD IS INITIALISED BY HYPHEN VALUE
	memset(chessBoard, '0', sizeof chessBoard);

// BLANK CHESS BOARD IS THEN PASSED TO THE nQueen PROBLEM
	nQueen(chessBoard, 0, 0);

	return 0;
}

// THIS METHOD IS CALLED FROM THE MAIN METHOD

void nQueen(char chessBoard[][N], int r, int c) {

// TO PRINT ONLY 10 SOLUTIONS, TAKE A STATIC VARIABLE TO COUNT THROUGH 10
	static int countSolutions = 0;

// IF N QUEENS ARE IN CORRECT POSITION AS REQUIRED, THEN PRINT THE SOLUTION
// IF USER WANT TO GET ORE SOLUTIONS, CHANGE 1 TO YOUR REQUIRED COUNT
// IF REMOVE THE CONDITIONAL STATEMENT USER CAN ALL SOLUTIONS


	if (countSolutions < 1) {
		if (c == 0 && r == N) {
			countSolutions++;
			cout << "\n\nSOLUTION NUMBER " << countSolutions << " :\n" << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					cout << chessBoard[i][j] << " ";
				cout << endl;
			}
			cout << endl;
			return;
		}
	}

// PLACE THE QUEEN AT EVERY SQUARE IN THE CURRENT ROW AND CHECK FOR VALID MOVE
	for (int i = 0; i < N; i++) {

// IF TWO CURRENT QUEENS ARE IN SAFE POSITIONS
		if (isQueenSafe(chessBoard, r, i)) {

// PLACE THE QUEEN ON THE CURRENT SQUARE ON CHESS BOARD
			chessBoard[r][i] = '1';

// RECURSIVELY CHECK FOR THE NEXT ROW
			nQueen(chessBoard, r + 1, 0);

// REMOVE QUEEN FROM QUEEN SQUARE AFTER BACKTRACKING
			chessBoard[r][i] = '0';
		}
	}
}

// THIS METHOD WILL CHECK WHETHER TWO SUBSEQUENT QUEENS THREATENS EACH OTHER OR NOT

bool isQueenSafe(char chessBoard[][N], int r, int c) {

// THIS LOOP WILL RETURN FALSE WHEN TWO QUEENS SHARE THE SAME COLUMN
	for (int i = 0; i < r; i++)
		if (chessBoard[i][c] == '1')
			return false;

// THIS LOOP WILL RETURN FALSE WHEN TWO QUEENS SHARE THE SAME DIAGONAL BOXES (\)
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (chessBoard[i][j] == '1')
			return false;

// THIS LOOP WILL RETURN FALSE WHEN TWO QUEENS SHARE THE SAME DIAGONAL BOXES (/)
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (chessBoard[i][j] == '1')
			return false;

	return true; // OTHERWISE WILL RETURN TRUE
}

/*
 * Test:

FOR N == 10


SOLUTION NUMBER 1 :

1 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0


____________________

n= 11;
SOLUTION NUMBER 1 :

1 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0



		*/

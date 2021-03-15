#pragma once

#include <iostream>
#include "Gaming_Board.h"
using namespace std;

class Board_Human : public Gaming_Board
{
public:
	Board_Human() :Gaming_Board() {};
	~Board_Human() {};

	vector<vector<char>> show() // initializarea plansei de joc a jucatorului
	{
		vector<vector<char>> copy_board;
		vector<char>board1;
		for (int i = 0; i < 11; i++)
			board1.push_back('0');
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				copy_board.push_back(board1);

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
				if (i == 0 && j == 0) copy_board[i][j] = ' ';
				else if (j == 0 && i == 1)copy_board[i][j] = 'A';
				else if (j == 0 && i == 2)copy_board[i][j] = 'B';
				else if (j == 0 && i == 3)copy_board[i][j] = 'C';
				else if (j == 0 && i == 4)copy_board[i][j] = 'D';
				else if (j == 0 && i == 5)copy_board[i][j] = 'E';
				else if (j == 0 && i == 6)copy_board[i][j] = 'F';
				else if (j == 0 && i == 7)copy_board[i][j] = 'G';
				else if (j == 0 && i == 8)copy_board[i][j] = 'H';
				else if (j == 0 && i == 9)copy_board[i][j] = 'I';
				else if (j == 0 && i == 10)copy_board[i][j] = 'J';
				else if (i == 0)copy_board[i][j] = char(j + '0');
				else if (this->board[i][j] == 0) copy_board[i][j] = char(248);
				else if (this->board[i][j] == 1) copy_board[i][j] = char(219);
				else if (this->board[i][j] == 2 || this->board[i][j] == 3) copy_board[i][j] = char(254);
		}
		return copy_board;
	}

};
#include "Gaming_Board.h"
#include "Human_Board.h"
#include "Pc_Board.h"


Gaming_Board::Gaming_Board()
{
}

Gaming_Board::~Gaming_Board()
{
}

void Gaming_Board::init_board() // INitializarea plansei de joc
{
	vector<int>board1;
	for (int i = 0; i < 11; i++)
		board1.push_back(0);
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			this->board.push_back(board1);
}

int Gaming_Board::get_element(int i, int j) // get element
{
	return this->board[i][j];
}

void Gaming_Board::add(int i, int j, int element) // adaugarea unui element
{
	this->board[i][j] = element;
}

void Gaming_Board::update(int i, int j, int element) // modificarea unui element
{
	this->board[i][j] = element;
}

vector<vector<int>> Gaming_Board::show_board() // afisarea plansei de joc
{
	return this->board;
}
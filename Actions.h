#pragma once
#include "Gaming_Board.h"
#include "Human_Board.h"
#include "Pc_Board.h"
#include <cstdlib>
#include <time.h>

class Actions
{
protected:
	Gaming_Board* human_gb = new Board_Human;
	Gaming_Board* pc_gb = new Pc_Board;
public:
	Actions();
	Actions(Gaming_Board* human_gb, Gaming_Board* pv_gb);
	~Actions();
	void create_board_all();
	void restart_board_all();
	void atack_human_board();
	void atack_pc_board(string s);
	void add_ships_human_board(string s, string type);
	void add_ships_pc_board();
	bool verify_human_board();
	bool verify_pc_board();
	vector<vector<int>> show_board_int_h();
	vector<vector<int>> show_board_int_p();
	vector<vector<char>> show_board_char_h();
	vector<vector<char>> show_board_char_p();

};

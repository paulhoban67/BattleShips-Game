#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include "Actions.h"
using namespace std;

class User_Interface
{
private:
	Actions actions;
	void show();
	void restart_board();
	void display();
	void add_ships_human();
	void add_ships_pc();
	void atack_ships_human();
	void atack_ships_pc();
	bool verify_board_human();
	bool verify_board_pc();

public:
	User_Interface();
	User_Interface(Actions& a);
	~User_Interface();
	void run();

};

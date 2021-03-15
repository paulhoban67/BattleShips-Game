#include "Actions.h"
#include "Exception.h"

Actions::Actions()
{
}

Actions::Actions(Gaming_Board* human_gb, Gaming_Board* pv_gb)
{
	this->human_gb = human_gb;
	this->pc_gb = pc_gb;
}

Actions::~Actions()
{
}

void Actions::create_board_all() // crearea celor 2 planse de joc
{
	this->human_gb->init_board();
	this->pc_gb->init_board();
}

void Actions::restart_board_all() // restart la plasele de joc
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			this->human_gb->update(i, j, 0);
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			this->pc_gb->update(i, j, 0);
}

void Actions::atack_human_board() // atacul plansei umane de catre pc
{
	int i, j;
	srand(time(NULL));
	do {
		i = rand() % 10;
		j = rand() % 10;
	} while (i == 0 || j == 0 || this->human_gb->get_element(i, j) == 2 || this->human_gb->get_element(i, j) == 3);
	if (this->human_gb->get_element(i, j) == 0)
		this->human_gb->update(i, j, 2);
	else
		if (this->human_gb->get_element(i, j) == 1)
			this->human_gb->update(i, j, 3);
}

void Actions::atack_pc_board(string s) // atacul plansei pc-ului de catre utilizator
{
	string mesage = "";
	if (s[0] < 'A' || s[0] > 'J')
		mesage += "\nERROR: POSITION A-J WRONG\n";
	if (s[1] - '0' < 1 || s[1] - '0' > 9)
		mesage += "ERROR: POSITION 1 - 9 WRONG\n";

	if (this->pc_gb->get_element(s[0] - char(64), s[1] - '0') == 0)
		this->pc_gb->update(s[0] - char(64), s[1] - '0', 2);
	else
		if (this->pc_gb->get_element(s[0] - char(64), s[1] - '0') == 1)
			this->pc_gb->update(s[0] - char(64), s[1] - '0', 3);
	if (mesage.length() > 1) throw Exception(mesage);
}

void Actions::add_ships_human_board(string s, string type) // adaugarea barcilor pe plansa de joc al jucatorului
{
	string mesage = "";
	if (type != "RAZBOI" && type != "YACHT" && type != "SUBMARINE")
		mesage += "\nTYPE SHIPS WRONG\n";
	if (s[0] < 'A' || s[0] > 'J')
		mesage += "ERROR: POSITION A-J WRONG\n";
	if (s[1] - '0' < 1 || s[1] - '0' > 9)
		mesage += "ERROR: POSITION 1 - 9 WRONG\n";

	if (type == "RAZBOI")
		this->human_gb->update(s[0] - char(64), s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 1, s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 2, s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 3, s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 4, s[1] - '0', 1);
	else if (type == "YACHT")
		this->human_gb->update(s[0] - char(64), s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 1, s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 2, s[1] - '0', 1);
	else if (type == "SUBMARINE")
		this->human_gb->update(s[0] - char(64), s[1] - '0', 1), this->human_gb->update(s[0] - char(64) + 1, s[1] - '0', 1);
	if (mesage.length() > 1) throw Exception(mesage);
}

void Actions::add_ships_pc_board() // adaugarea barcilor pe plansa de joc al pc-ului
{
	int i, j, k, l, m, n, o, p, s, t;
	srand(time(NULL));
	do {
		i = rand() % 10;
		j = rand() % 10;
	} while (i == 0 || j == 0 || i > 6);
	this->pc_gb->update(i, j, 1), this->pc_gb->update(i + 1, j, 1), this->pc_gb->update(i + 2, j, 1), this->pc_gb->update(i + 3, j, 1), this->pc_gb->update(i + 4, j, 1);

	do {
		k = rand() % 10;
		l = rand() % 10;
	} while (k == 0 || l == 0 || k > 8 || this->pc_gb->get_element(k, l) == 1);
	this->pc_gb->update(k, l, 1), this->pc_gb->update(k + 1, l, 1), this->pc_gb->update(k + 2, l, 1);

	do {
		m = rand() % 10;
		n = rand() % 10;
	} while (m == 0 || n == 0 || m > 9 || this->pc_gb->get_element(m, n) == 1);
	this->pc_gb->update(m, n, 1), this->pc_gb->update(m + 1, n, 1);

	do {
		o = rand() % 10;
		p = rand() % 10;
	} while (o == 0 || p == 0 || k > 8 || this->pc_gb->get_element(o, p) == 1);
	this->pc_gb->update(o, p, 1), this->pc_gb->update(o + 1, p, 1);
}

bool Actions::verify_human_board() // verificarea daca jucatorul a castigat
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			if (this->human_gb->get_element(i, j) == 1)
				return false;
	return true;
}

bool Actions::verify_pc_board() // verificarea daca pc-ul a castigat
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			if (this->pc_gb->get_element(i, j) == 1)
				return false;
	return true;
}

vector<vector<int>> Actions::show_board_int_h()
{
	return this->human_gb->show_board();
}

vector<vector<int>> Actions::show_board_int_p()
{
	return this->pc_gb->show_board();
}

vector<vector<char>> Actions::show_board_char_h()
{
	return this->human_gb->show();
}

vector<vector<char>> Actions::show_board_char_p()
{
	return this->pc_gb->show();
}

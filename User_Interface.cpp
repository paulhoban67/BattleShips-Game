#include "User_Interface.h"
#include "Exception.h"

HANDLE hCon;

enum Color {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW,
	GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
};

void set_color(Color c) // setarea culorilor aplicatiei
{
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

void User_Interface::show() // afisarea plansei de joc
{
	vector<vector<char>> bch = this->actions.show_board_char_h();
	vector<vector<char>> bcp = this->actions.show_board_char_p();
	vector<vector<int>> bih = this->actions.show_board_int_h();
	vector<vector<int>> bip = this->actions.show_board_int_p();

	for (int i = 0; i < 11; i++)
	{

		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j == 10) cout << "10";
			else
				if (bih[i][j] == 2) set_color(GREEN), cout << bch[i][j] << " ", set_color(GRAY);
				else
					if (bih[i][j] == 3) set_color(RED), cout << bch[i][j] << " ", set_color(GRAY);
					else
						cout << bch[i][j] << " ";
		}
		cout << '\t' << '\t' << '\t';
		for (int j = 0; j < 11; j++)
		{
			set_color(GRAY);
			if (i == 0 && j == 10) cout << "10";
			else
				if (bip[i][j] == 2) set_color(GREEN), cout << bcp[i][j] << " ", set_color(GRAY);
				else
					if (bip[i][j] == 3) set_color(RED), cout << bcp[i][j] << " ", set_color(GRAY);
					else
						if (bip[i][j] == 1) cout << char(248) << " ";
						else
							cout << bcp[i][j] << " ";
		}
		cout << endl;
	}
}

void User_Interface::restart_board() // restartarea jocului
{
	this->actions.restart_board_all();
}

void User_Interface::display() // titlul jocului
{
	cout << '\n';
	cout << "    _______       _____       ________   ________   __       ______      ______   __    __   __   ______   ______       \n";
	cout << "   |   _   " << char(92) << "     /  _  " << char(92) << "     |___  ___| |___  ___| |  |     |  ____|    |   ___| |  |  |  | |  | |   _  | |   ___|      \n";
	cout << "   |  |_|  /    /  / " << char(92) << "  " << char(92) << "       |  |       |  |    |  |     |  |___     |  |___  |  |__|  | |  | |  |_| | |  |___   \n";
	cout << "   |   _  <    /  /___" << char(92) << "  " << char(92) << "      |  |       |  |    |  |     |  ____|    |___   | |   __   | |  | |   ___| |___   |  \n";
	cout << "   |  |_|  " << char(92) << "  /  _______  " << char(92) << "     |  |       |  |    |  |___  |  |___      ___|  | |  |  |  | |  | |  |      ___|  |  \n";
	cout << "   |_______/ /__/       " << char(92) << "__" << char(92) << "    |__|       |__|    |______| |______|    |______| |__|  |__| |__| |__|     |______|  \n";
	cout << "*********************************************************************************************************************\n";
	cout << "\n\n";
}

void User_Interface::add_ships_human() // adaugarea de barci de catre utilizator
{
	try
	{
		string s, type;
		cout << "Type(e.g. RAZBOI): ", cin >> type;
		cout << "Position(e.g. A2): ", cin >> s;
		this->actions.add_ships_human_board(s, type);
	}
	catch (Exception exc)
	{
		cout << exc.what() << '\n';
		this->add_ships_human();
	}
}

void User_Interface::add_ships_pc() // adaugarea de barci de catre pc automat prin metoda random
{
	this->actions.add_ships_pc_board();
}

void User_Interface::atack_ships_human() // atacarea barcilor jucatorului prin metoda random
{
	this->actions.atack_human_board();
}

void User_Interface::atack_ships_pc() // atacarea barcilor pc-ului
{
	try 
	{
		string s;
		cout << "Position(e.g. A2): ", cin >> s;
		this->actions.atack_pc_board(s);
	}
	catch (Exception exc)
	{
		cout << exc.what() << '\n';
		this->atack_ships_pc();
	}
}

bool User_Interface::verify_board_human() // verificarea daca jucatorul a castigat
{
	if (this->actions.verify_human_board())
		return true;
	return false;
}

bool User_Interface::verify_board_pc() // verificarea daca pc-ul a castigat
{
	if (this->actions.verify_pc_board())
		return true;
	return false;
}

User_Interface::User_Interface()
{
}

User_Interface::User_Interface(Actions& a)
{
	
}

User_Interface::~User_Interface()
{
}

void User_Interface::run() // rularea aplicatiei
{
	system("cls");
	this->actions.create_board_all();
	string option;
	display();
	try
	{
		cout << "START A NEW GAME (YES/NO): ", cin >> option;
		while (option == "YES")
		{
			system("cls");
			string name;
			display();
			cout << "NAME: ", cin >> name;
			restart_board();
			system("cls");
			int nr = 0;
			while (nr != 4)
			{
				system("cls");
				display();
				show();
				cout << '\n' << '\n' << "ADD SHIPS!\n";
				this->add_ships_human();
				nr++;
			}
			this->add_ships_pc();
			system("cls");
			display();
			show();
			while (verify_board_human() == false && verify_board_pc() == false)
			{
				cout << '\n' << '\n' << "TIME TO ATTACK!\n";
				atack_ships_pc();
				atack_ships_human();
				system("cls");
				display();
				show();
			}
			system("cls");
			display();
			if (verify_board_human() == 1)
				cout << '\n' << '\n' << "WINNER PC\n", cout << "RESTART THE GAME? (YES/NO): ", cin >> option;

			else
				cout << '\n' << '\n' << "WINNER " << name << '\n', cout << "RESTART THE GAME? (YES/NO): ", cin >> option;
		}
		if (option == "NO")
		{
			system("cls");
			display();
			cout << '\n' << '\n' << "END GAME";
		}
		else throw Exception("");
	}
	catch (Exception msg)
	{
		this->run();
	}	
}

int main()
{
	User_Interface ui;
	ui.run();
}

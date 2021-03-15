//#pragma once
//
//#include "Gaming_Board.h"
//#include "Human_Board.h"
//#include <exception>
//#include <string>
//using namespace std;
//
//class Validate_Gaming_Board
//{
//private:
//	int nr_errors;
//	string message;
//public:
//	Validate_Gaming_Board() { this->nr_errors = 0; };
//	~Validate_Gaming_Board() {};
//	virtual string validate(Gaming_Board* gb = new Board_Human)
//	{
//		this->nr_errors = 0;
//		
//
//
//		if (f->get_date()[2] != f->get_date()[5])
//			this->nr_errors++, this->message += "Format date incorrect; ";
//		if (f->get_place() == " ")
//			this->nr_errors++, this->message += "Place incorrect; ";
//		if (f->get_number_free() < 0 || f->get_number_sold() < 0)
//			this->nr_errors++, this->message += "Number orders wrong; ";
//		if (nr_errors >= 1)
//			return this->message;
//	};
//	//string to_string_v() { return this->message; };
//};
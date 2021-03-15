#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exception : runtime_error
{
private:
	string message;
public:
	Exception(string msg) : runtime_error(msg), message(msg)
	{

	};
	const string what() // exceptiile aplicatiei
	{
		return message;
	}
};
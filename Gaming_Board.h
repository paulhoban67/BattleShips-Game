#pragma once
//REPO

#include<iostream>
#include <vector>
using namespace std;

class Gaming_Board
{
protected:
	vector<vector<int>> board;
public:
	Gaming_Board();
	~Gaming_Board();
    void init_board();
    int get_element(int i, int j);
    void add(int i, int j, int element);
    void update(int i, int j, int element);
    vector<vector<int>> show_board();
    virtual vector<vector<char>> show() = 0;

};


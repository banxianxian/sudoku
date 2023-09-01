#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "simpleStruct.h"
#include "Solution.h"
using namespace std;
class Sudoku {
public:
	Sudoku();
	Sudoku(int level);
	void solve_sudoku();			//Çó½âÊý¶À
	bool change_sudoku(int x, int y, char var);
	bool check_sudoku();
	void delete_sudoku(int i, int j);
	void answer_sudoku();
	char get_sudoku(int i, int j) const { return sudoku[i][j]; };
	vector<vector<char>> get_result() const { return result; };
	
	bool isCanUse[9][9];
private:

	int level;
	char sudoku[9][9];
	vector<vector<char> > result = vector<vector<char>> (9,vector<char>(9));
	string filename[3];
	
};
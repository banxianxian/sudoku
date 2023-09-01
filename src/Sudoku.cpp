#include "Sudoku.h"
#include <fstream>
using namespace std;
Sudoku::Sudoku() {

}

Sudoku::Sudoku(int level) :level(level) {
	//读取需要的数独
	filename[hard] = R"(./hard.dat)";
	filename[middle] = R"(./middle.dat)";
	filename[easy] = R"(./easy.dat)";
	ifstream fin;
	fin.open(filename[level], ios::in | ios::binary);
	if (fin.is_open() == false) {
		cout << "the file " << filename[level] << " cannot open" << endl;
	}
	fin.read((char*)&sudoku, sizeof(sudoku));
	fin.close();


	//求解result,同时标记哪些位置可以填写数字
	solve_sudoku();
}

void Sudoku::solve_sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			result[i][j] = sudoku[i][j];
			if (result[i][j] == '.') {
				isCanUse[i][j] = true;
			}
		}
	}
	unique_ptr<Solution> solve = make_unique<Solution>();
	solve->solveSudoku(result);
}

bool Sudoku::change_sudoku(int x, int y, char var) {
	if (isCanUse[x][y]) {
		sudoku[x][y] = var;
		return true;
	}
	return false;
}

bool Sudoku::check_sudoku() {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] != result[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void Sudoku::delete_sudoku(int i, int j) {

	if(isCanUse[i][j]) sudoku[i][j] = '.';
}

void Sudoku::answer_sudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = result[i][j];
		}
	}
}
#include "Solution.h"
bool Solution::isVaild(vector<vector<char>>& board, int col, int row, int var) {

    //ÐÐ
    for (int i = 0; i < 9; i++) {
        if (board[col][i] != '.' && board[col][i] == var + '0') {
            return false;
        }
    }
    //ÁÐ
    for (int i = 0; i < 9; i++) {
        if (board[i][row] != '.' && board[i][row] == var + '0') {
            return false;
        }
    }

    int areaCol = col / 3;
    int areaRow = row / 3;
    for (int i = areaCol * 3; i < areaCol * 3 + 3; i++) {
        for (int j = areaRow * 3; j < areaRow * 3 + 3; j++) {
            if (board[i][j] != '.' && board[i][j] == var + '0') {
                return false;
            }
        }
    }
    return true;

}

void Solution::backtracking(vector<vector<char>>& board, int k) {

    if (k == width * width) {

        box = board;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int col = k / width;
        int row = k - col * width;

        if (board[col][row] == '.' && isVaild(board, col, row, i)) {
            board[col][row] = '0' + i;
            backtracking(board, k + 1);
            board[col][row] = '.';
        }
        else if (board[col][row] != '.') {
            backtracking(board, k + 1);
            return;
        }
        else {
            continue;
        }


    }
}
void Solution::solveSudoku(vector<vector<char>>& board) {
    if (board.size() == 0) {

    }
    else {
        backtracking(board, 0);
        board = box;
    }
}
#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    const int width = 9;
    vector<vector<char>> box;
    bool isVaild(vector<vector<char>>& board, int col, int row, int var);
    void backtracking(vector<vector<char>>& board, int k);
    void solveSudoku(vector<vector<char>>& board);
};
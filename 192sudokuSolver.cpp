// https://www.naukri.com/code360/problems/sudoku-solver_699919
#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val){
    for(int i = 0; i < 9; i++){
        // row check
        if(board[row][i] == val)    return false;
        
        // col check
        if(board[i][col] == val)    return false;

        // 3x3 matrix
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)  return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            // cell empty
            if(board[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;
                        bool possibleSolution = solve(board);
                        if(possibleSolution)    return true;
                        else    board[row][col] = 0;    // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;  
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
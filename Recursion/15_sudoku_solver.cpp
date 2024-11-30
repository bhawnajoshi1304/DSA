// https://leetcode.com/problems/sudoku-solver/
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.
/*
5 3 . . 7 . . . . 
6 . . 1 9 5 . . . 
. 9 8 . . . . 6 . 
8 . . . 6 . . . 3 
4 . . 8 . 3 . . 1 
7 . . . 2 . . . 6 
. 6 . . . . 2 8 . 
. . . 4 1 9 . . 5 
. . . . 8 . . 7 9 
*/
#include <bits/stdc++.h>
using namespace std;
    bool isValid(vector<string> & board, int row, int col, char c) {
        for (int i = 0; i < 9; i += 1) {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<string> & board) {
        for (int i = 0; i < board.size(); i += 1) {
            for (int j = 0; j < board[0].size(); j += 1) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c += 1) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<string>& board) { solve(board); }

int main() {
    cout << "Enter sudoku:\n";
    vector<string> board(9,string(9,'.')); 
    for(int i=0;i<9;i+=1)
    for(int j=0;j<9;j+=1)
    cin>>board[i][j];
    solveSudoku(board);
    cout<<"Solved sudoku:\n";
    for(auto i:board){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// https://leetcode.com/problems/n-queens/
// Given n the size of n*n chess board, give all board configuration of placing n queens where none is attacking each other
#include <bits/stdc++.h>
using namespace std;
// bool canPlace(int row,int col,vector<string> &board, int n){
//     // check row, col, diagonal for queen
//     int i=row,j=col;
//     while(i>=0 && j>=0){
//         if(board[i][j] == 'Q') return false;
//         i-=1;
//         j-=1;
//     }
//     i=row;
//     j=col;
//     while (i < n && j >= 0) {
//         if (board[i][j] == 'Q') return false;
//         i++;
//         j--;
//     }
//     i=row;
//     while(i>=0){
//         if(board[i][col] == 'Q') return false;
//         i-=1;
//     }
//     j=col;
//     while(j>=0){
//         if(board[row][j] == 'Q') return false;
//         j-=1;
//     }
//     return true;
// }
// void nQueens(int n, vector<string> &board, vector<vector<string>> &ans, int col=0){
//     if(col == n){
//         ans.push_back(board);
//         return;
//     }
//     for(int row=0;row<n;row+=1){
//         if(canPlace(row,col,board,n)){
//             board[row][col]='Q';
//             nQueens(n,board,ans,col+1);
//             board[row][col]='.';   
//         }
//     }
// }
// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> ans;
//     vector<string> s(n,string(n,'.'));
//     nQueens(n,s,ans);
//     return ans;
// }

void nQueens(int n, vector<string>& board, vector<vector<string>>& ans, int col, vector<int>& mp, vector<int>& diagonal1, vector<int>& diagonal2) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row += 1) {
        if (mp[row] == 0 && diagonal1[row + col] == 0 &&
            diagonal2[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            mp[row] = 1;
            diagonal1[row + col] = 1;
            diagonal2[n - 1 + col - row] = 1;
            nQueens(n, board, ans, col + 1, mp, diagonal1, diagonal2);
            board[row][col] = '.';
            mp[row] = 0;
            diagonal1[row + col] = 0;
            diagonal2[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> s(n, string(n, '.'));
    vector<int> row(n), diagonal1(2 * n - 1), diagonal2(2 * n - 1);
    nQueens(n, s, ans, 0, row, diagonal1, diagonal2);
    return ans;
}
int main() {
    cout << "Enter size of chess board: ";
    long long n;
    cin >> n;
    cout << "All possible n queen boards:\n";
    vector<vector<string>> result = solveNQueens(n);
    for (auto i : result) {
        for (auto j : i)
            cout << j << "\n";
        cout << "\n";
    }
    return 0;
}

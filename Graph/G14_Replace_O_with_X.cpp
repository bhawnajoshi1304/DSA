// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Examples:

// Input: mat =
// [['X', 'X', 'X', 'X'],
// ['X', 'O', 'X', 'X'],
// ['X', 'O', 'O', 'X'],
// ['X', 'O', 'X', 'X'],
// ['X', 'X', 'O', 'O']]
// Output:
// [['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'X', 'X'],
// ['X', 'X', 'O', 'O']]

#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}
void DFS(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    visited[i][j] = true;
    int n = grid.size(), m = grid[0].size();
    int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
    for (int x = 0; x < 4; x += 1)
    {
        if (isValid(i + dx[x], j + dy[x], n, m) && !visited[i + dx[x]][j + dy[x]] && grid[i + dx[x]][j + dy[x]] == 'O')
            DFS(i + dx[x], j + dy[x], visited, grid);
    }
}
vector<vector<char>> fill(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i += 1) {
        if (!visited[i][0] && grid[i][0] == 'O')
            DFS(i, 0, visited, grid);
        if (!visited[i][m - 1] && grid[i][m - 1] == 'O')
            DFS(i, m - 1, visited, grid);
    }
    for (int i = 0; i < m; i += 1) {
        if (!visited[0][i] && grid[0][i] == 'O')
            DFS(0, i, visited, grid);
        if (!visited[n - 1][i] && grid[n - 1][i] == 'O')
            DFS(n - 1, i, visited, grid);
    }
    int ans = 0;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (!visited[i][j] && grid[i][j] == 'O')
                grid[i][j] = 'X';
        }
    }
    return grid;
}
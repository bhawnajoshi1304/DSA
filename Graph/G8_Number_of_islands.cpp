// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands. An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1

// Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
// Output: 2

// Connected components when input is matrix with possible directions given

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
    if (x >= 0 && y >= 0 && x < n && y < m)
        return true;
    return false;
}
void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m) {
    visited[i][j] = true;
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    for (int x = 0; x < 8; x += 1) {
        if (isValid(i + dx[x], j + dy[x], n, m) && (grid[i + dx[x]][j + dy[x]] == '1') && !visited[i + dx[x]][j + dy[x]])
            dfs(i + dx[x], j + dy[x], visited, grid, n, m);
    }
}
int numIslands(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if ((grid[i][j] == '1') && !visited[i][j]) {
                ans += 1;
                dfs(i, j, visited, grid, n, m);
            }
        }
    }
    return ans;
}
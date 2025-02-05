// https://www.geeksforgeeks.org/problems/number-of-enclaves/1
// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:

// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}
void DFS(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
    visited[i][j] = true;
    int n = grid.size(), m = grid[0].size();
    int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
    for (int x = 0; x < 4; x += 1) {
        if (isValid(i + dx[x], j + dy[x], n, m) && !visited[i + dx[x]][j + dy[x]] && grid[i + dx[x]][j + dy[x]])
            DFS(i + dx[x], j + dy[x], visited, grid);
    }
}
int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i += 1) {
        if (!visited[i][0] && grid[i][0])
            DFS(i, 0, visited, grid);
        if (!visited[i][m - 1] && grid[i][m - 1])
            DFS(i, m - 1, visited, grid);
    }
    for (int i = 0; i < m; i += 1) {
        if (!visited[0][i] && grid[0][i])
            DFS(0, i, visited, grid);
        if (!visited[n - 1][i] && grid[n - 1][i])
            DFS(n - 1, i, visited, grid);
    }
    int ans = 0;
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < m; j += 1)
            if (!visited[i][j] && grid[i][j])
                ans += 1;
    return ans;
}
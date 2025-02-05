// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Input:
// grid[][] = {{1, 1, 0, 0, 0},
//             {1, 1, 0, 0, 0},
//             {0, 0, 0, 1, 1},
//             {0, 0, 0, 1, 1}}
// Output:
// 1


#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& v, int pi, int pj) {
    visited[i][j] = true;
    v.push_back({i - pi, j - pj}); 
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    for (int x = 0; x < 4; x++) {
        int ni = i + dx[x];
        int nj = j + dy[x];
        if (isValid(ni, nj, grid.size(), grid[0].size()) && !visited[ni][nj] && grid[ni][nj] == 1) {
            DFS(ni, nj, grid, visited, v, pi, pj);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                vector<pair<int, int>> v;
                DFS(i, j, grid, visited, v, i, j); 
                s.insert(v); 
            }
        }
    }
    return s.size();
}
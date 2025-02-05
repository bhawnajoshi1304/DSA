// https://www.geeksforgeeks.org/problems/number-of-provinces/1
// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces. A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// Input:
// [
//  [1, 0, 1],
//  [0, 1, 0],
//  [1, 0, 1]
// ]

// Output:
// 2

// Connected components when given adjacency matrix
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited, vector<vector<int>> &isConnected, int x) {
    for (int i = 0; i < isConnected[x].size(); i++) {
        if (isConnected[x][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(visited, isConnected, i);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    int ans = 0, n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(visited, adj, i);
            ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
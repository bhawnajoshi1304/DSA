// https://neetcode.io/problems/count-connected-components
// There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph. The nodes are numbered from 0 to n - 1. Return the total number of connected components in that graph.

// Input:
// n=3
// edges=[[0,1], [0,2]]

// Output:
// 1

#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &visited, vector<vector<int>> &g){
    visited[node] = true;
    for(auto it: g[node]){
        if(!visited[it]){
            DFS(it,visited,g);
        }
    }
}
int countComponents(int n, vector<vector<int>>& edges) {
    int ans=0;
    vector<vector<int>> adj(n);
    for(auto i: edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            ans+=1;
            DFS(i,visited,adj);
        }
    }
    return ans;
}
// Strongly connected components are sub graph from which all nodes can be visited from each node.
// 1. Sort all nodes in terms of finishing time -- Topological sort (DFS using stack)
// 2. Transpose the graph(reverse the edges)
// 3. DFS according to finishing time stack of topological sort

// 1 -> 2 -> 4
// <   /     |
//  \ <      v
//   3       5
// Strongly connected components:
// 1 2 3
// 4
// 5
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> Graph(long long n,long long m){
    vector<vector<long long>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    return adj;
}
void printGraph(vector<vector<long long>> &G){
    cout<<"Adjacency list representation of graph:\n";
    for(long long i=1;i<G.size();i++){
        cout<<i<<"->";
        for(long long j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void dfs(long long node, vector<vector<long long>> &g, vector<bool> &visited, stack<long long> &s) {
    visited[node] = true;
    for (auto it : g[node])
        if (!visited[it])
            dfs(it, g, visited, s);
    s.push(node);
}
void dfsReversed(long long node, vector<vector<long long>> &g, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (auto it : g[node])
        if (!visited[it])
            dfsReversed(it, g, visited);
}
void printStronglyConnectedComponents(vector<vector<long long>> &g) {
    vector<bool> visited(g.size(), false);
    stack<long long> s;
    for (int it = 1; it < g.size(); it += 1)
        if (!visited[it])
            dfs(it, g, visited, s);
    vector<vector<long long>> reversed(g.size());
    for (long long it = 1; it < g.size(); it += 1) {
        visited[it] = false;
        for (auto j : g[it])
            reversed[j].push_back(it);
    }
    while (!s.empty()) {
        if (!visited[s.top()]) {
            dfsReversed(s.top(), reversed, visited);
            cout << "\n";
        }
        s.pop();
    }
}
int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;
    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";
    auto g = Graph(n,m);
    printGraph(g);
    cout<<"Strongly Connected Components in given graph are:\n";
    printStronglyConnectedComponents(g);
    cout<<"\n";
    return 0;
}
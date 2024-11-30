// Cut vertices / Articulation points in a graph are vertices whose removal increases the number of connected components.
// 1 - 2
// |   |
// 4 - 3
// |
// 5 - 6 - 9
//     |   |
//     7 - 8
//         |
//         10
//       /    \
//      11 -- 12

// Cut vertices in the graph are:
// 10 8 6 5 4
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> Graph(long long n,long long m){
    vector<vector<long long>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
void dfs(long long node, long long parent, vector<vector<long long>> &g, vector<bool> &visited, vector<long long> &low, vector<long long> &high, long long timer) {
    visited[node] = true;
    high[node] = low[node] = ++timer;
    int children = 0;
    for (auto it : g[node]) {
        if (it == parent)
            continue;
        if (visited[it]) {
            low[node] = min(low[node], high[it]);
        }
        else {
            dfs(it, node, g, visited, low, high, timer);
            low[node] = min(low[node], low[it]);
            if (low[it] >= high[node] && parent != 0)
                cout << node << " ";
            children += 1;
        }
    }
    if (parent == 0 && children > 1)
        cout << node << " ";
}
void printCutVertices(vector<vector<long long>> &g){
    vector<bool> visited(g.size(), false);
    vector<long long> low(g.size());
    vector<long long> high(g.size());
    long long timer = 0;
    for (long long node = 1; node < g.size(); node += 1) {
        if (!visited[node]) {
            dfs(node, 0, g, visited, low, high, timer);
        }
    }
}
int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;
    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";
    auto g = Graph(n,m);
    printGraph(g);
    cout<<"Cut vertices / Articulation points in given graph are: ";
    printCutVertices(g);
    cout<<"\n";
    return 0;
}
// A graph can be converted into tree with n nodes and n-1 edges where each node is reachable from every other node
// A mimimum spanning tree has minimum cost of edges among all trees that can be formed from a graph.
// Prim's algorithm is a greedy algorithm in which
// we take a node and add it to the MST
// check the minimum edge connecting nodes of MST with non-MST nodes
// Add the minimum edge and node to the MST

#include <bits/stdc++.h>
using namespace std;
//   9   5   8
// 5 - 4 - 3 - 6
// 4\ 1|3\ |1 /7
//    1 -- 2
//      2

// 5  4 3  6
//  \ | | /
//   1 - 2

vector<vector<pair<long long, long long>>> WeightedGraph(long long n, long long m)
{
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}
void printGraph(vector<vector<pair<long long, long long>>> &G)
{
    cout << "Adjacency list representation of graph:\n";
    for (long long i = 1; i < G.size(); i++)
    {
        cout << i << " -> ";
        for (long long j = 0; j < G[i].size(); j++)
        {
            cout << G[i][j].first << " : " << G[i][j].second << " ";
        }
        cout << "\n";
    }
}
void PrimMST(vector<vector<pair<long long, long long>>> &g)
{
    vector<long long> key(g.size(), INT_MAX);
    vector<long long> parent(g.size(), -1);
    vector<bool> mst(g.size(), false);
    key[1] = 0;
    for (long long count = 1; count < g.size(); count += 1)
    {
        long long mi = INT_MAX, u;
        for (long long v = 1; v < g.size(); v += 1)
        {
            if (mst[v] == false && key[v] < mi)
            {
                mi = key[v];
                u = v;
            }
        }
        mst[u] = true;
        for (auto it : g[u])
        {
            long long v = it.first;
            long long wt = it.second;
            if (mst[v] == false && wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
            }
        }
    }
    cout << "Adjacency list representation of MST formed by Prim's Algorithm:\n";
    for (long long i = 2; i < g.size(); i += 1)
    {
        cout << parent[i] << " -> " << i << " : " << key[i] << "\n";
    }
}
int main()
{
    long long n, m;
    cout << "Enter number of nodes and edges in graph: ";
    cin >> n >> m;

    cout << "Enter the edges described as source and destination and weight of edge seperated by space:\n";

    // auto g = directedGraph(n, m);
    auto wg = WeightedGraph(n, m);

    printGraph(wg);
    cout << "MST formed according to the Prim's Algorithm is:\n";
    PrimMST(wg);
    return 0;
}
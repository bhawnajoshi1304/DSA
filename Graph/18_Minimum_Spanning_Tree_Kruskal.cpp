// A graph can be converted into tree with n nodes and n-1 edges where each node is reachable from every other node
// A mimimum spanning tree has minimum cost of edges among all trees that can e formed from a graph.
// Kruskal's algorithm is a greedy algorithm which uses disjoint set data structure in which
// we store graph as a collection of edges
// sort the edges take minimum edge into mst component
// add edges in increasing order of weight which do not belong to the mst component
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
struct node
{
    long long u;
    long long v;
    long long wt;
    node(long long a, long long b, long long c)
    {
        u = a;
        v = b;
        wt = c;
    }
};
bool comp(node a, node b)
{
    return a.wt < b.wt;
}
long long findPar(long long u, vector<long long> &parent)
{
    if (u == parent[u])
        return u;
    return findPar(parent[u], parent);
}
void Union(long long u, long long v, vector<long long> &parent, vector<long long> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u] += 1;
    }
}

vector<node> WeightedEdgeGraph(long long n, long long m)
{
    vector<node> edges;
    for (long long i = 0; i < m; i += 1)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    return edges;
}
void printGraph(vector<node> &G)
{
    cout << "Representation of graph:\n";
    for (long long i = 1; i < G.size(); i++)
    {
        cout << G[i].u << " -> " << G[i].v << " : " << G[i].wt << "\n";
    }
}
void KruskalMST(vector<node> &g, long long n)
{
    sort(g.begin(), g.end(), comp);
    vector<long long> parent(n + 1), rank(n + 1, 0);
    for (long long i = 1; i <= n; i += 1)
    {
        parent[i] = i;
    }
    long long cost = 0;
    vector<pair<pair<long long, long long>, long long>> mst;
    for (auto it : g)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({{it.u, it.v}, it.wt});
            Union(it.u, it.v, parent, rank);
        }
    }
    cout << "Cost of MST formed is: " << cost << "\n";
    cout << "Adjacency list representation of MST formed by Kruskal's Algorithm:\n";
    for (auto it : mst)
    {
        cout << it.first.first << " -> " << it.first.second << " : " << it.second << "\n";
    }
}
int main()
{
    long long n, m;
    cout << "Enter number of nodes and edges in graph: ";
    cin >> n >> m;

    cout << "Enter the edges described as source and destination and weight of edge seperated by space:\n";

    // auto g = directedGraph(n, m);
    auto wg = WeightedEdgeGraph(n, m);

    printGraph(wg);
    cout << "MST formed according to the Kruskal's Algorithm is:\n";
    KruskalMST(wg, n);
    return 0;
}
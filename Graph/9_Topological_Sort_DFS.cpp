// Topological sort is linear ordering of vertices such that if a edge exist from u to v then u appears before v in the ordering.
// 5->6<-4
// |     |
// v     v
// 2->3->1

// 5 4 6 2 3 1

// Topological ordering exists only for DAG(Directed Acyclic Graph) as for a unordered or a graph with cycle, no ordering is possible

// Using DFS

#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> directedGraph(long long n, long long m)
{
    vector<vector<long long>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    return adj;
}
void printGraph(vector<vector<long long>> &G)
{
    cout << "Adjacency list representation of graph:\n";
    for (long long i = 1; i < G.size(); i++)
    {
        cout << i << "->";
        for (long long j = 0; j < G[i].size(); j++)
        {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
}

void findTopologicalSort(long long node, vector<bool> &visited, stack<long long> &s, vector<vector<long long>> &adj)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            findTopologicalSort(it, visited, s, adj);
        }
    }
    s.push(node);
}
void topologicalSort(vector<vector<long long>> &adj)
{
    stack<long long> s;
    vector<bool> visited(adj.size(), false);
    for (long long i = 1; i < adj.size(); i += 1)
    {
        if (!visited[i])
        {
            findTopologicalSort(i, visited, s, adj);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    long long n, m;
    cout << "Enter number of nodes and edges in graph: ";
    cin >> n >> m;

    cout << "Enter the edges described as source and destination nodes seperated by space:\n";

    auto g = directedGraph(n, m);
    // auto wg = WeightedGraph(n,m);

    printGraph(g);
    cout << "The topological ordering of the graph using DFS is: ";
    topologicalSort(g);
    cout << "\n";

    return 0;
}
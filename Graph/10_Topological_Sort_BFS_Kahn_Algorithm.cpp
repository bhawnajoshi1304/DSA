// Topological sort is linear ordering of vertices such that if a edge exist from u to v then u appears before v in the ordering.
// 5->6<-4
// |     |
// v     v
// 2->3->1

// 4 5 6 2 3 1

// Topological ordering exists only for DAG(Directed Acyclic Graph) as for a unordered or a graph with cycle, no ordering is possible

// Using BFS or the Kahn's Algorithm
// nodes in increasing order of indegree can give hint of ordering, to arrange properly we make use of BFS
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
void topologicalSort(vector<vector<long long>> &adj)
{
    queue<long long> q;
    vector<long long> indegree(adj.size(), 0);
    for (long long i = 1; i < adj.size(); i += 1)
    {
        for (auto it : adj[i])
        {
            indegree[it] += 1;
        }
    }
    for (long long i = 1; i < adj.size(); i += 1)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            indegree[it] -= 1;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    cout << "\n";
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
    cout << "The topological ordering of the graph using BFS Kahn's Algorithm is: ";
    topologicalSort(g);
    cout << "\n";

    return 0;
}
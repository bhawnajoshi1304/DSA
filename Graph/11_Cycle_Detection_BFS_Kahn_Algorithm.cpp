#include <bits/stdc++.h>
using namespace std;

// We make use of Kahn's algorithm used for finding Topological ordering of graph to check if there is a cycle in a graph.
// Topological ordering occurs for DAG only, so if no ordering is possible then graph has a cycle.
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
bool isCyclic(vector<vector<long long>> &g)
{
    queue<long long> q;
    vector<long long> indegree(g.size(), 0);
    for (long long i = 1; i < g.size(); i++)
    {
        for (auto it : g[i])
        {
            indegree[it] += 1;
        }
    }
    for (long long i = 1; i < g.size(); i += 1)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    long long cnt = 0;
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        // Whenever a node from topological ordering is printed increase count
        // cout<<node<<" ";
        cnt += 1;
        for (auto it : g[node])
        {
            indegree[it] -= 1;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    // If the topological ordering contains all the nodes then the graph must be DAG else it has a cycle.
    if (cnt == g.size() - 1)
        return false;
    else
        return true;
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
    cout << "The directed graph has cycle: ";
    cout << isCyclic(g) << "\n";

    return 0;
}
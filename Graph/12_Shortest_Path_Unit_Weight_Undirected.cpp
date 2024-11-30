#include <bits/stdc++.h>
using namespace std;
// We make use of BFS starting from the start node, as all the edge weights are 1, the shortest distance will be the depth from the start node.

// 9 - 1 -- 2 -- 6 - 7
//  \  |        /  \ |
//     3 - 4 - 5     8

vector<vector<long long>> undirectedGraph(long long n, long long m)
{
    vector<vector<long long>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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

void BFS(vector<vector<long long>> &g, long long start)
{
    vector<long long> distance(g.size(), INT_MAX);
    distance[start] = 0;
    queue<long long> q;
    q.push(start);
    while (!q.empty())
    {
        long long node = q.front();
        q.pop();
        for (auto it : g[node])
        {
            if (distance[node] + 1 < distance[it])
            {
                q.push(it);
                distance[it] = distance[node] + 1;
            }
        }
    }
    for (long long i = 1; i < g.size(); i += 1)
    {
        cout << start << "->" << i << ": ";
        if (distance[i] == INT_MAX)
            cout << "NA\n";
        else
            cout << distance[i] << "\n";
    }
}

int main()
{
    long long n, m;
    cout << "Enter number of nodes and edges in graph: ";
    cin >> n >> m;

    cout << "Enter the edges described as source and destination nodes seperated by space:\n";

    auto g = undirectedGraph(n, m);
    // auto wg = WeightedGraph(n,m);

    printGraph(g);
    long long start;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Shortest distances to various nodes of graph from " << start << " are: \n";
    BFS(g, start);
    return 0;
}
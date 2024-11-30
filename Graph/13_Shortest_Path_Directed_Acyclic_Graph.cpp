#include <bits/stdc++.h>
using namespace std;

// To find the shortest distance in a DAG we can make use of Topological ordering using DFS. Through the topological ordering we calculate distances.
// If source comes first then distance will be calculated in right order.
// Otherwise the nodes before source in topological ordering will be unreachable from source, hence can be ignored.

//   2   3   6
// 6---1---2---3
//  \1   2/  1/
//     4-----5
//        4

vector<vector<pair<long long, long long>>> WeightedGraph(long long n, long long m)
{
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});
    }
    return adj;
}
void printGraph(vector<vector<pair<long long, long long>>> &G)
{
    cout << "Adjacency list representation of graph:\n";
    for (long long i = 1; i < G.size(); i++)
    {
        cout << i << "->";
        for (long long j = 0; j < G[i].size(); j++)
        {
            cout << G[i][j].first << "-" << G[i][j].second << " ";
        }
        cout << "\n";
    }
}
void findTopologicalSort(long long node, vector<bool> &visited, stack<long long> &s, vector<vector<pair<long long, long long>>> &g)
{
    visited[node] = true;
    for (auto it : g[node])
    {
        if (!visited[it.first])
        {
            findTopologicalSort(it.first, visited, s, g);
        }
    }
    s.push(node);
}
void shortestPath(vector<vector<pair<long long, long long>>> &g, long long start)
{
    vector<bool> visited(g.size(), false);
    stack<long long> s;
    for (long long i = 1; i < g.size(); i += 1)
    {
        if (!visited[i])
        {
            findTopologicalSort(i, visited, s, g);
        }
    }
    vector<long long> distance(g.size(), INT_MAX);
    distance[start] = 0;
    while (!s.empty())
    {
        long long node = s.top();
        s.pop();
        if (distance[node] != INT_MAX)
        {
            for (auto it : g[node])
            {
                if (distance[node] + it.second < distance[it.first])
                {
                    distance[it.first] = distance[node] + it.second;
                }
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

    cout << "Enter the edges described as source and destination and weight of edge seperated by space:\n";

    // auto g = directedGraph(n, m);
    auto wg = WeightedGraph(n, m);

    printGraph(wg);
    long long start;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Shortest distances to various nodes of graph from " << start << " are: \n";
    shortestPath(wg, start);
    return 0;
}
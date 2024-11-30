#include <bits/stdc++.h>
using namespace std;

//      2     5
// 1 ----- 2 -- 5
//  \1     \4  /1
//     4 --- 3
//        3

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
        cout << i << "->";
        for (long long j = 0; j < G[i].size(); j++)
        {
            cout << G[i][j].first << "-" << G[i][j].second << " ";
        }
        cout << "\n";
    }
}

void shortestPath(vector<vector<pair<long long, long long>>> &g, long long source)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<long long> distance(g.size(), INT_MAX);
    distance[source] = 0;
    pq.push({0, source}); //distance, previous
    while (!pq.empty())
    {
        long long dist = pq.top().first;
        long long prev = pq.top().second;
        pq.pop();
        for (auto it : g[prev])
        {
            long long next = it.first;
            long long nextDistance = it.second;
            if (distance[next] > distance[prev] + nextDistance)
            {
                distance[next] = distance[prev] + nextDistance;
                pq.push({distance[next], next});
            }
        }
    }
    for (long long i = 1; i < g.size(); i += 1)
    {
        cout << source << "->" << i << ": ";
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
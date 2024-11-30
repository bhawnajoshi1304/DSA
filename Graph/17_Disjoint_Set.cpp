#include <bits/stdc++.h>
using namespace std;
// used in kruskal algorithm for MST
// Tell if two node belong to same component
// Union(a,b) combines a and b into one component,
// example :Union(3,4) for 1 -> 2 -> 3    4 changes to
// 1->2->3->4
// parent of component with smaller Rank is changed to that of higher Rank.
// Increase Rank of component which becomes parent when components of same Rank are mixed.
// path compression directly connects a node with its ultimate parent
// example : 1 -> 2 -> 3 -> 4 changes to
//   1 -> 2
//  / \
// 3   4

int parent[100000];
int Rank[100000];
void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}
int findParent(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}
void Union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (Rank[u] < Rank[v])
    {
        parent[u] = v;
    }
    else if (Rank[v] < Rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        Rank[u] += 1;
    }
}
int main()
{
    makeSet(5);
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    // if 2 and 3 belong to same component or not
    if (findParent(2) != findParent(3))
    {
        cout << "Different Component";
    }
    else
    {
        cout << "Same Component";
    }
    return 0;
}
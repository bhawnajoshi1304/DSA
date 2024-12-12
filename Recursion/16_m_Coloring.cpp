// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// Given a graph with v vertices and undirected edges and m colors, is it possible to color all vertices such that no adjacent vertices have same color.
/*
4
5
0 1
1 2
2 3
3 0
0 2
3
 */
#include <bits/stdc++.h>
using namespace std;

bool canColor(long long ind, long long i, vector<vector<long long>>& graph, vector<long long> &color){
    for(auto x: graph[ind]){
        if(color[x] == i) return false;
    }
    return true;
}
bool colorGraph(long long v, vector<vector<long long>>& graph, long long m, vector<long long> &color, long long ind){
    if(ind == v) return true;
    for(long long i=1;i<=m;i+=1){
        if(canColor(ind,i,graph,color)){
            color[ind]=i;
            if(colorGraph(v,graph,m,color,ind+1)) return true;
            color[ind] = -1;
        }
    }
    return false;
}
bool graphColoring(long long v, vector<pair<long long, long long>>& edges, long long m) {
    vector<vector<long long>> graph(v);
    vector<long long> color(v,-1);
    for(auto i: edges){
        graph[i.first].push_back(i.second);
        graph[i.second].push_back(i.first);
    }
    return colorGraph(v, graph, m,color,0);
}
int main() {
    long long v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    long long n;
    cin>>n;
    vector<pair<long long, long long>> edges(n);
    for(long long i=0;i<n;i+=1){
        cin>> edges[i].first>>edges[i].second;
    }
    long long m;
    cout<<"Enter number of colors: ";
    cin>>m;
    cout<<"Is m coloring possible: "<<graphColoring(v,edges,m);
    return 0;
}
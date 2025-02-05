// Adjacency matrix representation maps nodes to vector of adjacent nodes.
// Enter number of nodes and edges in graph: 5 3
// Enter the edges described as source and destination nodes seperated by space:
// 1 3
// 2 4
// 4 3
// Adjacency list representation of graph:
// 1->3 
// 2->4 
// 3->1 4 
// 4->2 3 
// 5->

// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> Graph(long long n,long long m){
    vector<vector<long long>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
vector<vector<pair<long long,long long>>> WeightedGraph(long long n,long long m){
    vector<vector<pair<long long,long long>>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    return adj;
}
void printGraph(vector<vector<long long>> &G){
    cout<<"Adjacency list representation of graph:\n";
    for(long long i=1;i<G.size();i++){
        cout<<i<<"->";
        for(long long j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;

    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";

    auto g = Graph(n,m);
    // auto wg = WeightedGraph(n,m);
    
    printGraph(g);
    
    return 0;
}
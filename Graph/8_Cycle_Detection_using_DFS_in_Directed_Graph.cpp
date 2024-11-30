#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> directedGraph(long long n,long long m){
    vector<vector<long long>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
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

bool DFS(long long node,vector<vector<long long>> &g, vector<bool> &visited,  vector<bool> &visitedDFS){
    visited[node] = true;
    visitedDFS[node] = true;
    for(auto it: g[node]){
        if(!visited[it]){
            if(DFS(it,g,visited,visitedDFS)){
                return true;
            }
        }else if(visitedDFS[it]){
            return true;
        }
    }
    visitedDFS[node] = false;
    return false;
}

bool isCyclic(vector<vector<long long>> &g){
    vector<bool> visited(g.size(),false), visitedDFS(g.size(),false);
    for(long long i=1;i<g.size();i++){
        if(!visited[i]){
            if(DFS(i,g,visited,visitedDFS)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;
    
    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";

    auto g = directedGraph(n,m);
    // auto wg = WeightedGraph(n,m);
    
    printGraph(g);
    cout<<"The directed graph has cycle: ";
    cout<<isCyclic(g)<<"\n";
    
    return 0;
}
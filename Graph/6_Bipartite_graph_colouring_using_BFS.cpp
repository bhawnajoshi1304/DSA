// Bipartite graph is a graph that can be divided into two partitions such that no nodes in same partition are connected 
// Try bfs and assign color while travelling, if colored check if matching else assign opposite to current
// Check for odd size cycles
// https://www.geeksforgeeks.org/problems/bipartite-graph/1
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

bool bipartiteCheck(vector<vector<long long>> &g){
    vector<long long> color(g.size(),-1);
    for(int i=1;i<g.size();i++){
        if(color[i]==-1){
            queue<long long> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                long long node=q.front();
                q.pop();
                for(auto it:g[node]){
                    if(color[it]==-1){
                        q.push(it);
                        color[it]=1-color[node];
                    }else if(color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void print(vector<long long> v){
    for(long long i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;

    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";

    auto g = Graph(n,m);
    // auto wg = WeightedGraph(n,m);
    
    printGraph(g);
    cout<<"Check wheather graph is bipartite using BFS: "<<bipartiteCheck(g)<<"\n";
    
    return 0;
}
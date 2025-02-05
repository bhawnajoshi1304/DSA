// Using dfs we can check for a cycle by checking if a node is already visited and is not the parent of the node.
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
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

bool hasCycle(vector<vector<long long>> &g){
    vector<bool> visited(g.size(),false);
    for(int i=1;i<g.size();i++){
        if(!visited[i]){
            stack<pair<long long,long long>> s;
            s.push({i,-1});
            while(!s.empty()){
                long long node = s.top().first;
                long long par = s.top().second;
                s.pop();
                if(!visited[node]){
                    visited[node]=true;
                    for(auto it:g[node]){
                        if(!visited[it]){
                            s.push({it,node});
                        }else if(it!=par)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

// bool DFS(int i,vector<vector<int>>& adj, vector<bool> &visited,int parent){
//     visited[i]=true;
//     for(auto x:adj[i]){
//         if(!visited[x]){
//             if(DFS(x,adj,visited,i)) return true;
//         }else{
//             if(x!=parent) return true;
//         }
//     }
//     return false;
// }
// bool isCycle(vector<vector<int>>& adj) {
//     int n=adj.size();
//     vector<bool> visited(n,false);
//     for(int i=0;i<n;i+=1){
//         if(!visited[i]){
//             if(DFS(i,adj,visited,-1)) return true;
//         }
//     }
//     return false;
// }
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
    cout<<"Check if graph has cycle using DFS: ";
    cout<<hasCycle(g)<<"\n";
    
    return 0;
}
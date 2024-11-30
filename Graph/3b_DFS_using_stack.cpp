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

vector<long long> dfs(vector<vector<long long>> &g){
    vector<long long> dfs;
    vector<bool> visited(g.size(),false);
    for(int i=1;i<g.size();i++){
        if(!visited[i]){
            stack<long long> s;
            s.push(i);
            while(!s.empty()){
                long long node = s.top();
                s.pop();
                if(!visited[node]){
                    visited[node]=true;
                    dfs.push_back(node);
                    for(auto it:g[node]){
                        if(!visited[it]){
                            s.push(it);
                        }
                    }
                }
            }
        }
    }
    return dfs;
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
    cout<<"DFS of graph is: ";
    print(dfs(g));
    
    return 0;
}
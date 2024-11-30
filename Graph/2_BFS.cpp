// BFS: Bredth First Search 
// It makes use of queue(FIFO) and all the adjacent elements are visited first which are equal distant from parent.
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

vector<long long> bfs(vector<vector<long long>> &g){
    vector<long long> bfs;
    vector<bool> visited(g.size(),false);
    for(int i=1;i<g.size();i++){
        if(!visited[i]){
            queue<long long> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                long long node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:g[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=true;
                    }
                }
            }
        }
    }
    return bfs;
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
    cout<<"BFS of graph is: ";
    print(bfs(g));
    
    return 0;
}
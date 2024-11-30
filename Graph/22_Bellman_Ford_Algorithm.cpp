// Shortest Path for directed graph can't be found if it contains a negative weight cycle
// Bellman Ford algorithm helps to find shortest path in directed graphs with negative edges but no negative weight cycle.
// Relax each edge n-1 time:
//     if(dist[u] + wt < dist[v])
//          dist[v] = dist[u] + wt
// If after n-1 relaxation if distance array changes that means the graph has a negative weight cycle.

//   5    -2     3
// 6 --> 1 --> 2 --> 4
//      |-3    ^    ^
//      |      |6   /-2
//      v      |   /  
//      5  -->   3
//          1
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long,long long>>> WeightedGraph(long long n,long long m){
    vector<vector<pair<long long,long long>>> adj(n+1);
    for(long long i=0;i<m;i++){
        long long u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    return adj;
}
void printGraph(vector<vector<pair<long long,long long>>> &G){
    cout<<"Adjacency list representation of graph:\n";
    for(long long i=1;i<G.size();i++){
        cout<<i<<"->";
        for(long long j=0;j<G[i].size();j++){
            cout<<"("<<G[i][j].first<<","<<G[i][j].second<<") ";
        }
        cout<<"\n";
    }
}
void BellmanFordAlgorithm(vector<vector<pair<long long,long long>>> &g){
    long long source;
    cout<<"Enter source for finding Shortest Path: ";
    cin>>source;
    long long INF = 10000000;
    vector<long long> distance(g.size(),INF);
    distance[source]=0;
    for(long long i=1;i<g.size()-1;i+=1){
        for(long long node=1;node<g.size();node+=1){
            for(auto it:g[node]){
                if(distance[node]+it.second<distance[it.first]){
                    distance[it.first]=distance[node]+it.second;
                }
            }
        }
    }
    int negativeCycle=false;
    for(long long node=1;node<g.size();node+=1){
        for(auto it:g[node]){
            if(distance[node]+it.second<distance[it.first]){
                negativeCycle=true;
                break;
            }
        }
    }
    if(negativeCycle){
        cout<<"The directed graph has a negative weight cycle!\n";
    }else{
        cout<<"Distance of nodes from source "<<source<<" are:\n";
        for(long long i=1;i<g.size();i+=1){
            cout<<i<<" "<<distance[i]<<"\n";
        }
    }
}
int main(){
    long long n,m;
    cout<<"Enter number of nodes and edges in graph: ";
    cin>>n>>m;
    cout<<"Enter the edges described as source and destination nodes seperated by space:\n";
    auto wg = WeightedGraph(n,m);
    printGraph(wg);
    cout<<"Bellman Ford algorithm:\n";
    BellmanFordAlgorithm(wg);
    cout<<"\n";
    return 0;
}
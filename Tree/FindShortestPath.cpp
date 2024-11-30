#include<bits/stdc++.h>
using namespace std;
// given matrix of elements 0 1 and 9 with 0 being unreachable and 9 final point. Find number of moves to reach final point from mat[0][0]
int findShortestPath(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    if(mat[0][0]==0) return -1;
    if(mat[0][0]==9) return 0;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[0][0]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int dist=it.first;
        int i=it.second.first;
        int j=it.second.second;
        if(j+1<m&&!vis[i][j+1] && mat[i][j+1]!=0){
            if(mat[i][j+1]==9) return dist+1;
            vis[i][j+1]=1;
            q.push({dist+1,{i,j+1}});
        }
        if(i+1<n &&!vis[i+1][j] && mat[i+1][j]!=0){
            if(mat[i+1][j]==9) return dist + 1;
            vis[i+1][j]=1;
            q.push({dist+1,{i+1,j}});
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt",'r',stdin);
    freopen("output.txt",'w',stdout);
    #endif
}
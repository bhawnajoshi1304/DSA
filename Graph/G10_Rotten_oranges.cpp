// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
// Given a matrix where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i, j] can rot other fresh orange at indexes [i-1, j], [i+1, j], [i, j-1], [i,j+1] (up, down, left and right) in unit time.

// Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

// Examples:

// Input: mat[][] = 
// [[0, 1, 2], 
// [0, 1, 2], 
// [2, 1, 1]]
// Output: 1


#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m){
    return (x>=0 && y>=0 && x<n && y<m);
}
int orangesRotting(vector<vector<int>>& mat) {
    int ans=0, n=mat.size(), m=mat[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<vector<int>> q;
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if(mat[i][j] == 2){
                visited[i][j] = true;
                q.push({i,j,0});
            }
            if(mat[i][j] == 0)
            visited[i][j] = true;
        }
    }
    while(!q.empty()){
        int x=q.front()[0], y=q.front()[1], d=q.front()[2];
        q.pop();
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        for(int i=0;i<4;i+=1){
            if(isValid(x+dx[i],y+dy[i],n,m) && !visited[x+dx[i]][y+dy[i]]){
                if(mat[x+dx[i]][y+dy[i]] == 1){
                    visited[x+dx[i]][y+dy[i]] = true;
                    q.push({x+dx[i],y+dy[i],d+1});
                }
                if(mat[x+dx[i]][y+dy[i]] == 0)
                visited[x+dx[i]][y+dy[i]] = true;
            }
        }
        ans=max(d,ans);
    }
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1)
            if(mat[i][j] == 1 && !visited[i][j]) return -1;
    return ans;
}
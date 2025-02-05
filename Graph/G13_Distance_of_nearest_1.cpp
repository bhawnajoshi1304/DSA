// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.
// Input: 
// grid = [[0,1,1,0], [1,1,0,0], [0,0,1,1]]
// Output: 
// [[1,0,0,1], [0,0,1,1], [1,1,0,0]]


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> ans(n,vector<int> (m,-1));
    int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i+=1){
        for(int j=0;j<m;j+=1){
            if(grid[i][j]==1){
                    q.push({{i,j}, 0}); 
                    ans[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int row = q.front().first.first; 
        int col = q.front().first.second; 
        int steps = q.front().second; 
        q.pop();
        for(int i = 0;i<4;i++) {
            int nrow = row + dx[i]; 
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && ans[nrow][ncol] == -1) {
                q.push({{nrow, ncol}, steps+1});  
                ans[nrow][ncol]=steps+1;
            }
        }
    }
    return ans;
}
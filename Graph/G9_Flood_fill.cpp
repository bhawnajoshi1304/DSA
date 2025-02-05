// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

#include <bits/stdc++.h>
using namespace std;

    bool isValid(int x, int y, int n, int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    void dfs(int r,int c, int n, int m, vector<vector<int>>& image, vector<vector<bool>> &visited, int oldColor, int newColor){
        image[r][c] = newColor;
        visited[r][c] = true;
        int x[4]={-1,0,0,1};
        int y[4]={0,-1,1,0};
        for(int i=0;i<4;i+=1){
            if(isValid(r+x[i],c+y[i],n,m) && (image[r+x[i]][c+y[i]] == oldColor) && !visited[r+x[i]][c+y[i]]){
                dfs(r+x[i],c+y[i],n,m,image,visited,oldColor,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor=image[sr][sc];
        int n=image.size(),m=image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,visited,oldColor,newColor);
        return image;
    }
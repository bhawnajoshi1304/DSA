// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// A rat can move in a matrix in all 4 directions with value 1, give all path to reach n-1,n-1 from 0,0.
/*
1 1 1 0 1 
1 0 1 1 1 
0 0 1 1 1 
1 0 0 1 1 
1 0 0 0 1 
 */
#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &mat, vector<char> &c,vector<int> &di,vector<int> &dj, vector<string> &ans, int i, int j, string tmp) {
    if((i==mat.size()-1) && (j==mat.size()-1)) {
        ans.push_back(tmp);
        return;
    }
    for(int x=0;x<4;x+=1) {
        if((i+di[x]>=0) && (j+dj[x]>=0) && (i+di[x]<mat.size()) && (j+dj[x]<mat.size()) && (mat[i+di[x]][j+dj[x]]==1)) {
            mat[i+di[x]][j+dj[x]]=0;
            solve(mat,c,di,dj,ans,i+di[x],j+dj[x],tmp+c[x]);
            mat[i+di[x]][j+dj[x]]=1;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat) {
    vector<char> c = {'R','L','D','U'};
    vector<int> di = {0, 0, 1, -1},dj = {1, -1, 0, 0};
    mat[0][0] = 0;
    vector<string> ans;
    solve(mat,c,di,dj,ans,0,0,"");
    return ans;
}
int main() {
    int n;
    cout<<"Enter size of maze: ";
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    cout<<"Enter maze matrix:\n";
    for(int i=0;i<n;i+=1) {
        for(int j=0;j<n;j+=1) {
            cin>>mat[i][j];
        }
    }
    cout<<"All the ways to escape the maze are: ";
    vector<string> ans= findPath(mat);
    for(auto i:ans) {
        cout<<i<<"\n";
    }
    return 0;
}
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
#include <bits/stdc++.h>
using namespace std;

// Recursive solution
// int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid) {
//     if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
//         return INT_MIN;
//     }
//     if (i == n - 1) {
//         return (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
//     }
//     int maxi = INT_MIN, tmp;
//     for (int di = -1; di <= 1; di += 1) {
//         for (int dj = -1; dj <= 1; dj += 1) {
//             tmp = f(i + 1, j1 + di, j2 + dj, n, m, grid) + ((j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]));
//             maxi = max(maxi, tmp);
//         }
//     }
//     return maxi;
// }
// int solve(int n, int m, vector<vector<int>> &grid) {
//     return f(0, 0, m - 1, n, m, grid);
// }

// DP Solution
// int solve(int n, int m, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
//     for (int j1 = 0; j1 < m; j1++) {
//         for (int j2 = 0; j2 < m; j2++) {
//             dp[n - 1][j1][j2] = (j1 == j2) ? grid[n - 1][j1] : (grid[n - 1][j1] + grid[n - 1][j2]);
//         }
//     }
//     for (int i = n - 2; i >= 0; i--) {
//         for (int j1 = 0; j1 < m; j1++) {
//             for (int j2 = 0; j2 < m; j2++) {
//                 int maxi = INT_MIN;
//                 for (int di = -1; di <= 1; di++) {
//                     for (int dj = -1; dj <= 1; dj++) {
//                         int ans = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
//                         if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
//                             ans = INT_MIN;
//                         else
//                             ans += dp[i + 1][j1 + di][j2 + dj];
//                         maxi = max(ans, maxi);
//                     }
//                 }
//                 dp[i][j1][j2] = maxi;
//             }
//         }
//     }
//     return dp[0][0][m - 1];
// }

// space optimized solution
int solve(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> curr(m, vector<int>(m, INT_MIN)), prev(m, vector<int>(m, INT_MIN));
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            prev[j1][j2] = (j1 == j2) ? grid[n - 1][j1] : (grid[n - 1][j1] + grid[n - 1][j2]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                        if (j1 + di >= 0 && j1 + di < m && j2 + dj >= 0 && j2 + dj < m) {
                            ans += prev[j1 + di][j2 + dj];
                        }
                        else {
                            ans = INT_MIN;
                        }
                        maxi = max(maxi, ans);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        swap(curr, prev);
    }
    return prev[0][m-1];
}
  
int main()
{
    long n,m;
    cout << "Enter grid size: ";
    cin >> m >> n;
    vector<vector<int>> mat(m,vector<int>(n,0));
    cout<<"Enter grid values:\n";
    for(int i=0;i<m;i+=1)
        for(int j=0;j<n;j+=1)
            cin>>mat[i][j];
    cout << "Min sum to reach grid[n-1] from grid[0] going down or diagonally left/right: " << solve(m,n,mat) << "\n";
    return 0;
}
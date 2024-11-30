#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/set-matrix-zeroes/description/
void set_matrix_zeroes(vector<vector<ll>> &matrix)
{
    ll first_index = matrix[0][0];
    for (ll i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
            first_index = 0;
        for (ll j = 1; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for (ll i = matrix.size() - 1; i >= 0; i--)
    {
        for (ll j = matrix[0].size() - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (first_index == 0)
            matrix[i][0] = 0;
    }
}
int main()
{
    ll m, n;
    cout << "Enter size of matrix: ";
    cin >> m >> n;
    vector<vector<ll>> matrix(m, vector<ll>(n));
    cout << "Enter matrix elements: \n";
    for (ll i = 0; i < m; i += 1)
    {
        for (ll j = 0; j < n; j += 1)
        {
            cin >> matrix[i][j];
        }
    }
    set_matrix_zeroes(matrix);
    for (ll i = 0; i < m; i += 1)
    {
        for (ll j = 0; j < n; j += 1)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

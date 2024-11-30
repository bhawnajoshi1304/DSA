#include <bits/stdc++.h>
#define ll long long
using namespace std;
void rotate_matrix(vector<vector<ll>> &matrix)
{
    for (ll i = 0; i < matrix.size(); i += 1)
    {
        for (ll j = i + 1; j < matrix.size(); j += 1)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
        for (ll j = 0; j < (matrix.size() + 1) / 2; j += 1)
        {
            swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
        }
    }
}
int main()
{
    ll n;
    cout << "Enter size of matrix: ";
    cin >> n;
    vector<vector<ll>> matrix(n, vector<ll>(n));
    cout << "Enter matrix elements:\n";
    for (ll i = 0; i < n; i += 1)
    {
        for (ll j = 0; j < n; j += 1)
        {
            cin >> matrix[i][j];
        }
    }
    rotate_matrix(matrix);
    for (ll i = 0; i < n; i += 1)
    {
        for (ll j = 0; j < n; j += 1)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
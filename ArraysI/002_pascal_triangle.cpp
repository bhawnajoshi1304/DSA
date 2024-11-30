#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/pascals-triangle/description/
void pascalTriangle(ll n)
{
    vector<vector<ll>> triangle;
    for (ll i = 0; i < n; i += 1)
    {
        vector<ll> row(i + 1, 1);
        for (ll j = 1; j < i; j += 1)
        {
            row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
        triangle.push_back(row);
    }
    for (auto i : triangle)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ll n;
    cout << "Enter size of Pascal's triangle: ";
    cin >> n;
    pascalTriangle(n);
    return 0;
}
// https://www.codechef.com/CENS2020/problems/CENS20A/
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<long long>> v(n + 1, vector<long long>(m + 1, 0));
    for (long long i = 0; i < n; i += 1)
        cin >> s[i];
    long long q;
    cin >> q;
    while (q--)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[x1 - 1][y1 - 1] += 1;
        v[x1 - 1][y2] -= 1;
        v[x2][y2] += 1;
        v[x2][y1 - 1] -= 1;
    }
    for (long long i = 0; i < n; i += 1)
    {
        for (long long j = 1; j < m; j += 1)
        {
            v[i][j] += v[i][j - 1];
        }
    }
    for (long long j = 0; j < m; j += 1)
    {
        for (long long i = 1; i < n; i += 1)
        {
            v[i][j] += v[i - 1][j];
        }
    }
    for (long long i = 0; i < n; i += 1)
    {
        for (long long j = 0; j < m; j += 1)
        {
            if (v[i][j] % 2 == 0)
                cout << s[i][j];
            else
            {
                long long tmp = s[i][j] - '0';
                cout << (tmp ^ 1);
            }
        }
        cout << "\n";
    }
}
int main()
{
    // long long t;
    // cin>>t;
    // while(t-=1){
    solve();
    // }
    return 0;
}
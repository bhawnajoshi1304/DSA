// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n), sum(n + 1, 0);
    for (long long i = 0; i < n; i += 1)
    {
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
    }
    for (long long i = 0; i < q; i += 1)
    {
        long long l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }
}
int main()
{
    // long long t;
    // cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}
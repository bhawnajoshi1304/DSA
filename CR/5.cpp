// https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/problem
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> v(p + 2, 0);
    for (long long i = 0; i < n; i += 1)
    {
        int l, r;
        cin >> l >> r;
        v[max(0, l - r)] += 1;
        v[min(p, l + r) + 1] -= 1;
    }
    long long ans = 0, cnt = 0;

    for (int i = 1; i <= p; i++)
        v[i] += v[i - 1];
    for (int i = 0; i <= p; i++)
    {
        if (v[i] != 1)
            cnt += 1;
        else
            ans = max(ans, cnt), cnt = 0;
    }
    cout << ans << "\n";
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
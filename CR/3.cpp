// https://codeforces.com/problemset/problem/1359/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    // Given b<=c<=a
    if (c <= (b + a) / 2)
        cout << "2\n";
    else
    {
        // There are two possible cases;
        // k hot water cups, k cold water cups c=(a+b)/2
        // k+1 hot water cups, k cold water cups c=(a*(k+1)+b*k)/(2*k+1)
        // c*2*k+c=k*(a+b)+a
        // k*(2*c-a-b)=a-c
        // As k may not be integer we check for floor(k) and ceil(k)
        long long val1 = (a - c) / (2 * c - a - b);
        long long val2 = val1 + 1;
        float v1 = (float)((val1 + 1) * a + val1 * b) / (float)(2 * val1 + 1);
        float v2 = (float)((val2 + 1) * a + val2 * b) / (float)(2 * val2 + 1);
        if (abs(v2 - c) > abs(v1 - c))
            cout << 2 * val1 + 1 << "\n";
        else
            cout << 2 * val2 + 1 << "\n";
    }
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
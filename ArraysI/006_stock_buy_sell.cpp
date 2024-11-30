#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
ll stock_buy_sell(vector<ll> &array)
{
    if (array.size() < 2)
        return 0;
    ll minimum_value = array[0], profit = 0;
    for (ll i = 1; i < array.size(); i += 1)
    {
        if (array[i] < minimum_value)
            minimum_value = array[i];
        profit = max(array[i] - minimum_value, profit);
    }
    return profit;
}
int main()
{
    ll n;
    cout << "Enter array size: ";
    cin >> n;
    vector<ll> array(n);
    cout << "Enter array elements: ";
    for (ll i = 0; i < n; i += 1)
    {
        cin >> array[i];
    }
    cout << "Maximum profit is: " << stock_buy_sell(array);
    return 0;
}
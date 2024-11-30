#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/maximum-subarray/
ll maximum_subarray_sum(vector<ll> &array)
{
    ll sum = array[0], maxSum = array[0];
    for (ll i = 1; i < array.size(); i += 1)
    {
        if (array[i] + sum >= array[i])
        {
            sum += array[i];
        }
        else
        {
            sum = array[i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
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
    cout << "Maximum subarray sum is: " << maximum_subarray_sum(array);
    return 0;
}
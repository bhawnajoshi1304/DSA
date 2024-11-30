// https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.
#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long> &arr, long long n, long long i, long long sum, vector<long long> &ans)
{
    if (i == n)
        ans.push_back(sum);
    else
    {
        solve(arr, n, i + 1, sum + arr[i], ans);
        solve(arr, n, i + 1, sum, ans);
    }
}
vector<long long> subsetSums(vector<long long> &arr, long long n)
{
    vector<long long> ans;
    solve(arr, n, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cout << "Enter size of array: ";
    long long n;
    cin >> n;
    cout << "Enter array elements: ";
    vector<long long> arr(n), l;
    for (long long i = 0; i < n; i += 1)
        cin >> arr[i];
    vector<long long> result = subsetSums(arr, n);
    cout<< "All possible subset sums: \n";
    for (long long i = 0; i < result.size(); i++)
    {
        cout << result[i]<<" ";
    }
    cout << "\n";
    return 0;
}

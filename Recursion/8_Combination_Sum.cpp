// https://leetcode.com/problems/combination-sum/description/
// Unbounded Knapsack
// Each element in array can be used multiple times
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> ans;
vector<long long> l;
vector<vector<long long>> combinationSum(vector<long long> &arr, long long sum, long long i = 0)
{
    if (i >= arr.size())
    {
        long long temp = 0;
        for (auto x : l)
            temp += x;
        if (temp == sum)
            ans.push_back(l);
        return ans;
    }
    long long temp = 0;
    for (auto i : l)
        temp += i;
    if (arr[i] + temp <= sum)
    {
        l.push_back(arr[i]);
        combinationSum(arr, sum, i);
        l.pop_back();
    }
    combinationSum(arr, sum, i + 1);
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
    long long sum;
    cout << "Enter sum of combination: ";
    cin >> sum;
    cout << "All combinationss with sum " << sum << "is:\n";
    vector<vector<long long>> ans = combinationSum(arr, sum);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
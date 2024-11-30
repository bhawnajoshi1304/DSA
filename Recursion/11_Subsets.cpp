// https://leetcode.com/problems/subsets-ii/
// Given an integer array nums that may contain duplicates, return all possible subsets(the power set).
#include <bits/stdc++.h>
using namespace std;
void subsets(vector<long long> &nums, vector<long long> &tmp, vector<vector<long long>> &ans, long long i = 0) {
    ans.push_back(tmp);
    for (long long j = i; j < nums.size(); j += 1) {
        if (j == i || nums[j] != nums[j - 1]) {
            tmp.push_back(nums[j]);
            subsets(nums, tmp, ans, j + 1);
            tmp.pop_back();
        }
    }
}
vector<vector<long long>> subsetsWithDup(vector<long long> &nums) {
    vector<vector<long long>> ans;
    vector<long long> tmp;
    sort(nums.begin(), nums.end());
    subsets(nums, tmp, ans);
    return ans;
}
int main() {
    cout << "Enter size of array: ";
    long long n;
    cin >> n;
    cout << "Enter array elements: ";
    vector<long long> arr(n), l;
    for (long long i = 0; i < n; i += 1)
        cin >> arr[i];
    cout << "All possible subsets without duplicates:\n";
    vector<vector<long long>> result = subsetsWithDup(arr);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}

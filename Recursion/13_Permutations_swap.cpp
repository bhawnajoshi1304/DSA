// https://leetcode.com/problems/permutations
// Given an array nums of distinct integers, return all the possible permutations
#include <bits/stdc++.h>
using namespace std;
void generatePermutations(vector<long long>& nums, vector<vector<long long>>& ans, long long ind = 0) {
    if (ind == nums.size() - 1)
        ans.push_back(nums);
    for (long long i = ind; i < nums.size(); i += 1) {
        swap(nums[i], nums[ind]);
        generatePermutations(nums, ans, ind+1);
        swap(nums[i], nums[ind]);
    }
}
vector<vector<long long>> permute(vector<long long>& nums) {
    vector<vector<long long>> ans;
    generatePermutations(nums, ans);
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
    cout << "All possible permutationsof array:\n";
    vector<vector<long long>> result = permute(arr);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}

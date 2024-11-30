// https://leetcode.com/problems/permutations
// Given an array nums of distinct integers, return all the possible permutations
#include <bits/stdc++.h>
using namespace std;
void generatePermutations(vector<long long> &nums,vector<long long> &tmp, vector<bool> &flag, vector<vector<long long>> &ans){
    if(tmp.size() == nums.size()) {ans.push_back(tmp);return;}
    for(long long i=0;i<nums.size();i+=1){
        if(!flag[i]){
            tmp.push_back(nums[i]);
            flag[i] = true;
            generatePermutations(nums,tmp,flag,ans);
            tmp.pop_back();
            flag[i]=false;
        }
    }

}
vector<vector<long long>> permute(vector<long long>& nums) {
    vector<vector<long long>> ans;
    vector<long long> tmp;
    vector<bool> flag(nums.size(),false);
    generatePermutations(nums,tmp,flag,ans);
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

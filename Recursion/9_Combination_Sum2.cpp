// https://leetcode.com/problems/combination-sum-ii/
// No duplicate combinations, numbers in array to be used once only
#include<bits/stdc++.h>
using namespace std;
void findCombinations(vector<long long>& arr, long long sum, vector<long long>& l, vector<vector<long long>>& ans, long long i = 0) {
    if (sum == 0) {
        ans.push_back(l);
        return;
    }
    for (long long j = i; j < arr.size(); j += 1) {
        if ((j == i || arr[j] != arr[j - 1]) && sum - arr[j] >= 0) {
            l.push_back(arr[j]);
            findCombinations(arr, sum - arr[j], l, ans, j + 1);
            l.pop_back();
        }
    }
}
vector<vector<long long>> combinationSum2(vector<long long>& arr, long long sum, long long i = 0) {
    sort(arr.begin(), arr.end());
    vector<vector<long long>> ans;
    vector<long long> l;
    findCombinations(arr, sum, l, ans);
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
    long long sum;
    cout << "Enter sum of combinations: ";
    cin >> sum;
    cout << "All combinationss with sum " << sum << " are:\n";
    vector<vector<long long>> ans = combinationSum2(arr, sum);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
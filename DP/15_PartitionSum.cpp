// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;
// bool canPartition(vector<int>& arr) {
//     int sum = 0, n = arr.size();
//     for (long long i = 0; i < n; i++)
//         sum += arr[i];
//     if (sum % 2 == 1)
//         return false;
//     sum /= 2;
//     vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
//     for (long long i = 0; i <= n; i++) {
//         t[i][0] = true;
//     }
//     for (long long i = 1; i <= n; i++) {
//         for (long long j = 1; j <= sum; j++) {
//             if (arr[i - 1] <= j) {
//                 t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
//             } else {
//                 t[i][j] = t[i - 1][j];
//             }
//         }
//     }
//     return t[n][sum];
// }
bool canPartition(vector<int>& arr) {
    int sum = 0, n = arr.size();
    for (long long i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    vector<bool> t(sum + 1, false);
    t[0] = true;
    for (long long i = 1; i <= n; i++) {
        for (long long j = sum; j >= arr[i - 1]; j--) {
            t[j] = t[j - arr[i - 1]] || t[j];
        }
    }
    return t[sum];
}

int main() {
    int n;
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter value of array elements: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1) {
        cin >> arr[i];
    }
    cout << "EqualSumPartition " << " possible: " << canPartition(arr) << "\n";
    return 0;
}
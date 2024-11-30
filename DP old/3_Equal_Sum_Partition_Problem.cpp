// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
// https://leetcode.com/problems/partition-equal-subset-sum/

// Input:
// arr = [1,5,11,5]
// Output:
// Subsets with equal sum partition are possible: 1

// This problem is equivalent to subset sum problem where required sum is half the sum of all elements.
// As sum of both subsets must be equal, so sum of array elements must be even else the answer is always false.

#include <bits/stdc++.h>
using namespace std;

// Top Down DP solution
bool equalSumPartition(vector<long long> arr, long long n)
{
    int sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // Returning false when sum is odd as it can't be split in two equal halves.
    if (sum % 2 == 1)
        return false;

    // The required sum is half of the sum of elements.
    sum /= 2;
    // We initialize the DP mtrix with false and 1st column with value true and others need to be computed.
    // 1st column indicates sum=0 i.e. always true as empty subarray has sum 0.
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
    // Initializing sum=0 i.e. first column as true.
    for (long long i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }
    // Computing the max value of other sum.
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= sum; j++)
        {
            // t[i][j] stores considering first i items if sum j is possible.
            if (arr[i - 1] <= j)
            {
                // when i th element is less than required sum we have choice to include it on our subarray or not.
                // If it is possible in either of the case sum j is possible
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                // when i th item is greater than required sum then it can't be included
                // hence is same as considering i-1 items with sum j
                t[i][j] = t[i - 1][j];
            }
        }
    }
    // We need to considers n items and required sum as sum so we return t[n][sum].
    return t[n][sum];
}

int main()
{
    char choice = 'y';
    cout << "Number of elements in array: 4\n";
    cout << "Array elements: 1 5 11 5\n";
    cout << "Subsets with equal sum partition are possible: " << equalSumPartition({1, 5, 11, 5}, 4) << "\n";
    cout << "Enter your choice to continue:(y/n)? ";
    cin >> choice;
    while (choice == 'y')
    {
        long long n;
        cout << "Enter number of elements in array: ";
        cin >> n;
        vector<long long> arr(n);
        cout << "Enter the array elements seperated by space: ";
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Subsets with equal sum partition are possible: " << equalSumPartition(arr, n) << "\n";
        cout << "Enter your choice to continue:(y/n)? ";
        cin >> choice;
    }
    return 0;
}
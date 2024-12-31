// Given an integer array A  of size N.
// You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.
// If there exist a subset then return 1 else return 0.
// https://www.interviewbit.com/problems/subset-sum-problem/
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming

// Input:
// arr = [3, 34, 4, 12, 5, 2]
// sum = 9

// Output:
// Subset sum is possible: 1

// This problem is equivalent to 01 Knapsack Problem where sum is the capacity of the knapsack and arr represent the weight array.
// There is no value array and we just need to return true if the sum is possible or not.
// So in this case instead of taking max value in case of excluding or including a element if take or of it.
// For the base case when array is empty then sum>0 are not possible and needs to be initialized with false and sum=0 is always possible with an empty subarray, hence initialized with true.

#include <bits/stdc++.h>
using namespace std;

// Top Down DP solution
bool subsetSum(vector<long long> arr, long long sum, long long n)
{
    // We initialize the DP mtrix with false and 1st column with value true and others need to be computed.
    // 1st column indicates sum=0 i.e. always true as empty subarray has sum 0.
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
    // Initializing sum=0
    t[0][0] = true;
    // Computing the max value of other sum.
    for (long long i = 1; i <= n; i++)
    {
    // Initializing sum=0 i.e. first column as true.
        t[i][0] = true;
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
    cout << "Number of elements in array: 6\n";
    cout << "Required sum: 9\n";
    cout << "Array elements: 3 34 4 12 5 2\n";
    cout << "Subset with required sum is possible: " << subsetSum({3, 34, 4, 12, 5, 2}, 9, 6) << "\n";
    cout << "Enter your choice to continue:(y/n)? ";
    cin >> choice;
    while (choice == 'y')
    {
        long long sum, n;
        cout << "Enter number of elements in array: ";
        cin >> n;
        cout << "Enter required sum: ";
        cin >> sum;
        vector<long long> arr(n);
        cout << "Enter the array elements seperated by space: ";
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Subset with required sum is possible: " << subsetSum(arr, sum, n) << "\n";
        cout << "Enter your choice to continue:(y/n)? ";
        cin >> choice;
    }
    return 0;
}
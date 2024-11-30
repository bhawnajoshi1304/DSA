// Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Input: 
// arr = [2, 3, 5, 6, 8, 10]
// sum = 10

// Output:
// Number of subsets with given target sum: 3

// This problem is modification of subset sum problem, here we need to find the count when given subset sum is possible.
// For the base case when array is empty then sum>0 are not possible and needs to be initialized with 0
// when sum=0 count is always 1 as there is only one empty subarray
// To count the number of subsets instead of taking or we add the cases.

#include <bits/stdc++.h>
using namespace std;

// Top Down DP solution
long long subsetSumCount(vector<long long> arr, long long sum, long long n)
{
    // We initialize the DP mtrix with 0 and 1st column with value 1 and others need to be computed.
    // 1st column indicates sum=0 i.e. always 1 as empty subarray has sum 0.
    vector<vector<long long>> t(n + 1, vector<long long>(sum + 1, 0));
    // Initializing for sum=0 i.e. first column as 1.
    for (long long i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    // Computing the max value of other sum.
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= sum; j++)
        {
            // t[i][j] stores considering first i items number of subsets with sum j.
            if (arr[i - 1] <= j)
            {
                // when i th element is less than required sum we have choice to include it on our subarray or not.
                // We take the sum of counts in both cases
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
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
    cout << "Required sum: 10\n";
    cout << "Array elements: 2 3 5 6 8 10\n";
    cout << "Number of subsets with given target sum: " << subsetSumCount({2, 3, 5, 6, 8, 10}, 10, 6) << "\n";
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
        cout << "Number of subsets with given target sum: " << subsetSumCount(arr, sum, n) << "\n";
        cout << "Enter your choice to continue:(y/n)? ";
        cin >> choice;
    }
    return 0;
}
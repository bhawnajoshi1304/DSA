// Given a set of integers and the difference in sum of its partition. Find number of ways in which such a partition can be formed.

// Input:
// arr = [31,26,33,21,40]
// Partition sum difference: 5
// Output:
// Count of partition sum difference: 1

// This problem is modification of minimum partition sum difference problem.
// In this problem we are given two partitions difference S2 - S1 = c and we have to count number of ways such a difference can be formed.
// It is also analogous to count subset sum modified through subset sum problem.

#include <bits/stdc++.h>
using namespace std;

long long countPartitionSumDifference(vector<long long> arr, long long sum, long long n)
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // We initialize the DP mtrix with false and 1st column with value true and others need to be computed.
    // 1st column indicates sum = 0 i.e. always true as empty subarray has sum 0.
    vector<vector<long long>> t(n + 1, vector<long long>(sum / 2 + 1, false));
    // Initializing sum=0 i.e. first column as true.
    for (long long i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }
    // Computing the max value of other sum.
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= sum / 2; j++)
        {
            // t[i][j] stores considering first i items if sum j is possible.
            if (arr[i - 1] <= j)
            {
                // when i th element is less than required sum we have choice to include it on our subarray or not.
                // If it is possible in either of the case sum j is possible
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
    // We need to considers n items and minimize sum - 2*possible subset sum(<=sum/2)
    // So traversing from sum/2 whichever is possible whill help to find the solution.
    for (long long i = sum / 2; i >= 0; i--)
    {
        if (t[n][i])
        {
            return (sum - (2 * i));
        }
    }
    return -1;
}

int main()
{
    char choice = 'y';
    cout << "Number of elements in array: 5\n";
    cout << "Array elements: 31 26 33 21 40\n";
    cout << "Subsets with equal sum partition are possible: " << minimumPartitionSumDifference({31, 26, 33, 21, 40}, 5) << "\n";
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
        cout << "Subsets with equal sum partition are possible: " << minimumPartitionSumDifference(arr, n) << "\n";
        cout << "Enter your choice to continue:(y/n)? ";
        cin >> choice;
    }
    return 0;
}
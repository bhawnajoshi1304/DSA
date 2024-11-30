// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
// Input:
// wt[]: [1,3,4,5]
// val[]: [1,4,5,7]
// W(capacity): 7

// Output:
// Total value in knapsack: 9

#include <bits/stdc++.h>
using namespace std;

// // Recursive solution
// long long knapsack(vector<long long> wt, vector<long long> val, long long w, long long n)
// {
//     if (n == 0 || w == 0)
//     {
//         // If there are no items or the knapsack capacity is 0 then total value will always be 0.
//         return 0;
//     }
//     else if (wt[n - 1] > w)
//     {
//         // If the weight of a item is greater than the capacity of knapsack then it can't be included in knapsack.
//         return knapsack(wt, val, w, n - 1);
//     }
//     else
//     {
//         // If the weight of item is less than the capacity of knapsack it can be included in knapsack
//         // But to obtain the maximum value in knapsack we need to make a choice to wheather we include it in knapsack or not.

//         // If we want to include a item then value of item needs to be added and capacity needs to be reduced for knapsack and recursively max value for new knapsack is calculated
//         // val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)
//         // If we do not include the item in knapsack then max value of knapsack is calculated excluding that item.
//         // knapsack(wt,val,w,n-1)
//         return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
//     }
// }

// // Memorized Recursive solution
// long long knapsack(vector<long long> wt, vector<long long> val, long long w, long long n, vector<vector<long long>> &t)
// {
//     if (n == 0 || w == 0)
//     {
//         // If there are no items or the knapsack capacity is 0 then total value will always be 0.
//         return 0;
//     }
//     else if (t[n][w] != -1)
//     {
//         // The max value for knapsack considering n items and w capacity is stored so simply return it.
//         return t[n][w];
//     }
//     else if (wt[n - 1] > w)
//     {
//         // If the weight of a item is greater than the capacity of knapsack then it can't be included in knapsack.
//         t[n][w] = knapsack(wt, val, w, n - 1, t);
//         return t[n][w];
//     }
//     else
//     {
//         // If the weight of item is less than the capacity of knapsack it can be included in knapsack
//         // But to obtain the maximum value in knapsack we need to make a choice to wheather we include it in knapsack or not.

//         // If we want to include a item then value of item needs to be added and capacity needs to be reduced for knapsack and recursively max value for new knapsack is calculated
//         // val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,t)
//         // If we do not include the item in knapsack then max value of knapsack is calculated excluding that item.
//         // knapsack(wt,val,w,n-1,t)
//         t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, t), knapsack(wt, val, w, n - 1, t));
//         return t[n][w];
//     }
// }

// Top Down DP solution
long long knapsack(vector<long long> wt, vector<long long> val, long long w, long long n)
{
    // We initialize the DP mtrix with 0 as for 1st row and 1st column value will be 0 and others need to be computed.
    // 1st row indicates n=0 i.e. no items.
    // 1st column indicates w=0 i.e. capacity of knapsack is 0.
    vector<vector<long long>> t(n + 1, vector<long long>(w + 1, 0));
    // Computing the max value of other knapsack.
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= w; j++)
        {
            // t[i][j] stores max value of knapsack considering first i items and capacity j we compute the max value for knapsack.
            if (wt[i - 1] <= j)
            {
                // when weight of i th element is less than capacity of knapsack we have choice to include it or not.
                // max value for this knapsack is maximum of these choices
                // when we include it we add value of i th item and max value for knapsack with cpacity j-wt[i-1]
                // when we exclude it the max value becomes t[i-1][j]
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                // when weight of item is greater than capacity then it can't be included
                // hence is same as considering i-1 items in j capacity knapsack
                t[i][j] = t[i - 1][j];
            }
        }
    }
    // Our knapsack considers n items and w capacity so we return t[n][w].
    for(long long i=0;i<n+1;i++){
        for(long long j=0;j<1+w;j+=1){
            cout<<t[i][j]<<" ";

        }
        cout<<"\n";
    }
    return t[n][w];
}

int main()
{
    char choice = 'y';
    cout << "Number of items: 4\n";
    cout << "Capacity of knapsack: 7\n";
    cout << "Weight of items: 1 3 4 5\n";
    cout << "Value of items: 1 4 5 7\n";
    cout << "Knapsack total value: " << knapsack({1, 3, 4, 5}, {1, 4, 5, 7}, 7, 4) << "\n";
    cout << "Enter your choice to continue:(y/n)? ";
    cin >> choice;
    while (choice == 'y')
    {
        long long capacity, n;
        cout << "Enter number of items: ";
        cin >> n;
        cout << "Enter capacity of knapsack: ";
        cin >> capacity;
        vector<long long> wt(n), val(n);
        cout << "Enter the weights of items seperated by space: ";
        for (long long i = 0; i < n; i++)
            cin >> wt[i];
        cout << "Enter the value of items seperated by space: ";
        for (long long i = 0; i < n; i++)
            cin >> val[i];

        // // Uncomment for call to memorized recursion knapsack function
        // vector<vector<long long>> t(n + 1, vector<long long>(capacity + 1, -1));
        // cout << "Knapsack total value: " << knapsack(wt, val, capacity, n, t) << "\n";

        cout << "Knapsack total value: " << knapsack(wt, val, capacity, n) << "\n";
        cout << "Enter your choice to continue:(y/n)? ";
        cin >> choice;
    }
    return 0;
}
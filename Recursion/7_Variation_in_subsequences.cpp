// Subsequence - follows true order of array
// 1. Print subsequences with sum k
// 2. Print any 1 subsequence with sum k
// 3. Print n subsequences with sum k
#include <bits/stdc++.h>
using namespace std;
void print(vector<long long> &l)
{
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}
void printSubsequences(vector<long long> &arr, long long i, vector<long long> l)
{
    if (i >= arr.size())
    {
        print(l);
        return;
    }
    l.push_back(arr[i]);
    printSubsequences(arr, i + 1, l);
    l.pop_back();
    printSubsequences(arr, i + 1, l);
}

void printSubsequences(vector<long long> &arr, long long i, vector<long long> l, long long sum)
{
    if (i >= arr.size())
    {
        long long temp = 0;
        for (auto i : l)
            temp += i;
        if (temp == sum)
            print(l);
        return;
    }
    long long temp = 0;
    for (auto i : l)
        temp += i;
    if (arr[i] + temp <= sum)
    {
        l.push_back(arr[i]);
        printSubsequences(arr, i + 1, l, sum);
        l.pop_back();
    }
    printSubsequences(arr, i + 1, l, sum);
}
bool printAnySubsequence(vector<long long> &arr, long long i, vector<long long> l, long long sum)
{
    if (i >= arr.size())
    {
        long long temp = 0;
        for (auto i : l)
            temp += i;
        if (temp == sum)
        {
            print(l);
            return true;
        }
        return false;
    }
    long long temp = 0;
    for (auto i : l)
        temp += i;
    if (arr[i] + temp <= sum)
    {
        l.push_back(arr[i]);
        if (printAnySubsequence(arr, i + 1, l, sum))
            return true;
        l.pop_back();
    }
    if (printAnySubsequence(arr, i + 1, l, sum))
        return true;
    return false;
}
long long printNSubsequence(vector<long long> &arr, long long i, vector<long long> l, long long sum, long long n, long long &count)
{
    if (i >= arr.size())
    {
        long long temp = 0;
        for (auto i : l)
            temp += i;
        if (temp == sum)
        {
            print(l);
            count += 1;
        }
        return count;
    }
    long long temp = 0;
    for (auto i : l)
        temp += i;
    if (arr[i] + temp <= sum)
    {
        l.push_back(arr[i]);
        if (printNSubsequence(arr, i + 1, l, sum, n, count) == n)
            return count;
        l.pop_back();
    }
    if (printNSubsequence(arr, i + 1, l, sum, n, count) == n)
        return count;
    return count;
}
int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    cout << "Enter array elements: ";
    vector<long long> arr(n), l;
    for (int i = 0; i < n; i += 1)
        cin >> arr[i];
    cout << "Printing all subsequences:\n";
    printSubsequences(arr, 0, l);
    long long sum;
    cout << "Enter sum of subsequence: ";
    cin >> sum;
    cout << "All subsequences with sum " << sum << "is:\n";
    printSubsequences(arr, 0, l, sum);
    cout << "\n";
    cout << "Any subsequences with sum " << sum << "is:\n";
    printAnySubsequence(arr, 0, l, sum);
    cout << "\n";
    cout << n << " subsequences with sum " << sum << " is:\n";
    long long count = 0;
    printNSubsequence(arr, 0, l, sum, n, count);
    cout << "\n";
    return 0;
}
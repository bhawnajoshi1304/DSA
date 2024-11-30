// Subsequence - follows true order of array
// 1. Print all subsequences
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
    printSubsequences(arr,i+1,l);
    l.pop_back();
    printSubsequences(arr,i+1,l);
    
}
int main()
{
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    cout<<"Enter array elements: ";
    vector<long long> arr(n),l;
    for(int i=0;i<n;i+=1)
    cin>>arr[i];
    print(arr);
    cout<<"Printing all subsequences:\n";
    printSubsequences(arr,0,l);
    return 0;
}
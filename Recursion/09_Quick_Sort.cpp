#include <bits/stdc++.h>
using namespace std;
void print(vector<long long> &l)
{
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}
void quickSort(vector<long long> &l, long long low, long long high)
{
    if (low < high)
    {
        long long mid = low, pivot = l[low];
        for(int i=low+1;i<=high;i+=1){
            if(l[i]<pivot){ 
                l[mid] = l[i];
                l[i] = l[mid+1];
                l[mid+1] = pivot;
                mid+=1;
                }
        }
        quickSort(l, low, mid-1);
        quickSort(l, mid + 1, high);      
    }
}
int main()
{
    cout << "Enter size of array: ";
    long long n;
    cin >> n;
    cout << "Enter array elements: ";
    vector<long long> arr(n);
    for (long long i = 0; i < n; i += 1)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    print(arr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void print(vector<long long> &l)
{
    for (auto i : l)
        cout << i << " ";
    cout << "\n";
}
void mergeOptimized(vector<long long> &l, long long low, long long mid, long long high){
    long long i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (l[i] <= l[j])
            i++;
        else {
            long long value = l[j];
            long long index = j;
            // shift left array
            while (index > i) {
                l[index] = l[index - 1];
                index--;
            }
            l[i] = value;
            i++;
            mid++;
            j++;
        }
    }
}
void merge(vector<long long> &l, long long low, long long mid, long long high){
    vector<long long> arr;
    long long i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (l[i] <= l[j])
            arr.push_back(l[i++]);
        else {
            arr.push_back(l[j++]);
        }
    }
    while (i <= mid) {
        arr.push_back(l[i++]);
    }
    while (j <= high) {
        arr.push_back(l[j++]);
    }
    i=low;
    j=0;
    while (i <= high) {
        l[i] = arr[j];
        i+=1;
        j+=1;
    }
}
void mergeSort(vector<long long> &l, long long low, long long high)
{
    if (low < high)
    {
        long long mid = (low + high) / 2;
        mergeSort(l, low, mid);
        mergeSort(l, mid + 1, high);
        // merge(l,low,mid,high);   
        mergeOptimized(l,low,mid,high);      
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
    mergeSort(arr, 0, n - 1);
    print(arr);
    return 0;
}
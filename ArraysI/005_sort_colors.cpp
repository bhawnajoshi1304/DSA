#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/next-permutation/description/
void sort_colors_counting_sort(vector<ll> &array)
{
    map<ll, ll> count;
    for (auto i : array)
    {
        if (count.find(i) != count.end())
        {
            count[i] += 1;
        }
        else
            count.insert({i, 1});
    }
    ll idx = 0;
    for (auto i : count)
    {
        for (ll c = 0; c < i.second; c += 1)
            array[idx++] = i.first;
    }
}
void sort_colors_dutch_national_flag(vector<ll> &array)
{
    ll ones = -1, twos = array.size(), i = 0;
    while (i < twos)
    {
        if (array[i] == 0)
        {
            ones += 1;
            swap(array[ones], array[i]);
            i += 1;
        }
        else if (array[i] == 2)
        {
            twos -= 1;
            swap(array[twos], array[i]);
        }
        else
        {
            i += 1;
        }
    }
}
int main()
{
    ll n;
    cout << "Enter array size: ";
    cin >> n;
    vector<ll> array(n);
    cout << "Enter array elements: ";
    for (ll i = 0; i < n; i += 1)
    {
        cin >> array[i];
    }
    cout << "Sorted array is: ";
    sort_colors_counting_sort(array);
    for (auto i : array)
        cout << i << " ";
    cout << "\n";
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (ll i = 0; i < n; i += 1)
    {
        cin >> array[i];
    }
    cout << "Sorted array is: ";
    sort_colors_dutch_national_flag(array);
    for (auto i : array)
        cout << i << " ";
    return 0;
}
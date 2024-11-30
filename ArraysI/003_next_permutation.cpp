#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/next-permutation/
void generate_next_permutation(vector<ll> &array)
{
    ll greaterIndex = -1, smallerIndex = -1;
    for (ll i = array.size() - 1; i > 0; i -= 1)
    {
        if (array[i] > array[i - 1])
        {
            greaterIndex = i;
            smallerIndex = i - 1;
            break;
        }
    }
    if (smallerIndex != -1)
    {
        for (ll i = array.size() - 1; i > greaterIndex; i -= 1)
        {
            if (array[smallerIndex] < array[i])
            {
                greaterIndex = i;
                break;
            }
        }
        swap(array[smallerIndex], array[greaterIndex]);
        reverse(array.begin() + smallerIndex + 1, array.end());
    }
    else
        reverse(array.begin(), array.end());
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
    cout << "Next permutation is: ";
    generate_next_permutation(array);
    for (auto i : array)
    {
        cout << i << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/
vector<pair<ll, ll>> merge_overlapping_intervals(vector<pair<ll, ll>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<pair<ll, ll>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    for (ll i = 1; i < intervals.size(); i += 1)
    {
        if (intervals[i].first <= mergedIntervals[mergedIntervals.size() - 1].second)
        {
            if (intervals[i].second > mergedIntervals[mergedIntervals.size() - 1].second)
                mergedIntervals[mergedIntervals.size() - 1].second = intervals[i].second;
        }
        else
        {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    return mergedIntervals;
}
int main()
{
    ll n;
    cout << "Enter number of intervals: ";
    cin >> n;
    cout << "Enter intervals:\n";
    vector<pair<ll, ll>> intervals;
    for (ll i = 0; i < n; i += 1)
    {
        ll a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    vector<pair<ll, ll>> mergedIntervals = merge_overlapping_intervals(intervals);
    cout << "Merged intervals: \n";
    for (auto i : mergedIntervals)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
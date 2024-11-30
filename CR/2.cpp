// https://www.interviewbit.com/problems/allocate-books/
#include <bits/stdc++.h>
using namespace std;
long long studentsNeeded(vector<long long> books, long long mid)
{
    long long sum1 = 0, count = 1;
    for (long long i = 0; i < books.size(); i++)
    {
        sum1 += books[i];
        if (sum1 > mid)
        {
            sum1 = books[i];
            count += 1;
        }
    }
    return count;
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> books(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    long long students;
    cin >> students;
    if (students > books.size())
        cout << "-1\n";
    else
    {
        long long ans = INT_MAX;
        // minimum of maximum pages to be read is the maximum number of pages in any book
        // maximum pages to be read is sum of pages of all books
        long long l = *max_element(books.begin(), books.end());
        long long r = accumulate(books.begin(), books.end(), 0);
        while (l <= r)
        {
            // We decide a fixed number of pages that a student can read.
            // Then we calculate number of students required to read all books according to the pages fixxed
            long long mid = l + (r - l) / 2;
            long long k = studentsNeeded(books, mid);
            // When students required are less than available students we need to reduce the fixed page limit so as to involve more children
            // We reduce the maximum limit and store the current fixed limit as ans.
            if (k <= students)
            {
                r = mid - 1;
                ans = min(ans, mid);
            }
            // When students required for the given fixed limit are more than available students we need to increase our lower limit.
            else if (k > students)
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
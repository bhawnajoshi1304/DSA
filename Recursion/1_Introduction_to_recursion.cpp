// Recursion - when a function calls itself until a specific condition is met.
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void print() // counts till 3
{
    if (cnt == 3)
        return;
    cout << cnt << "\n";
    cnt += 1;
    print();
}
int main()
{
    print();
    return 0;
}
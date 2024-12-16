// https://leetcode.com/problems/climbing-stairs/description/
#include<bits/stdc++.h>
using namespace std;

// ways to climb stairs: climb 1 stair or climb 2 stair.
// ways to be at stair 0: 1 (0 climb)
// ways to be at stair 1: 1 (climb 1 stair from 0)
// ways to be at stair 2: 2 (climb 2 stairs from 0, climb 1 stair from 1)
// ...
// ...
// ways to be at stair n: f(n-1) + f(n-2) (ways to reach from 1 stair back + ways to reach from 2 stairs back)
// Fibonacci solution
int climbStairs(int n) {
        int prev1 = 2, prev2 = 1, curr;
        if(n<3) return n;
        for (int i = 3; i <= n; i += 1) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
// Modification to q: Allowed climbs 1 stair or 3 stair:
// Recurrence relation = f(n-1) + f(n-3)


// WRITING RECURRENCE RELATION
// 1. Try to represent in terms of index
// 2. Do some stuff on indexes
// 3. To count no. of ways => sum of stuff
//    To find best way => min/max of stuff

int main(){
    cout<<climbStairs(3)<<"\n";
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;
    cout<<"Number of ways to climb n stairs by climbin 1 or 2 stairs: "<<climbStairs(n)<<"\n";
    return 0;
}
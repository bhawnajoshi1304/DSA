// Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, ...
// Memorization- Top down
    // Store recursion tree values of subproblem in some map/table
// Tabulation- Bottom up
    // Base case to required problem
#include<iostream>
#include<vector>
using namespace std;
// Recursive function
long Fibonacci(int n){
    if(n==0 || n==1) return n;
    else return Fibonacci(n-1) + Fibonacci(n-2);
}
// Time Complexity: O(2^n)
// Space Complexity: O(1)

// Memorization 
long Fibonacci(int n,vector<int> &dp){
    if (n == 0 || n == 1) return n;
    if (dp[n] != -1) return dp[n];
    else return dp[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}
// Time Complexity: O(n)
// Space Complexity: O(n)

// Tabulation
long Fibonacci(int n){
    if (n == 0 || n == 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i += 1)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
// Time Complexity: O(n)
// Space Complexity: O(n)

// Space Optimized
// Time Complexity: O(n)
// Space Complexity: O(1)
long Fibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for (int i = 2; i <= n; i += 1) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

int main(){
    cout<<Fibonacci(3)<<"\n";
    int n;
    cout<<"Enter n for nth Fibonacci number: ";
    cin>>n;
    vector<int> dp(n+1);
    cout<<"nth Fibonacci number: "<<Fibonacci(n,dp)<<"\n";
    return 0;
}
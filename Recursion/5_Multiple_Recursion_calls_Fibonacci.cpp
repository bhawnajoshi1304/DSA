#include <bits/stdc++.h>
using namespace std;
// Fibonacci
long long Fibonacci(long long n){
    if(n<=1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
void Problem1(){
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<n<<"th Fibonacci number is: ";
    cout<<Fibonacci(n);
}
int main()
{
    Problem1();
    return 0;
}
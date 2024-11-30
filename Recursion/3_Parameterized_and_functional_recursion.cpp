// Sum of first n numbers
#include <bits/stdc++.h>
using namespace std;
void SumParameterisedRecursion(long long n,long long i = 0){
    if(n==0){
        cout<<"Sum calculated by parameterised recursion: "<<i<<"\n";
    }else{
        SumParameterisedRecursion(n-1,i+n);
    }
}
long long SumFunctionalRecursion(long long n){
    if(n == 0){
        return 0;
    }
    return n + SumFunctionalRecursion(n-1);
}
int main()
{
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Sum of numbers 1 to "<<n<<":\n";
    SumParameterisedRecursion(n);
    cout<<"Sum calculated by functional recursion: "<<SumFunctionalRecursion(n)<<"\n";
    return 0;
}
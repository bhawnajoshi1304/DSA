// 1. Print name N times
// 2. Print linearly from 1 to N
// 3. Print from N to 1
// 4. Print 1 to N by backtracking
// 5. Print N to 1 by backtracking

#include <bits/stdc++.h>
using namespace std;
void printNameNTimes(string name,long long n,long long i = 0) {
    if(i<n) {
        cout<<name<<"\n";
        printNameNTimes(name,n,i+1);
    }
    else return;
}
void Problem1()
{
    cout<<"Problem 1\n";
    string name;
    long long n;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Name printed "<<n<<" times:\n";
    printNameNTimes(name,n);
}
void print1toN(long long n,long long i = 1) {
    if(i<=n){
        cout<<i<<" ";
        print1toN(n,i+1);
    }
    else{
        cout<<"\n";
        return;
    }
}
void Problem2()
{
    cout<<"Problem 2\n";
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Numbers printed 1 to "<<n<<" :\n";
    print1toN(n);
}
void printNto1(long long n,long long i = -1) {
    if(i == -1) i = n;
    if(i>0){
        cout<<i<<" ";
        printNto1(n,i-1);
    }
    else{
        cout<<"\n";
        return;
    }
}
void Problem3()
{
    cout<<"Problem 3\n";
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Numbers printed "<<n<<" to 1:\n";
    printNto1(n);
}
void print1toNBacktracking(long long n,long long i = -1) {
    if(i == -1) i = n;
    if(i>0){
        print1toNBacktracking(n,i-1);
        cout<<i<<" ";
    }
    else return;
}
void Problem4()
{
    cout<<"Problem 4\n";
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Numbers printed 1 to "<<n<<" by backtracking:\n";
    print1toNBacktracking(n);
    cout<<"\n";
}
void printNto1Backtracking(long long n,long long i = 1) {
    if(i<=n){
        printNto1Backtracking(n,i+1);
        cout<<i<<" ";
    }
    else return;
}
void Problem5()
{
    cout<<"Problem 5\n";
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    cout<<"Numbers printed "<<n<<" to 1 by backtracking:\n";
    printNto1Backtracking(n);
    cout<<"\n";
}
int main()
{
    Problem1();
    Problem2();
    Problem3();
    Problem4();
    Problem5();
    return 0;
}
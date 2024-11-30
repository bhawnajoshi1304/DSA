// 1. Reverse an array
// 2. Check string for palindrome

#include <bits/stdc++.h>
using namespace std;
// 1. Reverse an array
void reverseArray(vector<long long> &a,long long l,long long r){
    if(l>=r) return;
    swap(a[l],a[r]);
    reverseArray(a,l+1,r-1);
}
void reverseArray(vector<long long> &a,long long i){
    if(i>=a.size()/2) return;
    swap(a[i],a[a.size()-1-i]);
    reverseArray(a,i+1);
}
void Problem1(){
    long long n;
    cout<<"Enter value of N: ";
    cin>>n;
    vector<long long> a(n,0);
    cout<<"Enter array elements seperated by space:\n";
    for(long long i=0;i<n;i+=1)
    cin>>a[i];
    cout<<"Reversed array:\n";
    reverseArray(a,0,a.size()-1);
    for(long long i=0;i<n;i+=1)
    cout<<a[i]<<" ";
    cout<<"\n";
    cout<<"Reversed array:\n";
    reverseArray(a,0);
    for(long long i=0;i<n;i+=1)
    cout<<a[i]<<" ";
    cout<<"\n";
}
// 2. Check string for palindrome
bool palindrome(string s,long long i=0){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-1-i]) return false;
    return palindrome(s,i+1);
}
void Problem2(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<s<<" is palindrome: "<<palindrome(s)<<"\n";
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    Problem1();
    Problem2();
    return 0;
}
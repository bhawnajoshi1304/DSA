// https://codeforces.com/problemset/problem/1354/B 
#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    long long a,b,c,ans=INT_MAX;
    a=b=c=-1;
    for(long long i=0;i<s.size();i+=1){
        if(s[i]=='1')
        a=max(a,i);
        else if(s[i]=='2')
        b=max(b,i);
        else if(s[i]=='3')
        c=max(c,i);
        if(a!=-1 && b!=-1 && c!=-1){
            ans=min(ans,max(abs(a-b),max(abs(b-c),abs(a-c))));
        }
    }
    if(ans==INT_MAX)
    cout<<"0\n";
    else
    cout<<ans+1<<"\n";
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
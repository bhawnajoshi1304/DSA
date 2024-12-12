// https://leetcode.com/problems/palindrome-partitioning/
// Given a string, find all possible partition into palindromic substrings.
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int l, int r) {
    while (l <= r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}
void partitionHelper(int ind, string s, vector<string>& tmp, vector<vector<string>>& ans) {
    if (ind == s.size()) {
        ans.push_back(tmp);
        return;
    }
    for (int i = ind; i < s.size(); ++i) {
        if (isPalindrome(s, ind, i)) {
            tmp.push_back(s.substr(ind, i - ind + 1));
            partitionHelper(i + 1, s, tmp, ans);
            tmp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;
    partitionHelper(0, s, tmp, ans);
    return ans;
}
int main() {
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    vector<vector<string>> ans = partition(s);
    for(auto i: ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
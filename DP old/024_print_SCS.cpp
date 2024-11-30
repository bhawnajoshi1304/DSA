#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string a, string b) {
    int m = a.size(), n = b.size();
    string s = "";
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int i = m, j = n;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]) {
            s.insert(s.begin(),a[i-1]);
            i-=1;
            j-=1;
        }else if(dp[i-1][j]>=dp[i][j-1]){
            i-=1;
        }else{
            j-=1;
        }
    }
    return s;
}
string shortestCommonSupersequence(const string& X, const string& Y) {
    // string lcs = findLCS(X, Y);s
    string scs,lcs;

    int i = 0, j = 0, k = 0;
    while (k < lcs.size()) {
        while (i < X.size() && X[i] != lcs[k]) {
            scs.push_back(X[i++]);
        }
        while (j < Y.size() && Y[j] != lcs[k]) {
            scs.push_back(Y[j++]);
        }
        // Add the LCS character and move in all three strings
        scs.push_back(lcs[k++]);
        i++; j++;
    }

    // Add remaining characters from X and Y
    while (i < X.size()) scs.push_back(X[i++]);
    while (j < Y.size()) scs.push_back(Y[j++]);

    return scs;
}

int main() {
    string X = "abc";
    string Y = "ac";
    cout << "Shortest Common Supersequence: " << shortestCommonSupersequence(X, Y) << endl;
    return 0;
}

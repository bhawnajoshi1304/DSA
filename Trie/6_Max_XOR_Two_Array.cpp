// https://www.naukri.com/code360/problems/maximum-xor_973113
// You are given two arrays of non-negative integers say arr1 and arr2. 
// Your task is to find the maximum value of ( A xor B ) where 
// A and B are any elements from arr1 and arr2 respectively
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];
    bool containsKey(int bit) { return (links[bit] != NULL); }
    void put(int bit, Node *node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
};
class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    void getMax(int num, int &ans) {
        int maxi = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = !(num >> i & 1);
            if (node->containsKey(bit)) {
                maxi |=(1<<i);
                node = node->get(bit);
            }
            else {
                node = node->get(!bit);
            }
        }
        ans = max(ans, maxi);
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        trie.insert(arr1[i]);
    for (int i = 0; i < m; i++) {
        trie.getMax(arr2[i], ans);
    }
    return ans;
}
int main() {
    vector<int> arr1 = {6, 6, 6, 6, 6, 6, 6};
    vector<int> arr2 = {2, 2, 2, 2, 2, 2, 2};

    int n = arr1.size();
    int m = arr2.size();

    cout << "Maximum XOR: " << maxXOR(n, m, arr1, arr2) << endl;

    return 0;
}
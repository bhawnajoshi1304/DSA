// https://www.naukri.com/code360/problems/max-xor-queries_1382020
// You are given an array ARR consisting of N non-negative integers. You are also given a list QUERIES consisting of M queries, where the i-th query is a list/array of two non-negative integers i.e QUERIES[i] = [Xi, Ai].
// The answer to the ith query, is the maximum bitwise xor value of Xi with any integer less than or equal to Ai in ARR.

#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node *links[2]; 
    bool containsKey(int ind) {
        return (links[ind] != NULL); 
    }
    Node* get(int ind) {
        return links[ind]; 
    }
    void put(int ind, Node* node) {
        links[ind] = node; 
    }
}; 
class Trie {
    private: Node* root; 
    public:
        Trie() {
            root = new Node(); 
        }
        void insert(int num) {
            Node* node = root;
            for(int i = 31;i>=0;i--) {
                int bit = (num >> i) & 1; 
                if(!node->containsKey(bit)) {
                    node->put(bit, new Node()); 
                }
                node = node->get(bit); 
            }
        }
        int findMax(int num) {
        Node* node = root; 
        int maxNum = 0; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1<<i); 
                node = node->get(!bit); 
            }
            else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(), 0); 
    vector<pair<int, pair<int,int>>> offlineQueries; 
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); 
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    
    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.findMax(it.second.first); 
        else ans[it.second.second] = -1; 
    }
    return ans; 
}
int main() {
    vector<int> arr = {3, 10, 5, 25, 2, 8};
    vector<vector<int>> queries = {
        {5, 10},
        {25, 5},
        {2, 8},
        {5, 25}
    }; 
    vector<int> result = maxXorQueries(arr, queries);
    for(int res : result) {
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}
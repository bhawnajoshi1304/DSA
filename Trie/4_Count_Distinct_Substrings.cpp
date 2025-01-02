// https://www.naukri.com/code360/problems/count-distinct-substrings_985292
// Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. 
#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<Node*> links;
    Node(){
        links = vector<Node*>(26,nullptr);
    }
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
};
int countDistinctSubstrings(string &s) {
    int ans=0;
    Node *root = new Node();
    for(int i=0;i<s.size();i+=1){
        Node *node = root;
        for(auto j=i;j<s.size();j+=1){
            if(!node->containsKey(s[j])){
                node->put(s[j]);
                ans+=1;
            }
            node=node->get(s[j]);
        }
    }
    return ans+1;
}
int main() {
    string s = "ababa";
    cout << "Number of distinct substrings: " << countDistinctSubstrings(s) << endl;
    return 0;
}

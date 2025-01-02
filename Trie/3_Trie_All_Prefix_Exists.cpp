// https://www.naukri.com/code360/problems/complete-string_2687860
// A string is called a complete string if every prefix of this string is also present in the array A. 
// Find the longest complete string in the array 
// If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".
#include <bits/stdc++.h> 
using namespace std;
struct Node{
    vector<Node*> links;
    int flag;
    Node() {
        links = vector<Node*>(26, nullptr);
        flag=false;
    }
    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;;
    }
};
class Trie{
Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)){
                node->put(i,new Node());
            }
            node = node->get(i);
        }
        node->setEnd();
    }
    bool allPrefixExists(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)) return false;
            node = node->get(i);
            if(node->flag <=0) return false;
        }
        return node->flag >0;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(auto i:a){
        t.insert(i);
    }
    string ans="";
    for(auto i:a){
        if(i.size()>=ans.size())
        if(t.allPrefixExists(i)){
            if(i.size()>ans.size() || (i.size()==ans.size() && i<ans)){
                ans=i;
            }
        }
    }
    if(ans=="") return "None";
    return ans;
}

int main() {
    vector<string> words = {"n", "na", "nan", "nana", "ban", "bana", "banana"};
    int n = words.size();
    string result = completeString(n, words);
    cout << "Longest complete string: " << result << "\n";
    return 0;
}
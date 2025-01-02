// https://www.naukri.com/code360/problems/implement-trie_1387095
//  insert(“WORD”): insert the string “WORD”
// countWordsEqualTo(“WORD”): return how many times this “WORD”
// countWordsStartingWith(“PREFIX”): return how many words are there that have the string “PREFIX” as a prefix.
// erase(“WORD”): delete one occurrence of the string “WORD”
#include <bits/stdc++.h>
using namespace std;
struct Node{
    vector<Node*> links;
    int count;
    int prefixCount;
    Node() {
        links = vector<Node*>(26, nullptr);
        count=0;
        prefixCount=0;
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
    void increaseEnd(){
        count+=1;
    }
    void increasePrefix(){
        prefixCount+=1;
    }
    void decreaseEnd(){
        count-=1;
    }
    void decreasePrefix(){
        prefixCount-=1;
    }
};
class Trie{
Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)){
                node->put(i,new Node());
            }
            node = node->get(i);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)) return 0;
            node = node->get(i);
        }
        return node->count;
    }

    int countWordsStartingWith(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)) return 0;
            node = node->get(i);
        }
        return node->prefixCount;
    }

    void erase(string word){
        Node* node = root;
        for(auto i: word){
            if(!node->containsKey(i)) return;
            node = node->get(i);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};


int main() {
    Trie trie;
    string word1 = "apple";
    trie.insert(word1);
    cout << "Inserted 'apple'" << "\n";
    cout << "Count of 'apple': " << trie.countWordsEqualTo(word1) << "\n";
    cout << "Words starting with 'app': " << trie.countWordsStartingWith("app") << "\n";
    trie.erase(word1);
    cout << "Count of 'apple' after erase: " << trie.countWordsEqualTo(word1) << "\n";
    string emptyString = "";
    cout << "Count of empty string: " << trie.countWordsEqualTo(emptyString) << "\n";
    return 0;
}
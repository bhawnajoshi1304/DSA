// Trie is a data structure that enables efficient string search operations.
// https://www.naukri.com/code360/problems/implement-trie_631356
// nsert(word) - To insert a string "word" 
// search(word) - To check if string "word" is present 
// startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".
#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node *> links; // Vector to store pointers to child nodes
    bool flag = false;    // Flag to mark the end of a word

    Node() {
        links = vector<Node *>(26, nullptr);
    }
    // Constructor to initialize links with 26 nullptrs
};

class Trie {
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for (auto i : word) {
            if (node->links[i - 'a'] == nullptr) {
                node->links[i - 'a'] = new Node();
            }
            node = node->links[i - 'a'];
        }
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for (auto i : word) {
            if (node->links[i - 'a'] == nullptr)
                return false;
            node = node->links[i - 'a'];
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for (auto i : prefix) {
            if (node->links[i - 'a'] == nullptr)
                return false;
            node = node->links[i - 'a'];
        }
        return true;
    }
};
int main() {
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << "\n";   // Output: 1 (true)
    cout << obj->search("app") << "\n";     // Output: 0 (false)
    cout << obj->startsWith("app") << "\n"; // Output: 1 (true)
    obj->insert("app");
    cout << obj->search("app") << "\n"; // Output: 1 (true)
    delete obj;
    return 0;
}

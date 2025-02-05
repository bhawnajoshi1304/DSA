// Binary Search Tree

//            8
//        /        \
//      5           10
//    /   \            \
//   1     7            12

// Three methods to generate BST from preorder traversal:
// 1. n inserts in Binary Tree. Time Complexity: O(n^2)
// 2. sort preorder to form inorder and generate biary tree from it. Time Complexity: O(nlog n)+O(n)
// 3. Insert root and create bound for elements according to BST property and add nodes accordingly. Time Complexity: O(n). 
#include <bits/stdc++.h>
using namespace std;
struct node {
    long long data;
    struct node *left;
    struct node *right;
    node(long long data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void traversal(node *root) {
    stack<pair<node *, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL) return;
    while (!s.empty()) {
        auto it = s.top();
        s.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->left != NULL) {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL) {
                s.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    cout << "Preorder Traversal: ";
    for (auto i : pre)
        cout << i << " ";
    cout << "\n";
    cout << "Inorder Traversal: ";
    for (auto i : in)
        cout << i << " ";
    cout << "\n";
    cout << "Postorder Traversal: ";
    for (auto i : post)
        cout << i << " ";
    cout << "\n";
}
node *build(vector<int> &preorder, int &i, int bound) {
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;
    node *root = new node(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);
    return root;
}
node *bstFromPreorder(vector<int> &preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    traversal(bstFromPreorder(preorder));
    return 0;
}
// Morris Traversal
// It uses threaded binary tree to reduce space complexity in tree traversals.
// Before travelling to left, the right most node of left subtree is made to point to the current node.
// Then left tree is traversed, on reaching the current node it travels to left and finds the threaded link which is broken and tree is traversed to right.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// root left right
// Pre-Order Traversal:  10 5 2 6 15 13 12 14 22
// left root right
// In-Order Traversal:   2 5 6 10 12 13 14 15 22
// left right root
// Post-Order Traversal: 2 6 5 12 14 13 22 15 10

// from a root I can go to left then right but can't return so when I want to go to root again, last traversal of left needs to point to root  
// go to left then rightmost attach the right link to root
// 6->10
// 2->5
// 14->15
// 12->13 

// Time Complexity: O(n)
// Space Complexity: O(n) | O(1)
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
vector<int> inorderTraversal(node *root) {
    vector<int> inorder;
    node *curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            // cout<<curr->data<<" ";
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;
            if (prev->right == NULL) {
                // cout<<prev->data<<"->"<<curr->data<<"\n";
                prev->right = curr;
                curr = curr->left;
            }
            else if (prev->right == curr) {
                prev->right = NULL;
                // cout << curr->data << " ";
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
vector<int> preorderTraversal(node *root) {
    vector<int> preorder;
    node *curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            // cout<<curr->data<<" ";
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = curr;
                // cout << prev->data<<"->"<<curr->data << "\n";
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else if (prev->right == curr) {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
int main() {
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    node *tmp = root->left;
    cout << "Inorder Traversal: ";
    // inorderTraversal(root);
    vector<int> inorder = inorderTraversal(root);
    for (auto i : inorder)
        cout << i << " ";
    cout << "\n";
    cout << "Preorder Traversal: ";
    // preorderTraversal(root);
    vector<int> preorder = preorderTraversal(root);
    for (auto i : preorder)
        cout << i << " ";
    cout << "\n";
    return 0;
}
// Flattening a binary tree means to convert it to linked list with right as the next node
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


// Flattened tree: 10 5 2 6 15 13 12 14 22 
// last element of left subtree points to right element
// root right node becomes left node

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
void flattenTree(node *root) {
    node *curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            node *prev = curr->left;
            while (prev->right)
                prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
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
    flattenTree(root);
    cout << "Flattened tree: ";
    node *temp = root;
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << "\n";
    return 0;
}
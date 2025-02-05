// Lowest Common Ancestor
// It is the root of the smallest subtree from which given both nodes are visible.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// Lowest Common Ancestor of 12 and 22 is: 15

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)
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

node *LeastCommonAncestor(node *root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q)
        return root;
    node *left = LeastCommonAncestor(root->left, p, q);
    node *right = LeastCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    return root;
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
    int p = 12, q = 22;
    cout << "Least Common Ancestor of " << p << " and " << q << " is: " << LeastCommonAncestor(root, p, q)->data << "\n";
    return 0;
}
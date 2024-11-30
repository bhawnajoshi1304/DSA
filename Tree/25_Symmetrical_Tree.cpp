// Symmetric Tree
// If the right and left subtree of root are mirror images of each other.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//             /  \
//            12   14
// Symmetric Tree: false

//            10
//        /        \
//      15          15
//    /   \       /    \
//   22     6    6      22
// Symmetric Tree: true

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long data;
    struct node *left;
    struct node *right;
    node(long long data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

bool check(node *l, node *r){
    if (l == NULL || r == NULL)
        return l == r;
    return (l->data == r->data) && (check(l->left, r->right)) && (check(l->right, r->left));
}
bool Symmetric(node *root){
    if (root == NULL || check(root->left, root->right))
        return true;
    return false;
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    cout << "The tree is symmetric: " << Symmetric(root) << "\n";
    struct node *root1 = new node(10);
    root1->left = new node(15);
    root1->left->left = new node(22);
    root1->left->right = new node(16);
    root1->right = new node(15);
    root1->right->left = new node(16);
    root1->right->right = new node(22);
    cout << "The tree is symmetric: " << Symmetric(root1) << "\n";
    return 0;
}
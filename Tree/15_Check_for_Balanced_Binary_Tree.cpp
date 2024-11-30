// Balanced Binary Tree: Height of tree should be at maximum log(n) where n is number of nodes. Height of left sub tree - height of right sub tree must be smaller than or equal to 1.

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

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

int checkBalancedBinaryTree(node *root)
{
    if (root == NULL)
        return 0;
    int lh = checkBalancedBinaryTree(root->left);
    int rh = checkBalancedBinaryTree(root->right);
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    // Commenting the below line makes the tree unbalanced.
    root->right->right = new node(22);
    cout << "The tree is balanced binary tree: ";
    if (checkBalancedBinaryTree(root) == -1)
        cout << "false\n";
    else
        cout << "true\n";
    return 0;
}
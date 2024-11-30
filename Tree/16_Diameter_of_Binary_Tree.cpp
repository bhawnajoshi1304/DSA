// Diameter: Longest path between two nodes. Path does not need to pass via root. It is sum of height of the left subtree and height of right subtree.

//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14
// Diameter of the given Binary Tree is: 6

// Time Complexity: O(n)
// Space Complexity: O(1)

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

int height(node *root, int &diameter)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameter(node *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
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
    root->right->right = new node(22);
    cout << "Diameter of given Binary Tree: " << diameter(root) << "\n";
    return 0;
}

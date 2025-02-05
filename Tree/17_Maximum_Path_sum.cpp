// Path: Sequence of nodes and edges between two nodes.
// Maximum Path Sum can be calculated for a node as value of node + max path to left node + max path to right node.
// Remember to ignore negative path for left and right nodes.

//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14
// Maximum Path Sum of given Binary Tree: 64
// 14-13-15-22

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int maxPathTo(node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = max(0, maxPathTo(root->left, maxi));
    int rh = max(0, maxPathTo(root->right, maxi));
    maxi = max(maxi, root->data + lh + rh);
    return root->data + max(lh, rh);
}

int maxPathSum(node *root)
{
    int maxi = INT_MIN;
    maxPathTo(root, maxi);
    return maxi;
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
    cout << "Maximum Path Sum of given Binary Tree: " << maxPathSum(root) << "\n";
    return 0;
}

// Complete Binary tree is as filled as possible in the left
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  / \
// 12  14
    
// Count of nodes in complete binary tree is: 9
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

long long findLeftHeight(node *root)
{
    long long height = 0;
    while (root)
    {
        root = root->left;
        height += 1;
    }
    return height;
}
long long findRightHeight(node *root)
{
    long long height = 0;
    while (root)
    {
        root = root->right;
        height += 1;
    }
    return height;
}

long long countNodes(node *root)
{
    if (root == NULL)
        return 0;
    long long lh = findLeftHeight(root);
    long long rh = findRightHeight(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->left->left->left = new node(12);
    root->left->left->right = new node(14);
    root->right->right = new node(22);
    cout << "Count of nodes in complete binary tree is: "<<countNodes(root)<< "\n";
    return 0;
}
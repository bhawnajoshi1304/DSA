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

// Inorder Traversal - left root right

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22 
//  /          /  \
// 1          12   14

// In-Order Traversal:   1 2 5 6 10 12 13 14 15 22

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
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
    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\n";
    return 0;
}

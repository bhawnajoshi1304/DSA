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

// Postorder Traversal - left right root

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Post-Order Traversal: 1 2 6 5 12 14 13 22 15 10

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)

void postOrder(node *root)
{
    if (root == NULL)
        return;
    // Implemented using two stacks
    // Since we need first left tree then right and then root.
    // So in the first stack we insert a root
    // Then pop s1 top and push it in s2 to keep the root at bottom
    // As we want to pop left elements first from S2 we push left first in S1 then right elements so that right elements get pushed first in S2.
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        root = s2.top();
        s2.pop();
        cout << root->data << " ";
    }
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
    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << "\n";
    return 0;
}
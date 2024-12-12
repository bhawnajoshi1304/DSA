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

// Preorder Traversal - root left right

//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Pre-Order Traversal:  10 5 2 1 6 15 13 12 14 22

// Time Complexity: O(n)
// Space Complexity: O(n) | O(log n)

void preOrder(node *root)
{
    // Use stack for traversal first add the root into stack.
    // On removing element from stack add its right element in the stack first then add the left.
    // We add the right first because we want to pop left element first.
    if (root == NULL)
        return;
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->data << " ";
        if (root->right != NULL)
        {
            s.push(root->right);
        }
        if (root->left != NULL)
        {
            s.push(root->left);
        }
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
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << "\n";
    return 0;
}

// Depth: Total number of edges from root to that node + 1. Depth of root node is 1. Depth of tree is number of edges from root to farthest leaf node + 1.

//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14
// Depth of the given tree is: 4

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

// // Recursive method
// int depth(node *root)
// {
//     if (root == NULL)
//         return 0;
//     return 1 + max(depth(root->left), depth(root->right));
// }

// Using level order traversal
int depth(node *root)
{
    if (root == NULL)
        return 0;
    int d = 1;
    queue<pair<node *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        long long size = q.size();
        for (long long i = 0; i < size; i++)
        {
            auto n = q.front();
            d = max(d, n.second);
            q.pop();
            if (n.first->left != NULL)
                q.push({n.first->left, n.second + 1});
            if (n.first->right != NULL)
                q.push({n.first->right, n.second + 1});
        }
    }
    return d;
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
    cout << "Maximum Depth of Binary Tree: " << depth(root) << "\n";
    return 0;
}

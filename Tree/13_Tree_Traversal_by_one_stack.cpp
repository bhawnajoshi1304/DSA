// Different tree traversal are: BFS/DFS.

// There are three types of Depth First Search for trees:
// Inorder Traversal - left root right
// Preorder Traversal - root left right
// Postorder Traversal - left right root

//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Pre-Order Traversal:  10 5 2 1 6 15 13 12 14 22
// In-Order Traversal:   1 2 5 6 10 12 13 14 15 22
// Post-Order Traversal: 1 2 6 5 12 14 13 22 15 10

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

void traversal(node *root)
{
    stack<pair<node *, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
    {
        return;
    }
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        // Part for pre
        // increment 1 to 2
        // push left side of tree
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->left != NULL)
            {
                s.push({it.first->left, 1});
            }
        }
        // part for in
        // increment 2 to 3
        // push right
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL)
            {
                s.push({it.first->right, 1});
            }
        }
        // part for post
        // no need to push back again
        else
        {
            post.push_back(it.first->data);
        }
    }
    cout << "Preorder Traversal: ";
    for (auto i : pre)
        cout << i << " ";
    cout << "\n";
    cout << "Inorder Traversal: ";
    for (auto i : in)
        cout << i << " ";
    cout << "\n";
    cout << "Postorder Traversal: ";
    for (auto i : post)
        cout << i << " ";
    cout << "\n";
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
    traversal(root);
    return 0;
}

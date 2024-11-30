// Two trees are identical if they have same traversal
//           10
//       /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

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

bool identicalTrees(node *a, node *b)
{
    if (a == NULL || b == NULL)
        return a == b;
    return ((a->data == b->data) && (identicalTrees(a->left, b->left)) && (identicalTrees(a->right, b->right)));
}
int main()
{
    struct node *a = new node(10);
    a->left = new node(5);
    a->left->left = new node(2);
    a->left->left->left = new node(1);
    a->left->right = new node(6);
    a->right = new node(15);
    a->right->left = new node(13);
    a->right->left->left = new node(12);
    a->right->left->right = new node(14);
    a->right->right = new node(22);
    struct node *b = new node(10);
    b->left = new node(5);
    b->left->left = new node(2);
    b->left->left->left = new node(1);
    b->left->right = new node(6);
    b->right = new node(15);
    b->right->left = new node(13);
    b->right->left->left = new node(12);
    b->right->left->right = new node(14);
    b->right->right = new node(22);
    cout << "The two trees are identical: " << identicalTrees(a, b) << "\n";
    return 0;
}

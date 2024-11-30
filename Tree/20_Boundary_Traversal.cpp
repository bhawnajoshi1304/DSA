// Boundary traversal
// Take left boundary excluding leaf nodes then leaf nodes and then right boundary in reverse.
// Inorder traversal to get leaf nodes in different level in correct order
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Boundary Traversal: 10 5 2 1 6 12 14 22 15

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

bool isLeaf(node *root)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
        return true;
    return false;
}

// void addLeftBoundary(node *root, vector<long long> &ans)
void addLeftBoundary(node *root)
{
    node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            cout << cur->data << " ";
        // ans.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
// void addLeaves(node *root, vector<long long> &ans)
void addLeaves(node *root)
{
    if (isLeaf(root))
        cout << root->data << " ";
    // ans.push_back(root->data);
    if (root->left)
        addLeaves(root->left);
    // addLeaves(root->left, ans);
    if (root->right)
        addLeaves(root->right);
    // addLeaves(root->right, ans);
}
// void addRightBoundary(node *root, vector<long long> &ans)
void addRightBoundary(node *root)
{
    node *cur = root->right;
    stack<long long> s;
    while (cur)
    {
        if (!isLeaf(cur))
            s.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        // ans.push_back(s.top());
        s.pop();
    }
}
// vector<long long> BoundaryTraversal(node *root)
void BoundaryTraversal(node *root)
{
    // vector<long long> ans;
    if (root == NULL)
        // return ans;
        return;
    if (!isLeaf(root))
        cout << root->data << " ";
    // ans.push_back(root->data);
    addLeftBoundary(root);
    addLeaves(root);
    addRightBoundary(root);
    // addLeftBoundary(root, ans);
    // addLeaves(root, ans);
    // addRightBoundary(root, ans);
    // return ans;
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
    cout << "Boundary Traversal: ";
    BoundaryTraversal(root);
    // vector<long long> ans = BoundaryTraversal(root);
    // for (long long i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << "\n";
    return 0;
}
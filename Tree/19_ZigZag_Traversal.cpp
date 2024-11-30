// Zig Zag traversal is modified level order traversal where we maintain a flag to remember if we need to reverse the order.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Zig-Zag Traversal: 10 15 5 2 6 13 22 14 12 1

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

// vector<vector<long long>> ZigZagTraversal(node *root)
void ZigZagTraversal(node *root)
{
    // vector<vector<long long>> ans;
    if (root == NULL)
        // return ans;
        return;
    queue<node *> q;
    q.push(root);
    bool rightToleft = false;
    while (!q.empty())
    {
        long long size = q.size();
        // vector<long long> row;
        stack<long long> s;
        for (long long i = 0; i < size; i++)
        {
            node *n = q.front();
            q.pop();
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
            if (rightToleft)
            {
                s.push(n->data);
            }
            else
                cout << n->data << " ";
            // row.push_back(n->data);
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            // row.push_back(s.top());
            s.pop();
        }
        rightToleft = !rightToleft;
        // ans.push_back(row);
    }
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
    cout << "Level order Traversal: ";
    ZigZagTraversal(root);
    // vector<vector<long long>> ans = ZigZagTraversal(root);
    // for (long long i = 0; i < ans.size(); i++)
    // {
    //     for (long long j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    // }
    cout << "\n";
    return 0;
}
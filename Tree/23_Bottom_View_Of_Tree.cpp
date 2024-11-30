// Bottom View Of Tree
// Order from left to right, element lowest in vertical order are only included.
// Right elements are prioritized over left if they have same vertical and horizontal priority.
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Bottom View Of Tree: 1 2 12 13 14 22

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

// vector<long long> BottomView(node *root)
void BottomView(node *root)
{
    // vector<long long> ans;
    if (root == NULL)
        return;
    // return ans;
    map<long long, long long> m;
    queue<pair<node *, long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        node *curr = tmp.first;
        long long x = tmp.second;
        m[x] = curr->data;
        if (curr->left)
        {
            q.push({curr->left, x - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, x + 1});
        }
    }
    for (auto i : m)
    {
        cout << i.second << " ";
        // ans.push_back(i.second);
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
    cout << "Bottom View of Tree: ";
    BottomView(root);
    // vector<long long> ans = BottomView(root);
    // for (long long i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << "\n";
    return 0;
}
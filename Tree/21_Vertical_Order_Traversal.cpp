// Vertical traversal
// Order from top to bottom and left to right.
// If multiple elements at same level both horizontally and vertically, take smaller element first.
// Create map for each row column 
//            10
//        /        \
//      5           15
//    /   \       /    \
//   2     6    13      22
//  /          /  \
// 1          12   14

// Vertical order Traversal: 1 2 5 12 10 6 13 15 14 22

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

// vector<vector<long long>> VerticalOrderTraversal(node *root)
void VerticalOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    // return ans;
    map<long long, map<long long, multiset<long long>>> m;
    queue<pair<node *, pair<long long, long long>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        node *curr = tmp.first;
        long long x = tmp.second.first, y = tmp.second.second;
        m[x][y].insert(curr->data);
        if (curr->left)
        {
            q.push({curr->left, {x - 1, y + 1}});
        }
        if (curr->right)
        {
            q.push({curr->right, {x + 1, y + 1}});
        }
    }
    // vector<vector<long long>> ans;
    for (auto i : m)
    {
        // vector<long long> col;
        for (auto curr : i.second)
        {
            // col.insert(col.end(), curr.second.begin(), curr.second.end());
            for (auto data : curr.second)    
                cout << data << " ";
        }
        // ans.push_back(col);
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
    cout << "Vertical Order Traversal: ";
    VerticalOrderTraversal(root);
    // vector<vector<long long>> ans = VerticalOrderTraversal(root);
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
// Right View Of Tree
// Right view of a Binary Tree is set of nodes visible when tree is visited from Right side. root than traversal to right then left
//            10            0
//        /        \
//      5           15      1
//    /   \       /    \
//   2     6    13      22  2
//             /  \
//            12   14       3

// Right View Of Tree: 10 15 22 14

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
// void rightTraversal(node *root, long long level, vector<long long>& ans)
void rightTraversal(node *root, long long level, long long& max_level)
{
    if (root == NULL)
        return;
    // if(level>ans.size())
    if (level > max_level)
    {
        // ans.push_back(root->data);
        cout << root->data << " ";
        max_level = level;
    }
    // rightTraversal(root->right, level + 1, ans);
    // rightTraversal(root->left, level + 1, ans);
    rightTraversal(root->right, level + 1, max_level);
    rightTraversal(root->left, level + 1, max_level);
}

// vector<long long> RightView(node *root)
void RightView(node *root)
{
    vector<long long> ans;
    if (root == NULL)
        return;
        // return ans;
    long long max_level=0;
    // rightTraversal(root,1,ans);
    rightTraversal(root, 1, max_level);
    // return ans;
}

int main()
{
    struct node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->left->left = new node(12);
    root->right->left->right = new node(14);
    root->right->right = new node(22);
    cout << "Right View of Tree: ";
    RightView(root);
    // vector<long long> ans = RightView(root);
    // for (long long i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << "\n";
    return 0;
}
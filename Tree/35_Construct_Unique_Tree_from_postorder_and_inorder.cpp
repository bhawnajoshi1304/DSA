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
struct node {
    long long data;
    struct node *left;
    struct node *right;
    node(long long data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};
void traversal(node *root) {
    stack<pair<node *, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return;
    while (!s.empty()) {
        auto it = s.top();
        s.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->left != NULL)
                s.push({it.first->left, 1});
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second += 1;
            s.push(it);
            if (it.first->right != NULL)
                s.push({it.first->right, 1});
        }
        else
            post.push_back(it.first->data);
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
node *buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &imap) {
    if (postStart > postEnd || inStart > inEnd)
        return NULL;
    int inRoot = imap[postorder[postEnd]];// postOrder ends with root
    int numsLeft = inRoot - inStart; // number of left nodes
    node *root = new node(postorder[postEnd]);
    root->left = buildTree(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, imap);
    root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, imap);
    return root;
}
node *buildTree(vector<int> &postorder, vector<int> &inorder) {
    map<int, int> imap;
    for (int i = 0; i < inorder.size(); i += 1)
        imap[inorder[i]] = i;
    return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, imap);
}
int main() {
    vector<int> postorder = {1, 2, 6, 5, 12, 14, 13, 22, 15, 10};
    vector<int> inorder = {1, 2, 5, 6, 10, 12, 13, 14, 15, 22};
    traversal(buildTree(postorder, inorder));
    return 0;
}
